#include <iostream>
#include <cstdio>
#include <cstring>

#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "assert.h"

// WRITEME: The default attribute propagation rule
#define default_rule(X)\ 
(X)->m_attribute.m_scope = m_st->get_scope();\
(X) -> visit_children(this);\

#include <typeinfo>

using namespace std;

class Typecheck : public Visitor
{
  private:
    FILE* m_errorfile;
    SymTab* m_st;

    // The set of recognized errors
    enum errortype
    {
        no_main,
        nonvoid_main,
        dup_proc_name,
        dup_var_name,
        proc_undef,
        call_type_mismatch,
        narg_mismatch,
        expr_type_err,
        var_undef,
        ifpred_err,
        whilepred_err,
        incompat_assign,
        who_knows,
        ret_type_mismatch,
        array_index_error,
        no_array_var,
        arg_type_mismatch,
        expr_pointer_arithmetic_err,
        expr_abs_error,
        expr_addressof_error,
        invalid_deref
    };

    // Print the error to file and exit
    void t_error(errortype e, Attribute a)
    {
        fprintf(m_errorfile,"on line number %d, ", a.lineno);

        switch(e)
        {
            case no_main:
                fprintf(m_errorfile, "error: no main\n");
                exit(2);
            case nonvoid_main:
                fprintf(m_errorfile, "error: the Main procedure has arguments\n");
                exit(3);
            case dup_proc_name:
                fprintf(m_errorfile, "error: duplicate procedure names in same scope\n");
                exit(4);
            case dup_var_name:
                fprintf(m_errorfile, "error: duplicate variable names in same scope\n");
                exit(5);
            case proc_undef:
                fprintf(m_errorfile, "error: call to undefined procedure\n");
                exit(6);
            case var_undef:
                fprintf(m_errorfile, "error: undefined variable\n");
                exit(7);
            case narg_mismatch:
                fprintf(m_errorfile, "error: procedure call has different number of args than declartion\n");
                exit(8);
            case arg_type_mismatch:
                fprintf(m_errorfile, "error: argument type mismatch\n");
                exit(9);
            case ret_type_mismatch:
                fprintf(m_errorfile, "error: type mismatch in return statement\n");
                exit(10);
            case call_type_mismatch:
                fprintf(m_errorfile, "error: type mismatch in procedure call args\n");
                exit(11);
            case ifpred_err:
                fprintf(m_errorfile, "error: predicate of if statement is not boolean\n");
                exit(12);
            case whilepred_err:
                fprintf(m_errorfile, "error: predicate of while statement is not boolean\n");
                exit(13);
            case array_index_error:
                fprintf(m_errorfile, "error: array index not integer\n");
                exit(14);
            case no_array_var:
                fprintf(m_errorfile, "error: attempt to index non-array variable\n");
                exit(15);
            case incompat_assign:
                fprintf(m_errorfile, "error: type of expr and var do not match in assignment\n");
                exit(16);
            case expr_type_err:
                fprintf(m_errorfile, "error: incompatible types used in expression\n");
                exit(17);
            case expr_abs_error:
                fprintf(m_errorfile, "error: absolute value can only be applied to integers and strings\n");
                exit(17);
            case expr_pointer_arithmetic_err:
                fprintf(m_errorfile, "error: invalid pointer arithmetic\n");
                exit(18);
            case expr_addressof_error:
                fprintf(m_errorfile, "error: AddressOf can only be applied to integers, chars, and indexed strings\n");
                exit(19);
            case invalid_deref:
                fprintf(m_errorfile, "error: Deref can only be applied to integer pointers and char pointers\n");
                exit(20);
            default:
                fprintf(m_errorfile, "error: no good reason\n");
                exit(21);
        }
    }

    // Helpers
    // WRITEME: You might want write some hepler functions.

    // Type Checking
    // WRITEME: You need to implement type-checking for this project

