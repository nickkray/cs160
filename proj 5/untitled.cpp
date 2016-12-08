#include <cassert>
#include <typeinfo>

#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"

#define mpr(...) fprintf(m_outputfile,__VA_ARGS__)


class Codegen : public Visitor
{
  private:
    FILE* m_outputfile;
    SymTab *m_st;

    // Basic size of a word (integers and booleans) in bytes
    static const int wordsize = 4;

    int label_count; // Access with new_label
    
    
     static const int fFBefore = 2*wordsize;

    // Helpers
    // This is used to get new unique labels (cleverly names label1, label2, ...)
    int new_label()
    {
        return label_count++;
    }

    void set_text_mode()
    {
        fprintf(m_outputfile, ".text\n\n");
    }

    void set_data_mode()
    {
        fprintf(m_outputfile, ".data\n\n");
    }

    // PART 1:
    // 1) get arithmetic expressions on integers working:
    //  you wont really be able to run your code,
    //  but you can visually inspect it to see that the correct
    //  chains of opcodes are being generated.
    // 2) get procedure calls working:
    //  if you want to see at least a very simple program compile
    //  and link successfully against gcc-produced code, you
    //  need to get at least this far
    // 3) get boolean operation working
    //  before we can implement any of the conditional control flow
    //  stuff, we need to have booleans worked out.
    // 4) control flow:
    //  we need a way to have if-elses and while loops in our language.
    // 5) arrays: just like variables, but with an index

    // Hint: the symbol table has been augmented to track an offset
    //  with all of the symbols.  That offset can be used to figure
    //  out where in the activation record you should look for a particuar
    //  variable


    ///////////////////////////////////////////////////////////////////////////////
    //
    //  function_prologue
    //  function_epilogue
    //
    //  Together these two functions implement the callee-side of the calling
    //  convention.  A stack frame has the following layout:
    //
    //                         <- SP (before pre-call / after epilogue)
    //  high -----------------
    //       | actual arg 1  |
    //       |    ...        |
    //       | actual arg n  |
    //       -----------------
    //       |  Return Addr  |
    //       =================
    //       | temporary 1   | <- SP (when starting prologue)
    //       |    ...        |
    //       | temporary n   |
    //   low ----------------- <- SP (when done prologue)
    //
    //
    //              ||
    //              ||
    //             \  /
    //              \/
    //
    //
    //  The caller is responsible for placing the actual arguments
    //  and the return address on the stack. Actually, the return address
    //  is put automatically on the stack as part of the x86 call instruction.
    //
    //  On function entry, the callee
    //
    //  (1) allocates space for the callee's temporaries on the stack
    //
    //  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%ebp)
    //
    //  (3) makes the activation record pointer (frmae pointer - %ebp) point to the start of the temporary region
    //
    //  (4) possibly copies the actual arguments into the temporary variables to allow easier access
    //
    //  On function exit, the callee:
    //
    //  (1) pops the callee's activation record (temporay area) off the stack
    //
    //  (2) restores the callee-saved registers, including the activation record of the caller (%ebp)
    //
    //  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the
    //      return address off the stack
    //
    //////////////////////////////////////////////////////////////////////////////
    //
    // Since we are interfacing with code produced by GCC, we have to respect the
    // calling convention that GCC demands:
    //
    // Contract between caller and callee on x86:
    //    * after call instruction:
    //           o %eip points at first instruction of function
    //           o %esp+4 points at first argument
    //           o %esp points at return address
    //    * after ret instruction:
    //           o %eip contains return address
    //           o %esp points at arguments pushed by caller
    //           o called function may have trashed arguments
    //           o %eax contains return value (or trash if function is void)
    //           o %ecx, %edx may be trashed
    //           o %ebp, %ebx, %esi, %edi must contain contents from time of call
    //    * Terminology:
    //           o %eax, %ecx, %edx are "caller save" registers
    //           o %ebp, %ebx, %esi, %edi are "callee save" registers
    ////////////////////////////////////////////////////////////////////////////////


