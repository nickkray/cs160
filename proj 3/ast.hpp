#ifndef AST_HEADER
#define AST_HEADER

//Automatically Generated C++ Abstract Syntax Tree Interface

#include <list>
#include "attribute.hpp"


/********** Forward Declarations **********/

class ProgramImpl;
class Program;
class ProcImpl;
class Proc;
class Procedure_blockImpl;
class Procedure_block;
class Nested_blockImpl;
class Nested_block;
class DeclImpl;
class Decl;
class Assignment;
class Stat;
class StringAssignment;
class Call;
class IfNoElse;
class IfWithElse;
class WhileLoop;
class CodeBlock;
class Return;
class Return_stat;
class TInteger;
class Type;
class TCharacter;
class TBoolean;
class TCharPtr;
class TIntPtr;
class TString;
class AbsoluteValue;
class Expr;
class AddressOf;
class And;
class Div;
class Compare;
class Gt;
class Gteq;
class Lt;
class Lteq;
class Minus;
class Noteq;
class Or;
class Plus;
class Times;
class Not;
class Uminus;
class Ident;
class ArrayAccess;
class IntLit;
class CharLit;
class BoolLit;
class Deref;
class Variable;
class Lhs;
class DerefVariable;
class ArrayElement;
class SymName;
class Primitive;
class StringPrimitive;


/********** Pointer Typedefs **********/

typedef Program* Program_ptr;

typedef Proc* Proc_ptr;
typedef Decl* Decl_ptr;
typedef Stat* Stat_ptr;
typedef SymName* SymName_ptr;
typedef Expr* Expr_ptr;


/********** Union Type (from parse) **********/

#ifdef YYSTYPE_IS_TRIVIAL
#error Make sure to include this file _before_ parser.hpp
#endif
typedef union
{
std::list<Proc_ptr>* u_proc_list;
Program* u_program;
std::list<Decl_ptr>* u_decl_list;
Proc* u_proc;
std::list<Stat_ptr>* u_stat_list;
Procedure_block* u_procedure_block;
Nested_block* u_nested_block;
std::list<SymName_ptr>* u_symname_list;
Decl* u_decl;
Stat* u_stat;
std::list<Expr_ptr>* u_expr_list;
Return_stat* u_return_stat;
Type* u_type;
Expr* u_expr;
Lhs* u_lhs;
SymName* u_symname;
Primitive* u_primitive;
StringPrimitive* u_stringprimitive;

// a couple of hardcoded types
char* u_base_charptr;
int u_base_int;
} classunion_stype;
#define YYSTYPE classunion_stype

/********** Visitor Interfaces **********/

class Visitor{
 public:
  virtual ~Visitor() {}
virtual void visitProgramImpl(ProgramImpl *p) = 0;
virtual void visitProcImpl(ProcImpl *p) = 0;
virtual void visitProcedure_blockImpl(Procedure_blockImpl *p) = 0;
virtual void visitNested_blockImpl(Nested_blockImpl *p) = 0;
virtual void visitDeclImpl(DeclImpl *p) = 0;
virtual void visitAssignment(Assignment *p) = 0;
virtual void visitStringAssignment(StringAssignment *p) = 0;
virtual void visitCall(Call *p) = 0;
virtual void visitIfNoElse(IfNoElse *p) = 0;
virtual void visitIfWithElse(IfWithElse *p) = 0;
virtual void visitWhileLoop(WhileLoop *p) = 0;
virtual void visitCodeBlock(CodeBlock *p) = 0;
virtual void visitReturn(Return *p) = 0;
virtual void visitTInteger(TInteger *p) = 0;
virtual void visitTCharacter(TCharacter *p) = 0;
virtual void visitTBoolean(TBoolean *p) = 0;
virtual void visitTCharPtr(TCharPtr *p) = 0;
virtual void visitTIntPtr(TIntPtr *p) = 0;
virtual void visitTString(TString *p) = 0;
virtual void visitAbsoluteValue(AbsoluteValue *p) = 0;
virtual void visitAddressOf(AddressOf *p) = 0;
virtual void visitAnd(And *p) = 0;
virtual void visitDiv(Div *p) = 0;
virtual void visitCompare(Compare *p) = 0;
virtual void visitGt(Gt *p) = 0;
virtual void visitGteq(Gteq *p) = 0;
virtual void visitLt(Lt *p) = 0;
virtual void visitLteq(Lteq *p) = 0;
virtual void visitMinus(Minus *p) = 0;
virtual void visitNoteq(Noteq *p) = 0;
virtual void visitOr(Or *p) = 0;
virtual void visitPlus(Plus *p) = 0;
virtual void visitTimes(Times *p) = 0;
virtual void visitNot(Not *p) = 0;
virtual void visitUminus(Uminus *p) = 0;
virtual void visitIdent(Ident *p) = 0;
virtual void visitArrayAccess(ArrayAccess *p) = 0;
virtual void visitIntLit(IntLit *p) = 0;
virtual void visitCharLit(CharLit *p) = 0;
virtual void visitBoolLit(BoolLit *p) = 0;
virtual void visitDeref(Deref *p) = 0;
virtual void visitVariable(Variable *p) = 0;
virtual void visitDerefVariable(DerefVariable *p) = 0;
virtual void visitArrayElement(ArrayElement *p) = 0;
virtual void visitSymName(SymName *p) = 0;
virtual void visitPrimitive(Primitive *p) = 0;
virtual void visitStringPrimitive(StringPrimitive *p) = 0;

};