    // Check that there is one and only one main
    void check_for_one_main(ProgramImpl* p)
    {
        Symbol *s = m_st -> lookup("Main");
        if(s == NULL)
            this -> t_error(no_main, p -> m_attribute);
        // ASSERT There are no args for it
        if(s -> m_arg_type.size() > 0)
            this -> t_error(nonvoid_main,  p -> m_attribute);
        
    }

    // Create a symbol for the procedure and check there is none already
    // existing
    void add_proc_symbol(ProcImpl* p)
    {
        Symbol *s;
        Symbol *arg;
        s = new Symbol();
        s->m_basetype = bt_procedure;
        p->m_type->accept(this);


        m_st->open_scope();


         std::list<Decl_ptr>::iterator m_decl_list_iter;
            for(m_decl_list_iter = p->m_decl_list->begin();
              m_decl_list_iter != p->m_decl_list->end();
              ++m_decl_list_iter){
                (*m_decl_list_iter)->accept(this);
            }

        m_st->close_scope();   


        s-> m_return_type = p -> m_type -> m_attribute.m_basetype;


        list<Decl_ptr>::iterator iter;        
        for(iter = p->m_decl_list -> begin(); iter != p->m_decl_list -> end(); ++iter){
            s->m_arg_type.push_back((**iter).m_attribute.m_basetype);
            cout << "adding this "<< (**iter).m_attribute.m_basetype <<endl;
        }
        
        if(!m_st->insert(strdup(p->m_symname->spelling()), s))
            this->t_error(dup_proc_name, p->m_attribute);

        m_st->open_scope();

        default_rule(p);
        m_st->close_scope();   
    }

    // Add symbol table information for all the declarations following
    void add_decl_symbol(DeclImpl* p)
    {
        //cout << "\n\nadding decl list\n";
        list<SymName_ptr>::iterator iter;
        char* name;
        Symbol *s;
        
        for(iter = p->m_symname_list -> begin(); iter != p->m_symname_list -> end(); ++iter){
            name = strdup((*iter)->spelling());
            //cout << "adding "<<name << endl;
            s = new Symbol();
            s->m_basetype = p->m_type->m_attribute.m_basetype;


      //      if(s->m_basetype == bt_string)
       //         s->m_string_size = p->m_type->m_primitive->m_data;
            
            if(!m_st->insert(name, s))
                this->t_error(dup_var_name, p->m_attribute);
        }
    }

    // Check that the return statement of a procedure has the appropriate type
    void check_proc(ProcImpl *p)
    {
        if(p -> m_type -> m_attribute.m_basetype  != p -> m_procedure_block -> m_attribute.m_basetype)
            this->t_error(ret_type_mismatch, p->m_attribute);
    }   

    // Check that the declared return type is not an array
    void check_return(Return *p)
    {
        default_rule(p);
        if(p->m_attribute.m_basetype == bt_string)
            this->t_error(ret_type_mismatch, p->m_attribute);
    }

    void check_call(Call *p)
    {
        default_rule(p);
        Symbol *s = m_st->lookup(p->m_symname->spelling());
        if(s == NULL || s->m_basetype != bt_procedure)       //function doesnt exist
            this->t_error(proc_undef, p->m_attribute);
        if(p->m_lhs->m_attribute.m_basetype != s->m_return_type)    //incompat assign
            this->t_error(incompat_assign, p->m_attribute);

        if(p->m_expr_list->size() != s->m_arg_type.size())
            this->t_error(narg_mismatch, p->m_attribute);            

        std::vector<Basetype>::iterator iter2 = s->m_arg_type.end();
        --iter2;
        for(auto iter = p->m_expr_list -> begin(); iter != p->m_expr_list -> end(); ++iter){   
            //cout << "comparing call "<<*iter2<< " with "<< (**iter).m_attribute.m_basetype<< endl;
            if(*iter2!=(**iter).m_attribute.m_basetype)
                this->t_error(arg_type_mismatch, p->m_attribute);
            --iter2;
        }
    }