    void emit_prologue(ProcImpl* p)
    {
        
        mpr("#### function %s\n",p->m_symname->spelling());


        int size_locals = m_st->scopesize(p->m_procedure_block->m_attribute.m_scope);
        mpr("#### size locals is %i\n",size_locals);
        if(strcmp("Main",p->m_symname->spelling())==0){
            mpr("_Main:\n");
        }
        mpr("%s:\n",p->m_symname->spelling());


        
        mpr("    push %%ebp\n");    //save base ptr
        mpr("    mov %%esp, %%ebp\n");  //set new base ptr
        mpr("    sub $%i, %%esp\n",size_locals);




                int num_args = p->m_decl_list->size();
                if(num_args>0){
                                mpr("// Copy function args to local space. Saved regs + return addr take up %d space before %%ebp\n",fFBefore);
                                int offset = 8;
                                while(num_args>0){
                                    
                                    mpr("// Copying arg to local: offset %d\n",offset);
                                    mpr("    pushl %d(%%ebp)\n",offset);
                                    
                                    num_args--;
                                    // stackSpace+=wordsize;
                                    offset+=wordsize;
                                }
                                mpr("// Done copying function args\n");
                            }



    }

    void emit_epilogue(ProcImpl* p)
    {
        int size_locals = m_st->scopesize(p->m_procedure_block->m_attribute.m_scope);
        //mpr("#### stackspace is %i\n",stackSpace);
        mpr("    add $%i, %%esp\n",size_locals);

        if(strcmp("Main",p->m_symname->spelling())==0){
            mpr("    leave\n");
        }else{
            mpr("    pop %%ebp\n");
        }

        mpr("    ret\n");
    }

  // WRITEME: more functions to emit code

  public:

    Codegen(FILE* outputfile, SymTab* st)
    {
        m_outputfile = outputfile;
        m_st = st;
        label_count = 0;
    }

    void visitProgramImpl(ProgramImpl* p)
    {

//        DEST_LOCATION = STACK;
        mpr(".globl _Main\n");
        mpr(".globl Main\n");
        // WRITEME
        p->visit_children(this);

    }

    void visitProcImpl(ProcImpl* p)
    {
        
            emit_prologue(p);
//        tprint("// There are %d bytes after ebp used for storing caller regs\n",fFAfter);
        p->visit_children(this);
        emit_epilogue(p);
        
    }

    void visitProcedure_blockImpl(Procedure_blockImpl* p)
    {
        p->visit_children(this);
    }

    void visitNested_blockImpl(Nested_blockImpl* p)
    {
    }

    void visitAssignment(Assignment* p)
    {
        p->visit_children(this);
        fprintf( m_outputfile, "#### ASSIGN\n");
    }

    void visitCall(Call* p)
    {

         std::list<Expr_ptr>::reverse_iterator iter = p->m_expr_list->rbegin();
         for(; iter != p->m_expr_list->rend(); ++iter){
             (*iter)->accept(this);
//             fprintf(m_outputfile, "pushl $%d\n", (*iter)->m_attribute.m_lattice_elem.value);
         }
       
        char *name = strdup(p -> m_symname -> spelling());
        fprintf( m_outputfile, "#### CALLING %s\n",name);
        //call func
        fprintf(m_outputfile, "call %s\n", name);

        mpr("push %%eax\n");    //get return
/*
         Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
         if(s==NULL){
             mpr("### symbol not found\n");
        }else{
        int offset=4+s->get_offset();
    
        mpr("mov %%eax, -%d(%%ebp)\n", offset); //puts eax in the var slot
        }

*/

        p->visit_children(this);
    }

    void visitReturn(Return* p)
    {
        p->visit_children(this);
        fprintf( m_outputfile, "#### RETURN\n");
        fprintf( m_outputfile, "popl %%eax\n");
    }

    // Control flow
    void visitIfNoElse(IfNoElse* p)
    {
    }

    void visitIfWithElse(IfWithElse* p)
    {
    }

    void visitWhileLoop(WhileLoop* p)
    {
    }

    void visitCodeBlock(CodeBlock *p) 
    {
    }

    // Variable declarations (no code generation needed)
    void visitDeclImpl(DeclImpl* p)
    {
        p -> visit_children(this);
    }

    void visitTInteger(TInteger* p)
    {
    }