class Visitable
{
 public:
  virtual ~Visitable() {}
  virtual void visit_children(Visitor *v) = 0;
  virtual void accept(Visitor *v) = 0;
};


/********** Abstract Syntax Classes **********/

class Program : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Program *clone() const = 0;
};

class Proc : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Proc *clone() const = 0;
};

class Procedure_block : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Procedure_block *clone() const = 0;
};

class Nested_block : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Nested_block *clone() const = 0;
};

class Decl : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Decl *clone() const = 0;
};

class Stat : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Stat *clone() const = 0;
};

class Return_stat : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Return_stat *clone() const = 0;
};

class Type : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Type *clone() const = 0;
};

class Expr : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Expr *clone() const = 0;
};

class Lhs : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Lhs *clone() const = 0;
};


// Program ==> *Proc
class ProgramImpl : public Program
{
  public:
  std::list<Proc_ptr> *m_proc_list;

  ProgramImpl(const ProgramImpl &);
  ProgramImpl &operator=(const ProgramImpl &);
  ProgramImpl(std::list<Proc_ptr> *p1);
  ~ProgramImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ProgramImpl  *clone() const;
  void swap(ProgramImpl &);
};

// Proc ==>  SymName *Decl Type Procedure_block
class ProcImpl : public Proc
{
  public:
  SymName *m_symname;
  std::list<Decl_ptr> *m_decl_list;
  Type *m_type;
  Procedure_block *m_procedure_block;

  ProcImpl(const ProcImpl &);
  ProcImpl &operator=(const ProcImpl &);
  ProcImpl(SymName *p1, std::list<Decl_ptr> *p2, Type *p3, Procedure_block *p4);
  ~ProcImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ProcImpl  *clone() const;
  void swap(ProcImpl &);
};

// Procedure_block ==> *Proc *Decl *Stat Return_stat
class Procedure_blockImpl : public Procedure_block
{
  public:
  std::list<Proc_ptr> *m_proc_list;
  std::list<Decl_ptr> *m_decl_list;
  std::list<Stat_ptr> *m_stat_list;
  Return_stat *m_return_stat;

  Procedure_blockImpl(const Procedure_blockImpl &);
  Procedure_blockImpl &operator=(const Procedure_blockImpl &);
  Procedure_blockImpl(std::list<Proc_ptr> *p1, std::list<Decl_ptr> *p2, std::list<Stat_ptr> *p3, Return_stat *p4);
  ~Procedure_blockImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Procedure_blockImpl  *clone() const;
  void swap(Procedure_blockImpl &);
};

// Nested_block ==> *Decl *Stat
class Nested_blockImpl : public Nested_block
{
  public:
  std::list<Decl_ptr> *m_decl_list;
  std::list<Stat_ptr> *m_stat_list;

  Nested_blockImpl(const Nested_blockImpl &);
  Nested_blockImpl &operator=(const Nested_blockImpl &);
  Nested_blockImpl(std::list<Decl_ptr> *p1, std::list<Stat_ptr> *p2);
  ~Nested_blockImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Nested_blockImpl  *clone() const;
  void swap(Nested_blockImpl &);
};

