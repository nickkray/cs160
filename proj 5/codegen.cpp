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

        Symbol *s = m_st->lookup(p->m_symname->spelling());
  int num_args = s->m_arg_type.size();

                mpr("           #### number of args for this func is %i\n", num_args);
                

                if(num_args>0){
                                mpr("// Copy function args to local space. Saved regs + return addr take up %d space before %%ebp\n",fFBefore);
                                int offset = 8;
                                while(num_args>0){
                                    
                                    mpr("// Copying arg to local vars %d\n",offset);
                                    mpr("    mov %d(%%ebp), %%eax\n",offset);
                                    mpr("    mov %%eax, -%d(%%ebp)\n",offset-4);
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
            mpr("pop %%ebp\n");
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
        p->visit_children(this);
    }

    void visitAssignment(Assignment* p)
    {
        
        fprintf( m_outputfile, "#### ASSIGN\n");
        p->m_expr->accept(this);
        if(dynamic_cast<const AddressOf*>(p->m_expr) != 0){
            mpr("movl %%ecx, %%eax ### fixin this deref\n");
        }
        p->m_lhs->accept(this);
        if(dynamic_cast<const ArrayElement*>(p->m_lhs) != 0){
            mpr("           ### It seems like lhs is an array elemnt?\n");
            mpr("movl %%eax, (%%ecx)\n");
            mpr("popl %%eax ### we don't need what's on the stack\n");
        }
        if(dynamic_cast<const Variable*>(p->m_lhs) != 0 && p->m_lhs->m_attribute.m_basetype!=bt_string){
            mpr("### back to assigner to fix for call to var\n");
            mpr("movl %%eax, (%%ecx)\n");
        }
        if(dynamic_cast<const DerefVariable*>(p->m_lhs) != 0){
            mpr("### back to assigner to fix for call to deref\n");
            mpr("movl %%eax, (%%ecx)\n");
        }
    }

    void visitCall(Call* p)
    {

         std::list<Expr_ptr>::reverse_iterator iter = p->m_expr_list->rbegin();
         for(; iter != p->m_expr_list->rend(); ++iter){
             (*iter)->accept(this);
//             fprintf(m_outputfile, "pushl $%d\n", (*iter)->m_attribute.m_lattice_elem.);
         }
       
        char *name = strdup(p -> m_symname -> spelling());
        fprintf( m_outputfile, "#### CALLING %s\n",name);
        //call func
        fprintf(m_outputfile, "call %s\n", name);

iter = p->m_expr_list->rbegin();
         for(; iter != p->m_expr_list->rend(); ++iter){
             mpr("popl %%ecx\n");    //get return
//             fprintf(m_outputfile, "pushl $%d\n", (*iter)->m_attribute.m_lattice_elem.);
         }


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
        p->m_lhs->accept(this);
        //p->visit_children(this);
        mpr("movl %%eax, (%%ecx)\n");
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

         fprintf( m_outputfile, "#### IFNOELSE\n");
      
      int label=new_label();
      p->m_expr->accept(this);
      fprintf( m_outputfile, "#### Expression checked above\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "movl $0, %%ebx\n");
      fprintf( m_outputfile, "cmp %%eax, %%ebx\n");
      fprintf( m_outputfile, "je skip_if_%i\n",label);
      p->m_nested_block->accept(this);
      fprintf( m_outputfile, "skip_if_%i:\n",label);
    }

    void visitIfWithElse(IfWithElse* p)
    {

         fprintf( m_outputfile, "#### IF WITH ELSE\n");

      int label=new_label();
      int donelabel=new_label();
      p ->m_expr->accept(this);
      fprintf( m_outputfile, "#### IFWITHELSE\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "movl $0, %%ebx\n");
      fprintf( m_outputfile, "cmp %%eax, %%ebx\n");
      fprintf( m_outputfile, "je skip_if_%i\n",label);
      p->m_nested_block_1->accept(this);
      mpr("    jmp IfWithElseDone%d\n",donelabel);
      fprintf( m_outputfile, "skip_if_%i:\n",label);
      p->m_nested_block_2->accept(this);
        fprintf( m_outputfile, "IfWithElseDone%i:",donelabel);
    }

    void visitWhileLoop(WhileLoop* p)
    {
fprintf( m_outputfile, "#### WHILE LOOP\n");

    int label=new_label();
    fprintf( m_outputfile, "jmp compare_expr%i\n",label);
    fprintf( m_outputfile, "func_body%i:\n",label);
    p->m_nested_block->accept(this);
    fprintf( m_outputfile, "compare_expr%i:\n",label);
    p->m_expr->accept(this);
    fprintf( m_outputfile, "pop %%ebx\n");
    fprintf( m_outputfile, "mov $1, %%eax\n");
    fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
    fprintf( m_outputfile, "je func_body%i\n",label);
    
     fprintf( m_outputfile, "#### END WHILE LOOP\n");

    }

    void visitCodeBlock(CodeBlock *p) 
    {
        p -> visit_children(this);
    }

    // Variable declarations (no code generation needed)
    void visitDeclImpl(DeclImpl* p)
    {
        p -> visit_children(this);
    }

    void visitTInteger(TInteger* p)
    {
        p -> visit_children(this);
    }

    void visitTIntPtr(TIntPtr* p)
    {
        p -> visit_children(this);
    }

    void visitTBoolean(TBoolean* p)
    {
        p -> visit_children(this);
    }

    void visitTCharacter(TCharacter* p)
    {
        p -> visit_children(this);
    }

    void visitTCharPtr(TCharPtr* p)
    {
        p -> visit_children(this);
    }

    void visitTString(TString* p)
    {
        p -> visit_children(this);
    }

    // Comparison operations
    void visitCompare(Compare* p)
    {

         fprintf( m_outputfile, "######## Compare ==\n");
    // WRITEME
//     int label=new_label();
//      if (p -> m_attribute.m_lattice_elem != TOP) {
//          fprintf( m_outputfile, " pushl $%d\n", p->m_attribute.m_lattice_elem.value);
//          return;
//      }
    int lbl=new_label();
      p -> visit_children(this);
      fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      fprintf(m_outputfile, "je equal%d\n", lbl);
      
      fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);


    }

    void visitNoteq(Noteq* p)
    {
        mpr("### visiting noteq");
         p -> visit_children(this);
      fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      int lbl=new_label();
      fprintf(m_outputfile, "jne equal%d\n", lbl);
      
    fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);


    }

    void visitGt(Gt* p)
    {

        p -> visit_children(this);
      int lbl=new_label();
       fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      fprintf(m_outputfile, "jg equal%d\n", lbl);
      
     fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);


    }

    void visitGteq(Gteq* p)
    {

             p -> visit_children(this);
   int lbl=new_label();
    fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      fprintf(m_outputfile, "jge equal%d\n", lbl);
      
      fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);

    }

    void visitLt(Lt* p)
    {

          p -> visit_children(this);
      int lbl=new_label();
       fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      fprintf(m_outputfile, "jl equal%d\n", lbl);
      
     fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);


    }

    void visitLteq(Lteq* p)
    {

             p -> visit_children(this);
 int lbl=new_label();
      fprintf( m_outputfile, "popl %%ebx\n");
      fprintf( m_outputfile, "popl %%eax\n");
      fprintf( m_outputfile, "cmp %%ebx,%%eax\n");
      fprintf(m_outputfile, "jle equal%d\n", lbl);
      
     fprintf(m_outputfile, "pushl $0\n");
      fprintf(m_outputfile, "jmp end%d\n", lbl);
      
      fprintf(m_outputfile, "equal%d:\n", lbl);
      fprintf(m_outputfile, "pushl $1\n");
      
      fprintf(m_outputfile, "end%d:\n", lbl);


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

    fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " orl %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");

    }

    void visitMinus(Minus* p)
    {
if(p->m_expr_1->m_attribute.m_basetype==bt_integer){
         fprintf(m_outputfile, "# Minus\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    fprintf(m_outputfile, "  subl %%ecx, %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //Minus\n");
}else{
    fprintf(m_outputfile, "# Minus for pointers\n");
    p->visit_children(this);
    fprintf(m_outputfile, "  popl %%ecx\n");
    fprintf(m_outputfile, "  popl %%eax\n");
    mpr("imul $-4, %%ecx ###mult by -4\n");
    fprintf(m_outputfile, "  subl %%ecx, %%eax\n");
    fprintf(m_outputfile, "  pushl %%eax\n");
    fprintf(m_outputfile, "# //Minus\n");
}

    }

    void visitPlus(Plus *p) {
        if(p->m_expr_1->m_attribute.m_basetype==bt_integer){
            fprintf(m_outputfile, "# Plus\n");
            p->visit_children(this);
            fprintf(m_outputfile, "  popl %%ecx\n");
            fprintf(m_outputfile, "  popl %%eax\n");
            fprintf(m_outputfile, "  addl %%ecx, %%eax\n");
            fprintf(m_outputfile, "  pushl %%eax\n");
            fprintf(m_outputfile, "# //Plus\n");
            
            p->m_attribute.m_basetype=bt_integer;

        }else{
            fprintf(m_outputfile, "# Plus for pointers\n");
            p->visit_children(this);
            fprintf(m_outputfile, "  popl %%ecx\n");
            fprintf(m_outputfile, "  popl %%eax\n");
            mpr("imul $-4, %%ecx ###mult by -4\n");
            fprintf(m_outputfile, "  addl %%ecx, %%eax\n");
            fprintf(m_outputfile, "  pushl %%eax\n");
            
            p->m_attribute.m_basetype=bt_intptr;
        }
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

                  p -> visit_children(this);

          fprintf( m_outputfile, " popl %%eax\n");
          fprintf( m_outputfile, " not  %%eax\n");
          fprintf( m_outputfile, " pushl %%eax\n");

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
        // mpr("### the type is %i", s->m_attribute.m_basetype);
        if(s->m_basetype == bt_string){
            if(p->m_parent_attribute->m_basetype == bt_integer){
            mpr("### found string - assuming you want len\n");
            mpr("pushl $%i\n", s->getStringLen());
            }else{
                       mpr("### popping string memory into stack\n");
                    int offset=4+s->get_offset();
                    for(int i=0;i<s->getStringLen();i++){
                        mpr("mov -%d(%%ebp), %%eax\n", offset+i*4);
                        mpr("pushl %%eax\n"); 
                    }
            }
        }else{
        mpr("pushl -%d(%%ebp)\n",offset);
        }
    }

    void visitBoolLit(BoolLit* p)
    {

          fprintf( m_outputfile, "#### Visit BOOLLit\n");
    fprintf( m_outputfile, "pushl $%d\n", p -> m_primitive->m_data);

    }

    void visitCharLit(CharLit* p)
    {

          fprintf( m_outputfile, "#### Visit Charlit\n");
    fprintf( m_outputfile, "pushl $%d\n", p -> m_primitive->m_data);

    }

    void visitIntLit(IntLit* p)
    {
        mpr("### found int literal\n");
        p->visit_children(this);
        fprintf(m_outputfile, "  pushl $%d #Int\n", p->m_primitive->m_data);
    }

    void visitNullLit(NullLit* p)
    {
        p->visit_children(this);
        mpr("### found null literal\n");
        mpr("mov 0 eax\n");
    }

    void visitArrayAccess(ArrayAccess* p)
    {
        Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
        p->m_expr->accept(this);
        mpr("### performing an array access\n");
        mpr("popl %%ecx ### storing our offset\n");
        //mpr("mov %%eax, %%ecx ### storing our offset\n");
        mpr("imul $-4, %%ecx ###mult by -4\n");
        int offset=4+s->get_offset();
        mpr("sub $%d, %%ecx ### add to real memory addr\n", offset);
        mpr("movl (%%ecx, %%ebp), %%eax\n");
    //    mpr("movl %%ecx, %%eax\n");
        mpr("pushl %%eax\n");

    }

    // LHS
    void visitVariable(Variable* p)
    {
        
        mpr("### var lhs called for %s\n", p->m_symname->spelling());
        p->visit_children(this);

        Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
         if(s==NULL){
             mpr("### symbol not found\n");
        }else{

                if(s->m_basetype != bt_string){
                int offset=4+s->get_offset();
             mpr("### providing memory address for lhs assign\n");
                    mpr("popl %%eax\n");            //pops the stack and puts it in eax
               //     mpr("mov %%eax, -%d(%%ebp)\n", offset); //puts eax in the var slot
                    mpr("mov $%d, %%ecx\n", -offset);
                    mpr("add %%ebp, %%ecx\n", -offset);

                }else{
                    mpr("### popping string stack into memory\n");
                    int offset=4+s->get_offset() + 4*s->getStringLen()-4;
                    for(int i=0;i<s->getStringLen();i++){
                        mpr("popl %%eax\n"); 
                        mpr("mov %%eax, -%d(%%ebp)\n", offset-4*i);
                    }
                }

        }
    }

    void visitDerefVariable(DerefVariable* p)
    {
        mpr("### VISIT DEREF VAR\n");
        Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
        mpr("mov %%ebp, %%ecx ### storing our ebp\n");
        int offset=4+s->get_offset();
        mpr("sub $%d, %%ecx ### add to real memory addr\n", offset);
      //  mpr("pushl %%ecx ###putting the address here \n"); 
        mpr("popl %%eax\n");
        mpr("mov (%%ecx), %%ecx\n");
    }

    void visitArrayElement(ArrayElement* p)
    {
        //Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());

            Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
        p->m_expr->accept(this);
        mpr("### performing an array set\n");
        mpr("popl %%ecx ### storing our offset\n");
        // mpr("popl %%eax ### storing our expression\n");
        //mpr("mov %%eax, %%ecx ### storing our offset\n");
        mpr("imul $-4, %%ecx ###mult by -4\n");
        int offset=4+s->get_offset();
        mpr("sub $%d, %%ecx ### add to real memory addr\n", offset);
        mpr("add %%ebp, %%ecx ### add to ebp\n", offset);
        mpr("pushl %%ecx ###putting the address here in case we need it\n"); 
          // mpr("movl %%eax, (%%ecx, %%ebp)\n");
    //    mpr("movl %%ecx, %%eax\n");
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
       p->m_stringprimitive->accept(this);
        p->m_lhs->accept(this);
    }

    void visitStringPrimitive(StringPrimitive* p)
    {
        //mpr("### the string len is %i", p->getStringLen());
         for(int i = 0; p->m_string[i-1] != '\0'; i++) {
             printf("pushl $%i\n", p->m_string[i]);
         }
    }

    void visitAbsoluteValue(AbsoluteValue* p)
    {
        p->m_attribute.m_basetype = bt_integer;
        if(p->m_expr->m_attribute.m_basetype == bt_string){
            mpr("### string len\n");
            p -> visit_children(this);

        }else{
            p->visit_children(this);
            mpr("### int abs\n");
            mpr("popl %%eax\n");
            mpr("mov %%eax, %%ebx \n");
            mpr("not %%eax\n");
            mpr("cmovl %%ebx, %%eax\n");
            mpr("pushl %%eax\n");
        }

    }

    // Pointer
    void visitAddressOf(AddressOf* p)
    {
        p->visit_children(this);
        // Symbol *s=m_st->lookup(p->m_attribute.m_scope,p->m_symname->spelling());
        //  if(s==NULL){
        //      mpr("### symbol not found\n");
        // }else{
        // int offset=4+s->get_offset();
        // mpr("### address of\n");
        // mpr("mov %%ebp, %%eax\n");
        // mpr("sub $%i, %%eax\n", offset);
        // }
    }

    void visitDeref(Deref* p)
    {
            p->visit_children(this);
            mpr("### performing a deref off a var\n");
         
            mpr("popl %%eax\n");
            mpr("movl (%%eax), %%eax\n");
            mpr("pushl %%eax\n");
    }
};


void dopass_codegen(Program_ptr ast, SymTab* st)
{
    Codegen* codegen = new Codegen(stdout, st);
    ast->accept(codegen);
    delete codegen;
}