    void visitTIntPtr(TIntPtr* p)
    {
    }

    void visitTBoolean(TBoolean* p)
    {
    }

    void visitTCharacter(TCharacter* p)
    {
    }

    void visitTCharPtr(TCharPtr* p)
    {
    }

    void visitTString(TString* p)
    {
    }

    // Comparison operations
    void visitCompare(Compare* p)
    {
    }

    void visitNoteq(Noteq* p)
    {
    }

    void visitGt(Gt* p)
    {
    }

    void visitGteq(Gteq* p)
    {
    }

    void visitLt(Lt* p)
    {
    }

    void visitLteq(Lteq* p)
    {
    }

    // Arithmetic and logic operations
    void visitAnd(And* p)
    {

        fprintf(m_outputfile, "# And\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  andl %%ecx, %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //And\n");

    }

    void visitOr(Or* p)
    {
    }

    void visitMinus(Minus* p)
    {

         fprintf(m_outputfile, "# Minus\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  subl %%ecx, %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //Minus\n");

    }

    void visitPlus(Plus *p) {
        fprintf(m_outputfile, "# Plus\n");
        p->visit_children(this);
        fprintf(m_outputfile, "  popl %%ecx\n");
        fprintf(m_outputfile, "  popl %%eax\n");
        fprintf(m_outputfile, "  addl %%ecx, %%eax\n");
        fprintf(m_outputfile, "  pushl %%eax\n");
        fprintf(m_outputfile, "# //Plus\n");
        
        p->m_attribute.m_basetype=bt_integer;
    }

    void visitTimes(Times* p)
    {
        fprintf(m_outputfile, "# Times\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  imull %%ecx, %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //Times\n");

    }

    void visitDiv(Div* p)
    {

        fprintf(m_outputfile, "# Divide\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  cdq\n");
    fprintf(m_outputfile, "  idivl %%ecx\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //Divide\n");

    }

    void visitNot(Not* p)
    {
    }

    void visitUminus(Uminus* p)
    {

        fprintf(m_outputfile, "# UnaryMinus\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  negl %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //UnaryMinus\n");
    
    }

    // Variable and constant access
    void visitIdent(Ident* p)
    { 
        p -> visit_children(this);
        mpr("### getting IDENT (retrieving val for) %s\n", p->m_symname->spelling());
        Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
        int offset=4+s->get_offset();
        mpr("pushl -%d(%%ebp)\n",offset);
    }

    void visitBoolLit(BoolLit* p)
    {
    }

    void visitCharLit(CharLit* p)
    {
    }

    void visitIntLit(IntLit* p)
    {
        p->visit_children(this);
        fprintf(m_outputfile, "  pushl $%d #Int\n", p->m_primitive->m_data);
    }

    void visitNullLit(NullLit* p)
    {
    }

    void visitArrayAccess(ArrayAccess* p)
    {
    }

    // LHS
    void visitVariable(Variable* p)
    {
        
        mpr("### assigning var %s\n", p->m_symname->spelling());
        p->visit_children(this);

        Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
         if(s==NULL){
             mpr("### symbol not found\n");
        }else{
        int offset=4+s->get_offset();
    
        mpr("popl %%eax\n");            //pops the stack and puts it in eax
        mpr("mov %%eax, -%d(%%ebp)\n", offset); //puts eax in the var slot
        }
    }

    void visitDerefVariable(DerefVariable* p)
    {
    }

    void visitArrayElement(ArrayElement* p)
    {
    }

    // Special cases
    void visitSymName(SymName* p)
    {
    }

    void visitPrimitive(Primitive* p)
    {
    }

    // Strings
    void visitStringAssignment(StringAssignment* p)
    {
    }

    void visitStringPrimitive(StringPrimitive* p)
    {
    }

    void visitAbsoluteValue(AbsoluteValue* p)
    {
    }

    // Pointer
    void visitAddressOf(AddressOf* p)
    {
    }

    void visitDeref(Deref* p)
    {
    }
};


void dopass_codegen(Program_ptr ast, SymTab* st)
{
    Codegen* codegen = new Codegen(stdout, st);
    ast->accept(codegen);
    delete codegen;
}