// Decl ==> *SymName Type
class DeclImpl : public Decl
{
  public:
  std::list<SymName_ptr> *m_symname_list;
  Type *m_type;

  DeclImpl(const DeclImpl &);
  DeclImpl &operator=(const DeclImpl &);
  DeclImpl(std::list<SymName_ptr> *p1, Type *p2);
  ~DeclImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  DeclImpl  *clone() const;
  void swap(DeclImpl &);
};

// Stat:Assignment ==> Lhs Expr
class Assignment : public Stat
{
  public:
  Lhs *m_lhs;
  Expr *m_expr;

  Assignment(const Assignment &);
  Assignment &operator=(const Assignment &);
  Assignment(Lhs *p1, Expr *p2);
  ~Assignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Assignment  *clone() const;
  void swap(Assignment &);
};

// Stat:StringAssignment ==> Lhs StringPrimitive
class StringAssignment : public Stat
{
  public:
  Lhs *m_lhs;
  StringPrimitive *m_stringprimitive;

  StringAssignment(const StringAssignment &);
  StringAssignment &operator=(const StringAssignment &);
  StringAssignment(Lhs *p1, StringPrimitive *p2);
  ~StringAssignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  StringAssignment  *clone() const;
  void swap(StringAssignment &);
};

// Stat:Call ==> Lhs SymName *Expr
class Call : public Stat
{
  public:
  Lhs *m_lhs;
  SymName *m_symname;
  std::list<Expr_ptr> *m_expr_list;

  Call(const Call &);
  Call &operator=(const Call &);
  Call(Lhs *p1, SymName *p2, std::list<Expr_ptr> *p3);
  ~Call();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Call  *clone() const;
  void swap(Call &);
};

// Stat:IfNoElse ==> Expr Nested_block
class IfNoElse : public Stat
{
  public:
  Expr *m_expr;
  Nested_block *m_nested_block;

  IfNoElse(const IfNoElse &);
  IfNoElse &operator=(const IfNoElse &);
  IfNoElse(Expr *p1, Nested_block *p2);
  ~IfNoElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IfNoElse  *clone() const;
  void swap(IfNoElse &);
};

// Stat:IfWithElse ==> Expr Nested_block Nested_block
class IfWithElse : public Stat
{
  public:
  Expr *m_expr;
  Nested_block *m_nested_block_1;
  Nested_block *m_nested_block_2;

  IfWithElse(const IfWithElse &);
  IfWithElse &operator=(const IfWithElse &);
  IfWithElse(Expr *p1, Nested_block *p2, Nested_block *p3);
  ~IfWithElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IfWithElse  *clone() const;
  void swap(IfWithElse &);
};

// Stat:WhileLoop ==>  Expr Nested_block
class WhileLoop : public Stat
{
  public:
  Expr *m_expr;
  Nested_block *m_nested_block;

  WhileLoop(const WhileLoop &);
  WhileLoop &operator=(const WhileLoop &);
  WhileLoop(Expr *p1, Nested_block *p2);
  ~WhileLoop();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  WhileLoop  *clone() const;
  void swap(WhileLoop &);
};

// Stat:CodeBlock ==>  Nested_block
class CodeBlock : public Stat
{
  public:
  Nested_block *m_nested_block;

  CodeBlock(const CodeBlock &);
  CodeBlock &operator=(const CodeBlock &);
  CodeBlock(Nested_block *p1);
  ~CodeBlock();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  CodeBlock  *clone() const;
  void swap(CodeBlock &);
};

// Return_stat:Return ==> Expr
class Return : public Return_stat
{
  public:
  Expr *m_expr;

  Return(const Return &);
  Return &operator=(const Return &);
  Return(Expr *p1);
  ~Return();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Return  *clone() const;
  void swap(Return &);
};

// Type:TInteger ==>
class TInteger : public Type
{
  public:

  TInteger(const TInteger &);
  TInteger &operator=(const TInteger &);
  TInteger();
  ~TInteger();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TInteger  *clone() const;
  void swap(TInteger &);
};

// Type:TCharacter ==>
class TCharacter : public Type
{
  public:

  TCharacter(const TCharacter &);
  TCharacter &operator=(const TCharacter &);
  TCharacter();
  ~TCharacter();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TCharacter  *clone() const;
  void swap(TCharacter &);
};