    // For checking that this expressions type is boolean used in if/else
    void check_pred_if(Expr* p)
    {
        default_rule(p);
        if(p->m_attribute.m_basetype != bt_boolean)
            this-> t_error(ifpred_err, p->m_attribute);
    }

    // For checking that this expressions type is boolean used in while
    void check_pred_while(Expr* p)
    {
        
        if(p->m_attribute.m_basetype != bt_boolean)
            this-> t_error(whilepred_err, p->m_attribute);
    }

    void check_assignment(Assignment* p)    //check that types match
    {
        //cout << "checking assignment ";
        default_rule(p);
        //can also assign null to any pointer
        //cout << "performing assignment lhs: " <<  p->m_lhs->m_attribute.m_basetype << " with rhs: " << p->m_expr->m_attribute.m_basetype << endl;
        if( !((p -> m_expr -> m_attribute.m_basetype == p->m_lhs->m_attribute.m_basetype) || (p -> m_expr -> m_attribute.m_basetype == bt_ptr && (p->m_lhs->m_attribute.m_basetype == bt_charptr || p->m_lhs->m_attribute.m_basetype == bt_intptr))))
            this-> t_error(incompat_assign, p->m_attribute);
    }

    void check_string_assignment(StringAssignment* p)
    {
        default_rule(p);
        if(p->m_lhs->m_attribute.m_basetype != bt_string)
            this->t_error(incompat_assign, p->m_attribute);
    }

    void check_array_access(ArrayAccess* p)
    {
        default_rule(p);
        Symbol *s = m_st->lookup(p->m_symname->spelling());
        if(s == NULL)       //var doesnt exit
            this->t_error(proc_undef, p->m_attribute);
        if(p->m_expr->m_attribute.m_basetype != bt_integer)
            this->t_error(array_index_error, p->m_attribute);
    }

    void check_array_element(ArrayElement* p)
    {
        default_rule(p);
        Symbol *s = m_st->lookup(p->m_symname->spelling());
        if(s == NULL)       //var doesnt exit
            this->t_error(proc_undef, p->m_attribute);
        if(s->m_basetype != bt_string)
            this->t_error(no_array_var, p->m_attribute);
        if(p->m_expr->m_attribute.m_basetype != bt_integer)
            this->t_error(array_index_error, p->m_attribute);
        p->m_attribute.m_basetype = bt_char;
    }

    // For checking boolean operations(and, or ...)
    void checkset_boolexpr(Expr* parent, Expr* child1, Expr* child2)
    {
        default_rule(parent);
         if(     child1->m_attribute.m_basetype != bt_char 
             || child2->m_attribute.m_basetype != bt_char )
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_boolean;
    }

    // For checking arithmetic expressions(plus, times, ...)
    void checkset_arithexpr(Expr* parent, Expr* child1, Expr* child2)
    {
        default_rule(parent);
        if(child1->m_attribute.m_basetype == bt_intptr || child2->m_attribute.m_basetype == bt_intptr || child1->m_attribute.m_basetype == bt_charptr || child2->m_attribute.m_basetype == bt_charptr)  //no int ptr arithmetic
            this->t_error(expr_pointer_arithmetic_err, parent->m_attribute);
         if(     child1->m_attribute.m_basetype != bt_integer 
             || child2->m_attribute.m_basetype != bt_integer )
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_integer;
    }