// Type:TBoolean ==>
class TBoolean : public Type
{
  public:

  TBoolean(const TBoolean &);
  TBoolean &operator=(const TBoolean &);
  TBoolean();
  ~TBoolean();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TBoolean  *clone() const;
  void swap(TBoolean &);
};

// Type:TCharPtr ==>
class TCharPtr : public Type
{
  public:

  TCharPtr(const TCharPtr &);
  TCharPtr &operator=(const TCharPtr &);
  TCharPtr();
  ~TCharPtr();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TCharPtr  *clone() const;
  void swap(TCharPtr &);
};

// Type:TIntPtr ==>
class TIntPtr : public Type
{
  public:

  TIntPtr(const TIntPtr &);
  TIntPtr &operator=(const TIntPtr &);
  TIntPtr();
  ~TIntPtr();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TIntPtr  *clone() const;
  void swap(TIntPtr &);
};

// Type:TString ==> Primitive
class TString : public Type
{
  public:
  Primitive *m_primitive;

  TString(const TString &);
  TString &operator=(const TString &);
  TString(Primitive *p1);
  ~TString();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TString  *clone() const;
  void swap(TString &);
};

// Expr:AbsoluteValue ==> Expr
class AbsoluteValue : public Expr
{
  public:
  Expr *m_expr;

  AbsoluteValue(const AbsoluteValue &);
  AbsoluteValue &operator=(const AbsoluteValue &);
  AbsoluteValue(Expr *p1);
  ~AbsoluteValue();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  AbsoluteValue  *clone() const;
  void swap(AbsoluteValue &);
};

// Expr:AddressOf ==> Lhs
class AddressOf : public Expr
{
  public:
  Lhs *m_lhs;

  AddressOf(const AddressOf &);
  AddressOf &operator=(const AddressOf &);
  AddressOf(Lhs *p1);
  ~AddressOf();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  AddressOf  *clone() const;
  void swap(AddressOf &);
};

// Expr:And ==> Expr Expr
class And : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  And(const And &);
  And &operator=(const And &);
  And(Expr *p1, Expr *p2);
  ~And();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  And  *clone() const;
  void swap(And &);
};

// Expr:Div ==> Expr Expr
class Div : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Div(const Div &);
  Div &operator=(const Div &);
  Div(Expr *p1, Expr *p2);
  ~Div();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Div  *clone() const;
  void swap(Div &);
};

// Expr:Compare ==> Expr Expr
class Compare : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Compare(const Compare &);
  Compare &operator=(const Compare &);
  Compare(Expr *p1, Expr *p2);
  ~Compare();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Compare  *clone() const;
  void swap(Compare &);
};

// Expr:Gt ==> Expr Expr
class Gt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gt(const Gt &);
  Gt &operator=(const Gt &);
  Gt(Expr *p1, Expr *p2);
  ~Gt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Gt  *clone() const;
  void swap(Gt &);
};

// Expr:Gteq ==> Expr Expr
class Gteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gteq(const Gteq &);
  Gteq &operator=(const Gteq &);
  Gteq(Expr *p1, Expr *p2);
  ~Gteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Gteq  *clone() const;
  void swap(Gteq &);
};

// Expr:Lt ==> Expr Expr
class Lt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lt(const Lt &);
  Lt &operator=(const Lt &);
  Lt(Expr *p1, Expr *p2);
  ~Lt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Lt  *clone() const;
  void swap(Lt &);
};

// Expr:Lteq ==> Expr Expr
class Lteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lteq(const Lteq &);
  Lteq &operator=(const Lteq &);
  Lteq(Expr *p1, Expr *p2);
  ~Lteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Lteq  *clone() const;
  void swap(Lteq &);
};

// Expr:Minus ==> Expr Expr
class Minus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Minus(const Minus &);
  Minus &operator=(const Minus &);
  Minus(Expr *p1, Expr *p2);
  ~Minus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Minus  *clone() const;
  void swap(Minus &);
};

// Expr:Noteq ==> Expr Expr
class Noteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Noteq(const Noteq &);
  Noteq &operator=(const Noteq &);
  Noteq(Expr *p1, Expr *p2);
  ~Noteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Noteq  *clone() const;
  void swap(Noteq &);
};

// Expr:Or ==> Expr Expr
class Or : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Or(const Or &);
  Or &operator=(const Or &);
  Or(Expr *p1, Expr *p2);
  ~Or();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Or  *clone() const;
  void swap(Or &);
};

// Expr:Plus ==> Expr Expr
class Plus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Plus(const Plus &);
  Plus &operator=(const Plus &);
  Plus(Expr *p1, Expr *p2);
  ~Plus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Plus  *clone() const;
  void swap(Plus &);
};

// Expr:Times ==> Expr Expr
class Times : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Times(const Times &);
  Times &operator=(const Times &);
  Times(Expr *p1, Expr *p2);
  ~Times();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Times  *clone() const;
  void swap(Times &);
};

// Expr:Not ==> Expr
class Not : public Expr
{
  public:
  Expr *m_expr;

  Not(const Not &);
  Not &operator=(const Not &);
  Not(Expr *p1);
  ~Not();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Not  *clone() const;
  void swap(Not &);
};

// Expr:Uminus ==> Expr
class Uminus : public Expr
{
  public:
  Expr *m_expr;

  Uminus(const Uminus &);
  Uminus &operator=(const Uminus &);
  Uminus(Expr *p1);
  ~Uminus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Uminus  *clone() const;
  void swap(Uminus &);
};

// Expr:Ident ==> SymName
class Ident : public Expr
{
  public:
  SymName *m_symname;

  Ident(const Ident &);
  Ident &operator=(const Ident &);
  Ident(SymName *p1);
  ~Ident();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Ident  *clone() const;
  void swap(Ident &);
};

// Expr:ArrayAccess ==> SymName Expr
class ArrayAccess : public Expr
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  ArrayAccess(const ArrayAccess &);
  ArrayAccess &operator=(const ArrayAccess &);
  ArrayAccess(SymName *p1, Expr *p2);
  ~ArrayAccess();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ArrayAccess  *clone() const;
  void swap(ArrayAccess &);
};

// Expr:IntLit ==> Primitive
class IntLit : public Expr
{
  public:
  Primitive *m_primitive;

  IntLit(const IntLit &);
  IntLit &operator=(const IntLit &);
  IntLit(Primitive *p1);
  ~IntLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IntLit  *clone() const;
  void swap(IntLit &);
};

// Expr:CharLit ==> Primitive
class CharLit : public Expr
{
  public:
  Primitive *m_primitive;

  CharLit(const CharLit &);
  CharLit &operator=(const CharLit &);
  CharLit(Primitive *p1);
  ~CharLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  CharLit  *clone() const;
  void swap(CharLit &);
};

// Expr:BoolLit ==> Primitive
class BoolLit : public Expr
{
  public:
  Primitive *m_primitive;

  BoolLit(const BoolLit &);
  BoolLit &operator=(const BoolLit &);
  BoolLit(Primitive *p1);
  ~BoolLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  BoolLit  *clone() const;
  void swap(BoolLit &);
};

// Expr:Deref ==> Expr
class Deref : public Expr
{
  public:
  Expr *m_expr;

  Deref(const Deref &);
  Deref &operator=(const Deref &);
  Deref(Expr *p1);
  ~Deref();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Deref  *clone() const;
  void swap(Deref &);
};

// Lhs:Variable ==> SymName
class Variable : public Lhs
{
  public:
  SymName *m_symname;

  Variable(const Variable &);
  Variable &operator=(const Variable &);
  Variable(SymName *p1);
  ~Variable();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Variable  *clone() const;
  void swap(Variable &);
};

// Lhs:DerefVariable ==> SymName
class DerefVariable : public Lhs
{
  public:
  SymName *m_symname;

  DerefVariable(const DerefVariable &);
  DerefVariable &operator=(const DerefVariable &);
  DerefVariable(SymName *p1);
  ~DerefVariable();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  DerefVariable  *clone() const;
  void swap(DerefVariable &);
};

// Lhs:ArrayElement ==> SymName Expr
class ArrayElement : public Lhs
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  ArrayElement(const ArrayElement &);
  ArrayElement &operator=(const ArrayElement &);
  ArrayElement(SymName *p1, Expr *p2);
  ~ArrayElement();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ArrayElement  *clone() const;
  void swap(ArrayElement &);
};




#endif //AST_HEADER