    // Called by plus and minus: in these cases we allow pointer arithmetics
    void checkset_arithexpr_or_pointer(Expr* parent, Expr* child1, Expr* child2)
    {
        default_rule(parent);
        /*
        if(!((child1->m_attribute.m_basetype == bt_integer && child2->m_attribute.m_basetype == bt_integer) || (child1->m_attribute.m_basetype == bt_intptr && child2->m_attribute.m_basetype == bt_integer) || (child2->m_attribute.m_basetype == bt_integer && child1->m_attribute.m_basetype == bt_charptr)))
            this->t_error(expr_pointer_arithmetic_err, parent->m_attribute);
            */
        if(child1->m_attribute.m_basetype == bt_intptr || child2->m_attribute.m_basetype == bt_intptr)  //no int ptr arithmetic
            this->t_error(expr_pointer_arithmetic_err, parent->m_attribute);
        if(child1->m_attribute.m_basetype == bt_charptr && child2->m_attribute.m_basetype == bt_charptr)    //can't be 2 char ptrs
            this->t_error(expr_pointer_arithmetic_err, parent->m_attribute);
        if(child1->m_attribute.m_basetype == bt_integer && child2->m_attribute.m_basetype == bt_charptr)// can't do int+charptr
            this->t_error(expr_pointer_arithmetic_err, parent->m_attribute);
        if(child1->m_attribute.m_basetype == bt_integer && child2->m_attribute.m_basetype == bt_integer)
            parent->m_attribute.m_basetype=bt_integer;
        if(child1->m_attribute.m_basetype == bt_charptr && child2->m_attribute.m_basetype == bt_integer)
            parent->m_attribute.m_basetype=bt_charptr;

    }

    // For checking relational(less than , greater than, ...)
    void checkset_relationalexpr(Expr* parent, Expr* child1, Expr* child2)
    {
        default_rule(parent);
         if(     child1->m_attribute.m_basetype != bt_integer 
             || child2->m_attribute.m_basetype != bt_integer )
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_boolean;
    }

    // For checking equality ops(equal, not equal)
    void checkset_equalityexpr(Expr* parent, Expr* child1, Expr* child2)
    {
        default_rule(parent);
        if(child1->m_attribute.m_basetype!=child2->m_attribute.m_basetype || child1->m_attribute.m_basetype == bt_string)
                  this->t_error(expr_type_err, parent->m_attribute);
        parent->m_attribute.m_basetype=bt_boolean;
    }

    // For checking not
    void checkset_not(Expr* parent, Expr* child)
    {
        default_rule(parent);
         if(child->m_attribute.m_basetype != bt_boolean)
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_boolean;
    }

    // For checking unary minus
    void checkset_uminus(Expr* parent, Expr* child)
    {
        default_rule(parent);
         if(child->m_attribute.m_basetype != bt_integer)
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_integer;
    }

    void checkset_absolute_value(Expr* parent, Expr* child)
    {
        default_rule(parent);
         if(child->m_attribute.m_basetype != bt_integer && child->m_attribute.m_basetype != bt_string)
            this->t_error(expr_type_err, parent->m_attribute);
       parent->m_attribute.m_basetype=bt_integer;
    }

    void checkset_addressof(Expr* parent, Lhs* child)
    {
        default_rule(parent);
        if(!(child->m_attribute.m_basetype== bt_integer || child->m_attribute.m_basetype== bt_char))
            this -> t_error(expr_addressof_error, parent -> m_attribute);
        if(child->m_attribute.m_basetype== bt_char)
            parent->m_attribute.m_basetype=bt_charptr;
        if(child->m_attribute.m_basetype== bt_integer)
            parent->m_attribute.m_basetype=bt_intptr;
    }

    void checkset_deref_expr(Deref* parent,Expr* child)
    {
        //cout << "checking deref expr"<<endl;
        default_rule(parent);
        if(!(child->m_attribute.m_basetype== bt_intptr || child->m_attribute.m_basetype== bt_charptr))
            this -> t_error(invalid_deref, parent -> m_attribute);
        if(child->m_attribute.m_basetype== bt_intptr)
            parent->m_attribute.m_basetype = bt_integer;
        if(child->m_attribute.m_basetype== bt_charptr)
            parent->m_attribute.m_basetype = bt_char;
        if(child->m_attribute.m_basetype== bt_string)
            parent->m_attribute.m_basetype = bt_charptr;
    }   

    /*
if(!((s->m_attribute.m_basetype== bt_intptr && child->m_attribute.m_basetype == bt_integer)||(s->m_attribute.m_basetype== bt_charptr && child->m_attribute.m_basetype == bt_character)))
            this -> t_error(expr_type_err, p -> m_attribute);

    */

    // Check that if the right-hand side is an lhs, such as in case of
    // addressof
    void checkset_deref_lhs(DerefVariable* p)
    {
        default_rule(p);
        Symbol* s = m_st -> lookup(p->m_symname->spelling());
        //cout << "symbol lookup"<<endl;
        if(s == NULL)  //defined
            this -> t_error(var_undef, p -> m_attribute);
        if(!(s->m_basetype== bt_intptr || s->m_basetype== bt_charptr)) //address of is a pointer
            this -> t_error(invalid_deref, p -> m_attribute);   //address matches type
        if(s->m_basetype == bt_intptr)
            p->m_attribute.m_basetype = bt_integer;
        if(s->m_basetype == bt_charptr)
            p->m_attribute.m_basetype = bt_char;
    }

    void checkset_variable(Variable* p)
    {
        Symbol* assign = m_st -> lookup(p->m_symname->spelling());
        if (assign == NULL)
            this -> t_error(var_undef, p -> m_attribute);
        p->m_attribute.m_basetype = assign->m_basetype;
    }


  public:

    Typecheck(FILE* errorfile, SymTab* st) {
        m_errorfile = errorfile;
        m_st = st;
    }

    void visitProgramImpl(ProgramImpl* p)
    {
        default_rule(p);
        check_for_one_main(p);
    }

    void visitProcImpl(ProcImpl* p)
    {

        /*
Symbol *s;
s = new Symbol();
        s->m_basetype = bt_procedure;
        if(!m_st->insert(strdup(p->m_symname->spelling()), s))
            this->t_error(dup_proc_name, p->m_attribute);

        p->m_type->accept(this);
        s-> m_return_type = p -> m_type -> m_attribute.m_basetype;
//        cout << "what is the type pre("<< p->m_symname->spelling() <<"): "<< p -> m_type -> m_attribute.m_basetype << endl;

        m_st->open_scope();
        default_rule(p);
        m_st->close_scope(); 

      //  cout << "what is the type post("<< p->m_symname->spelling() <<"): "<< p -> m_type -> m_attribute.m_basetype << endl;



//add_proc_symbol(p);        
        check_proc(p);
        */

        add_proc_symbol(p);
       
        check_proc(p);

    }

    void visitCall(Call* p)
    {
        default_rule(p);
        check_call(p);
    }

    void visitNested_blockImpl(Nested_blockImpl* p)
    {
        m_st->open_scope();
        default_rule(p);  
        m_st->close_scope(); 
    }

    void visitProcedure_blockImpl(Procedure_blockImpl* p)
    {
        //m_st->open_scope();   since nested block is called already
        //cout << "\nvisiting proc_blockImpl\n";
        default_rule(p);
        //cout << "\nsetting our return to the right type"<<p->m_return_stat->m_attribute.m_basetype<<"\n";
        p->m_attribute.m_basetype = p->m_return_stat->m_attribute.m_basetype;
        //m_st->close_scope(); 
    }

    void visitDeclImpl(DeclImpl* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = p->m_type->m_attribute.m_basetype;
        add_decl_symbol(p);
    }

    void visitAssignment(Assignment* p)
    {
        check_assignment(p);
    }

    void visitStringAssignment(StringAssignment *p)
    {
        check_string_assignment(p);
    }

    void visitIdent(Ident* p)
    {
        default_rule(p);
        Symbol* ident = m_st -> lookup(p -> m_symname -> spelling());
        if (ident == NULL)
            this -> t_error(var_undef, p -> m_attribute);
        p->m_attribute.m_basetype=ident->m_basetype;
    }

    void visitReturn(Return* p)
    {
        check_return(p);
        p->m_attribute.m_basetype = p->m_expr->m_attribute.m_basetype;
    }

    void visitIfNoElse(IfNoElse* p)
    {
        default_rule(p);
        check_pred_if(p->m_expr);
    }

    void visitIfWithElse(IfWithElse* p)
    {
        default_rule(p);
        check_pred_if(p->m_expr);
    }

    void visitWhileLoop(WhileLoop* p)
    {
        default_rule(p);
        check_pred_while(p->m_expr);
    }

    void visitCodeBlock(CodeBlock *p) 
    {
        default_rule(p);
    }

    void visitTInteger(TInteger* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = bt_integer;
    }

    void visitTBoolean(TBoolean* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = bt_boolean;
    }

    void visitTCharacter(TCharacter* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = bt_char;
    }

    void visitTString(TString* p)
    {

        default_rule(p);
        p->m_attribute.m_basetype = bt_string;
        if(p->m_primitive->m_data<1){
            cout << "string length less than 1";
            exit(21);
        }
        //cout << "it's len is " << p->m_primitive->m_data<<endl;

    }

    void visitTCharPtr(TCharPtr* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = bt_charptr;
    }

    void visitTIntPtr(TIntPtr* p)
    {
        default_rule(p);
        p->m_attribute.m_basetype = bt_intptr;
    }

    void visitAnd(And* p)
    {
        checkset_boolexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitDiv(Div* p)
    {
        checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitCompare(Compare* p)
    {
        checkset_equalityexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitGt(Gt* p)
    {
        checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitGteq(Gteq* p)
    {
        checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitLt(Lt* p)
    {
        checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitLteq(Lteq* p)
    {
        checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitMinus(Minus* p)
    {
        checkset_arithexpr_or_pointer(p, p->m_expr_1, p->m_expr_2);
        //checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitNoteq(Noteq* p)
    {
        checkset_boolexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitOr(Or* p)
    {
        checkset_boolexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitPlus(Plus* p)
    {
        checkset_arithexpr_or_pointer(p, p->m_expr_1, p->m_expr_2);
        //checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitTimes(Times* p)
    {
        checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
    }

    void visitNot(Not* p)
    {
        checkset_not(p,p->m_expr);
    }

    void visitUminus(Uminus* p)
    {
        checkset_uminus(p,p->m_expr);
    }

    void visitArrayAccess(ArrayAccess* p)
    {
        check_array_access(p);
    }

    void visitIntLit(IntLit* p)
    {
        default_rule(p);
        p -> m_attribute.m_basetype = bt_integer;
    }

    void visitCharLit(CharLit* p)
    {
        default_rule(p);
        p -> m_attribute.m_basetype = bt_char;
    }

    void visitBoolLit(BoolLit* p)
    {
        default_rule(p);
        p -> m_attribute.m_basetype = bt_boolean;
    }

    void visitNullLit(NullLit* p)
    {
        default_rule(p);
        p -> m_attribute.m_basetype = bt_ptr;
    }

    void visitAbsoluteValue(AbsoluteValue* p)
    {
        checkset_absolute_value(p,p->m_expr);
    }

    void visitAddressOf(AddressOf* p)
    {
        checkset_addressof(p,p->m_lhs);
    }

    void visitVariable(Variable* p)
    {
        checkset_variable(p);
    }

    void visitDeref(Deref* p)
    {
        checkset_deref_expr(p,p->m_expr);
    }

    void visitDerefVariable(DerefVariable* p)
    {
        checkset_deref_lhs(p);
    }

    void visitArrayElement(ArrayElement* p)
    {
        check_array_element(p);
    }

    // Special cases
    void visitPrimitive(Primitive* p) {}
    void visitSymName(SymName* p) {}
    void visitStringPrimitive(StringPrimitive* p) {}
};


void dopass_typecheck(Program_ptr ast, SymTab* st)
{
    Typecheck* typecheck = new Typecheck(stderr, st);
    ast->accept(typecheck); // Walk the tree with the visitor above
    delete typecheck;
}
