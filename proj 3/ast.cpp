//Automatically Generated C++ Abstract Syntax Tree Class Hierarchy

#include <algorithm>
#include "ast.hpp"
extern int yylineno;
#include "symtab.hpp"
#include "primitive.hpp"
#include "primitive.hpp"



/********* ProgramImpl ************/
 ProgramImpl::ProgramImpl(std::list<Proc_ptr> *p1)  {
	m_proc_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		(*m_proc_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 ProgramImpl::ProgramImpl(const ProgramImpl & other) {
	m_proc_list = new std::list<Proc_ptr>;
	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = other.m_proc_list->begin();
	  m_proc_list_iter != other.m_proc_list->end();
	  ++m_proc_list_iter){
		m_proc_list->push_back( (*m_proc_list_iter)->clone() );
	}
 }
 ProgramImpl &ProgramImpl::operator=(const ProgramImpl & other) { ProgramImpl tmp(other); swap(tmp); return *this; }
 void ProgramImpl::swap(ProgramImpl & other) {
	std::swap(m_proc_list, other.m_proc_list);
 }
 ProgramImpl::~ProgramImpl() {
 	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		delete( *m_proc_list_iter );
	}
 }
 void ProgramImpl::visit_children( Visitor* v ) {
 	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		(*m_proc_list_iter)->accept( v );
	}
 }
 void ProgramImpl::accept(Visitor *v) { v->visitProgramImpl(this); }
 ProgramImpl *ProgramImpl::clone() const { return new ProgramImpl(*this); }
 
 
/********* ProcImpl ************/
 ProcImpl::ProcImpl(SymName *p1, std::list<Decl_ptr> *p2, Type *p3, Procedure_block *p4)  {
	m_symname = p1;
	m_decl_list = p2;
	m_type = p3;
	m_procedure_block = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_type->m_parent_attribute = &m_attribute;
 	m_procedure_block->m_parent_attribute = &m_attribute;
  }
 ProcImpl::ProcImpl(const ProcImpl & other) {
	m_symname = other.m_symname->clone();
	m_decl_list = new std::list<Decl_ptr>;
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_type = other.m_type->clone();
	m_procedure_block = other.m_procedure_block->clone();
 }
 ProcImpl &ProcImpl::operator=(const ProcImpl & other) { ProcImpl tmp(other); swap(tmp); return *this; }
 void ProcImpl::swap(ProcImpl & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_type, other.m_type);
	std::swap(m_procedure_block, other.m_procedure_block);
 }
 ProcImpl::~ProcImpl() {
 	delete(m_symname);
 	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	delete(m_type);
 	delete(m_procedure_block);
  }
 void ProcImpl::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
	m_type->accept( v );
 	m_procedure_block->accept( v );
  }
 void ProcImpl::accept(Visitor *v) { v->visitProcImpl(this); }
 ProcImpl *ProcImpl::clone() const { return new ProcImpl(*this); }
 
 
/********* Procedure_blockImpl ************/
 Procedure_blockImpl::Procedure_blockImpl(std::list<Proc_ptr> *p1, std::list<Decl_ptr> *p2, std::list<Stat_ptr> *p3, Return_stat *p4)  {
	m_proc_list = p1;
	m_decl_list = p2;
	m_stat_list = p3;
	m_return_stat = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		(*m_proc_list_iter)->m_parent_attribute = &m_attribute;
	}
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_return_stat->m_parent_attribute = &m_attribute;
  }
 Procedure_blockImpl::Procedure_blockImpl(const Procedure_blockImpl & other) {
	m_proc_list = new std::list<Proc_ptr>;
	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = other.m_proc_list->begin();
	  m_proc_list_iter != other.m_proc_list->end();
	  ++m_proc_list_iter){
		m_proc_list->push_back( (*m_proc_list_iter)->clone() );
	}
	m_decl_list = new std::list<Decl_ptr>;
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_stat_list = new std::list<Stat_ptr>;
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
	m_return_stat = other.m_return_stat->clone();
 }
 Procedure_blockImpl &Procedure_blockImpl::operator=(const Procedure_blockImpl & other) { Procedure_blockImpl tmp(other); swap(tmp); return *this; }
 void Procedure_blockImpl::swap(Procedure_blockImpl & other) {
	std::swap(m_proc_list, other.m_proc_list);
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_stat_list, other.m_stat_list);
	std::swap(m_return_stat, other.m_return_stat);
 }
 Procedure_blockImpl::~Procedure_blockImpl() {
 	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		delete( *m_proc_list_iter );
	}
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
	delete(m_return_stat);
  }
 void Procedure_blockImpl::visit_children( Visitor* v ) {
 	std::list<Proc_ptr>::iterator m_proc_list_iter;
	for(m_proc_list_iter = m_proc_list->begin();
	  m_proc_list_iter != m_proc_list->end();
	  ++m_proc_list_iter){
		(*m_proc_list_iter)->accept( v );
	}
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->accept( v );
	}
	m_return_stat->accept( v );
  }
 void Procedure_blockImpl::accept(Visitor *v) { v->visitProcedure_blockImpl(this); }
 Procedure_blockImpl *Procedure_blockImpl::clone() const { return new Procedure_blockImpl(*this); }
 
 
/********* Nested_blockImpl ************/
 Nested_blockImpl::Nested_blockImpl(std::list<Decl_ptr> *p1, std::list<Stat_ptr> *p2)  {
	m_decl_list = p1;
	m_stat_list = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Nested_blockImpl::Nested_blockImpl(const Nested_blockImpl & other) {
	m_decl_list = new std::list<Decl_ptr>;
	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_stat_list = new std::list<Stat_ptr>;
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
 }
 Nested_blockImpl &Nested_blockImpl::operator=(const Nested_blockImpl & other) { Nested_blockImpl tmp(other); swap(tmp); return *this; }
 void Nested_blockImpl::swap(Nested_blockImpl & other) {
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_stat_list, other.m_stat_list);
 }
 Nested_blockImpl::~Nested_blockImpl() {
 	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
 }
 void Nested_blockImpl::visit_children( Visitor* v ) {
 	std::list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
	std::list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->accept( v );
	}
 }
 void Nested_blockImpl::accept(Visitor *v) { v->visitNested_blockImpl(this); }
 Nested_blockImpl *Nested_blockImpl::clone() const { return new Nested_blockImpl(*this); }
 
 
/********* DeclImpl ************/
 DeclImpl::DeclImpl(std::list<SymName_ptr> *p1, Type *p2)  {
	m_symname_list = p1;
	m_type = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	std::list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_type->m_parent_attribute = &m_attribute;
  }
 DeclImpl::DeclImpl(const DeclImpl & other) {
	m_symname_list = new std::list<SymName_ptr>;
	std::list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = other.m_symname_list->begin();
	  m_symname_list_iter != other.m_symname_list->end();
	  ++m_symname_list_iter){
		m_symname_list->push_back( (*m_symname_list_iter)->clone() );
	}
	m_type = other.m_type->clone();
 }
 DeclImpl &DeclImpl::operator=(const DeclImpl & other) { DeclImpl tmp(other); swap(tmp); return *this; }
 void DeclImpl::swap(DeclImpl & other) {
	std::swap(m_symname_list, other.m_symname_list);
	std::swap(m_type, other.m_type);
 }
 DeclImpl::~DeclImpl() {
 	std::list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		delete( *m_symname_list_iter );
	}
	delete(m_type);
  }
 void DeclImpl::visit_children( Visitor* v ) {
 	std::list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->accept( v );
	}
	m_type->accept( v );
  }
 void DeclImpl::accept(Visitor *v) { v->visitDeclImpl(this); }
 DeclImpl *DeclImpl::clone() const { return new DeclImpl(*this); }
 
 
/********* Assignment ************/
 Assignment::Assignment(Lhs *p1, Expr *p2)  {
	m_lhs = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_lhs->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 Assignment::Assignment(const Assignment & other) {
	m_lhs = other.m_lhs->clone();
	m_expr = other.m_expr->clone();
 }
 Assignment &Assignment::operator=(const Assignment & other) { Assignment tmp(other); swap(tmp); return *this; }
 void Assignment::swap(Assignment & other) {
	std::swap(m_lhs, other.m_lhs);
	std::swap(m_expr, other.m_expr);
 }
 Assignment::~Assignment() {
 	delete(m_lhs);
 	delete(m_expr);
  }
 void Assignment::visit_children( Visitor* v ) {
 	m_lhs->accept( v );
 	m_expr->accept( v );
  }
 void Assignment::accept(Visitor *v) { v->visitAssignment(this); }
 Assignment *Assignment::clone() const { return new Assignment(*this); }
 
 
/********* StringAssignment ************/
 StringAssignment::StringAssignment(Lhs *p1, StringPrimitive *p2)  {
	m_lhs = p1;
	m_stringprimitive = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_lhs->m_parent_attribute = &m_attribute;
 	m_stringprimitive->m_parent_attribute = &m_attribute;
  }
 StringAssignment::StringAssignment(const StringAssignment & other) {
	m_lhs = other.m_lhs->clone();
	m_stringprimitive = other.m_stringprimitive->clone();
 }
 StringAssignment &StringAssignment::operator=(const StringAssignment & other) { StringAssignment tmp(other); swap(tmp); return *this; }
 void StringAssignment::swap(StringAssignment & other) {
	std::swap(m_lhs, other.m_lhs);
	std::swap(m_stringprimitive, other.m_stringprimitive);
 }
 StringAssignment::~StringAssignment() {
 	delete(m_lhs);
 	delete(m_stringprimitive);
  }
 void StringAssignment::visit_children( Visitor* v ) {
 	m_lhs->accept( v );
 	m_stringprimitive->accept( v );
  }
 void StringAssignment::accept(Visitor *v) { v->visitStringAssignment(this); }
 StringAssignment *StringAssignment::clone() const { return new StringAssignment(*this); }
 
 
/********* Call ************/
 Call::Call(Lhs *p1, SymName *p2, std::list<Expr_ptr> *p3)  {
	m_lhs = p1;
	m_symname = p2;
	m_expr_list = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_lhs->m_parent_attribute = &m_attribute;
 	m_symname->m_parent_attribute = &m_attribute;
 	std::list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Call::Call(const Call & other) {
	m_lhs = other.m_lhs->clone();
	m_symname = other.m_symname->clone();
	m_expr_list = new std::list<Expr_ptr>;
	std::list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = other.m_expr_list->begin();
	  m_expr_list_iter != other.m_expr_list->end();
	  ++m_expr_list_iter){
		m_expr_list->push_back( (*m_expr_list_iter)->clone() );
	}
 }
 Call &Call::operator=(const Call & other) { Call tmp(other); swap(tmp); return *this; }
 void Call::swap(Call & other) {
	std::swap(m_lhs, other.m_lhs);
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr_list, other.m_expr_list);
 }
 Call::~Call() {
 	delete(m_lhs);
 	delete(m_symname);
 	std::list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		delete( *m_expr_list_iter );
	}
 }
 void Call::visit_children( Visitor* v ) {
 	m_lhs->accept( v );
 	m_symname->accept( v );
 	std::list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->accept( v );
	}
 }
 void Call::accept(Visitor *v) { v->visitCall(this); }
 Call *Call::clone() const { return new Call(*this); }
 
 
/********* IfNoElse ************/
 IfNoElse::IfNoElse(Expr *p1, Nested_block *p2)  {
	m_expr = p1;
	m_nested_block = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 IfNoElse::IfNoElse(const IfNoElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 IfNoElse &IfNoElse::operator=(const IfNoElse & other) { IfNoElse tmp(other); swap(tmp); return *this; }
 void IfNoElse::swap(IfNoElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block, other.m_nested_block);
 }
 IfNoElse::~IfNoElse() {
 	delete(m_expr);
 	delete(m_nested_block);
  }
 void IfNoElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block->accept( v );
  }
 void IfNoElse::accept(Visitor *v) { v->visitIfNoElse(this); }
 IfNoElse *IfNoElse::clone() const { return new IfNoElse(*this); }
 
 
/********* IfWithElse ************/
 IfWithElse::IfWithElse(Expr *p1, Nested_block *p2, Nested_block *p3)  {
	m_expr = p1;
	m_nested_block_1 = p2;
	m_nested_block_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block_1->m_parent_attribute = &m_attribute;
 	m_nested_block_2->m_parent_attribute = &m_attribute;
  }
 IfWithElse::IfWithElse(const IfWithElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block_1 = other.m_nested_block_1->clone();
	m_nested_block_2 = other.m_nested_block_2->clone();
 }
 IfWithElse &IfWithElse::operator=(const IfWithElse & other) { IfWithElse tmp(other); swap(tmp); return *this; }
 void IfWithElse::swap(IfWithElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block_1, other.m_nested_block_1);
	std::swap(m_nested_block_2, other.m_nested_block_2);
 }
 IfWithElse::~IfWithElse() {
 	delete(m_expr);
 	delete(m_nested_block_1);
 	delete(m_nested_block_2);
  }
 void IfWithElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block_1->accept( v );
 	m_nested_block_2->accept( v );
  }
 void IfWithElse::accept(Visitor *v) { v->visitIfWithElse(this); }
 IfWithElse *IfWithElse::clone() const { return new IfWithElse(*this); }
 
 
/********* WhileLoop ************/
 WhileLoop::WhileLoop(Expr *p1, Nested_block *p2)  {
	m_expr = p1;
	m_nested_block = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 WhileLoop::WhileLoop(const WhileLoop & other) {
	m_expr = other.m_expr->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 WhileLoop &WhileLoop::operator=(const WhileLoop & other) { WhileLoop tmp(other); swap(tmp); return *this; }
 void WhileLoop::swap(WhileLoop & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block, other.m_nested_block);
 }
 WhileLoop::~WhileLoop() {
 	delete(m_expr);
 	delete(m_nested_block);
  }
 void WhileLoop::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block->accept( v );
  }
 void WhileLoop::accept(Visitor *v) { v->visitWhileLoop(this); }
 WhileLoop *WhileLoop::clone() const { return new WhileLoop(*this); }
 
 
/********* CodeBlock ************/
 CodeBlock::CodeBlock(Nested_block *p1)  {
	m_nested_block = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_nested_block->m_parent_attribute = &m_attribute;
  }
 CodeBlock::CodeBlock(const CodeBlock & other) {
	m_nested_block = other.m_nested_block->clone();
 }
 CodeBlock &CodeBlock::operator=(const CodeBlock & other) { CodeBlock tmp(other); swap(tmp); return *this; }
 void CodeBlock::swap(CodeBlock & other) {
	std::swap(m_nested_block, other.m_nested_block);
 }
 CodeBlock::~CodeBlock() {
 	delete(m_nested_block);
  }
 void CodeBlock::visit_children( Visitor* v ) {
 	m_nested_block->accept( v );
  }
 void CodeBlock::accept(Visitor *v) { v->visitCodeBlock(this); }
 CodeBlock *CodeBlock::clone() const { return new CodeBlock(*this); }
 
 
/********* Return ************/
 Return::Return(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Return::Return(const Return & other) {
	m_expr = other.m_expr->clone();
 }
 Return &Return::operator=(const Return & other) { Return tmp(other); swap(tmp); return *this; }
 void Return::swap(Return & other) {
	std::swap(m_expr, other.m_expr);
 }
 Return::~Return() {
 	delete(m_expr);
  }
 void Return::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Return::accept(Visitor *v) { v->visitReturn(this); }
 Return *Return::clone() const { return new Return(*this); }
 
 
/********* TInteger ************/
 TInteger::TInteger()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TInteger::TInteger(const TInteger & other) {
 }
 TInteger &TInteger::operator=(const TInteger & other) { TInteger tmp(other); swap(tmp); return *this; }
 void TInteger::swap(TInteger & other) {
 }
 TInteger::~TInteger() {
  }
 void TInteger::visit_children( Visitor* v ) {
  }
 void TInteger::accept(Visitor *v) { v->visitTInteger(this); }
 TInteger *TInteger::clone() const { return new TInteger(*this); }
 
 
/********* TCharacter ************/
 TCharacter::TCharacter()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TCharacter::TCharacter(const TCharacter & other) {
 }
 TCharacter &TCharacter::operator=(const TCharacter & other) { TCharacter tmp(other); swap(tmp); return *this; }
 void TCharacter::swap(TCharacter & other) {
 }
 TCharacter::~TCharacter() {
  }
 void TCharacter::visit_children( Visitor* v ) {
  }
 void TCharacter::accept(Visitor *v) { v->visitTCharacter(this); }
 TCharacter *TCharacter::clone() const { return new TCharacter(*this); }
 
 
/********* TBoolean ************/
 TBoolean::TBoolean()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TBoolean::TBoolean(const TBoolean & other) {
 }
 TBoolean &TBoolean::operator=(const TBoolean & other) { TBoolean tmp(other); swap(tmp); return *this; }
 void TBoolean::swap(TBoolean & other) {
 }
 TBoolean::~TBoolean() {
  }
 void TBoolean::visit_children( Visitor* v ) {
  }
 void TBoolean::accept(Visitor *v) { v->visitTBoolean(this); }
 TBoolean *TBoolean::clone() const { return new TBoolean(*this); }
 
 
/********* TCharPtr ************/
 TCharPtr::TCharPtr()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TCharPtr::TCharPtr(const TCharPtr & other) {
 }
 TCharPtr &TCharPtr::operator=(const TCharPtr & other) { TCharPtr tmp(other); swap(tmp); return *this; }
 void TCharPtr::swap(TCharPtr & other) {
 }
 TCharPtr::~TCharPtr() {
  }
 void TCharPtr::visit_children( Visitor* v ) {
  }
 void TCharPtr::accept(Visitor *v) { v->visitTCharPtr(this); }
 TCharPtr *TCharPtr::clone() const { return new TCharPtr(*this); }
 
 
/********* TIntPtr ************/
 TIntPtr::TIntPtr()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TIntPtr::TIntPtr(const TIntPtr & other) {
 }
 TIntPtr &TIntPtr::operator=(const TIntPtr & other) { TIntPtr tmp(other); swap(tmp); return *this; }
 void TIntPtr::swap(TIntPtr & other) {
 }
 TIntPtr::~TIntPtr() {
  }
 void TIntPtr::visit_children( Visitor* v ) {
  }
 void TIntPtr::accept(Visitor *v) { v->visitTIntPtr(this); }
 TIntPtr *TIntPtr::clone() const { return new TIntPtr(*this); }
 
 
/********* TString ************/
 TString::TString(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 TString::TString(const TString & other) {
	m_primitive = other.m_primitive->clone();
 }
 TString &TString::operator=(const TString & other) { TString tmp(other); swap(tmp); return *this; }
 void TString::swap(TString & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 TString::~TString() {
 	delete(m_primitive);
  }
 void TString::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void TString::accept(Visitor *v) { v->visitTString(this); }
 TString *TString::clone() const { return new TString(*this); }
 
 
/********* AbsoluteValue ************/
 AbsoluteValue::AbsoluteValue(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 AbsoluteValue::AbsoluteValue(const AbsoluteValue & other) {
	m_expr = other.m_expr->clone();
 }
 AbsoluteValue &AbsoluteValue::operator=(const AbsoluteValue & other) { AbsoluteValue tmp(other); swap(tmp); return *this; }
 void AbsoluteValue::swap(AbsoluteValue & other) {
	std::swap(m_expr, other.m_expr);
 }
 AbsoluteValue::~AbsoluteValue() {
 	delete(m_expr);
  }
 void AbsoluteValue::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void AbsoluteValue::accept(Visitor *v) { v->visitAbsoluteValue(this); }
 AbsoluteValue *AbsoluteValue::clone() const { return new AbsoluteValue(*this); }
 
 
/********* AddressOf ************/
 AddressOf::AddressOf(Lhs *p1)  {
	m_lhs = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_lhs->m_parent_attribute = &m_attribute;
  }
 AddressOf::AddressOf(const AddressOf & other) {
	m_lhs = other.m_lhs->clone();
 }
 AddressOf &AddressOf::operator=(const AddressOf & other) { AddressOf tmp(other); swap(tmp); return *this; }
 void AddressOf::swap(AddressOf & other) {
	std::swap(m_lhs, other.m_lhs);
 }
 AddressOf::~AddressOf() {
 	delete(m_lhs);
  }
 void AddressOf::visit_children( Visitor* v ) {
 	m_lhs->accept( v );
  }
 void AddressOf::accept(Visitor *v) { v->visitAddressOf(this); }
 AddressOf *AddressOf::clone() const { return new AddressOf(*this); }
 
 
/********* And ************/
 And::And(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 And::And(const And & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 And &And::operator=(const And & other) { And tmp(other); swap(tmp); return *this; }
 void And::swap(And & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 And::~And() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void And::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void And::accept(Visitor *v) { v->visitAnd(this); }
 And *And::clone() const { return new And(*this); }
 
 
/********* Div ************/
 Div::Div(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Div::Div(const Div & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Div &Div::operator=(const Div & other) { Div tmp(other); swap(tmp); return *this; }
 void Div::swap(Div & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Div::~Div() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Div::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Div::accept(Visitor *v) { v->visitDiv(this); }
 Div *Div::clone() const { return new Div(*this); }
 
 
/********* Compare ************/
 Compare::Compare(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Compare::Compare(const Compare & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Compare &Compare::operator=(const Compare & other) { Compare tmp(other); swap(tmp); return *this; }
 void Compare::swap(Compare & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Compare::~Compare() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Compare::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Compare::accept(Visitor *v) { v->visitCompare(this); }
 Compare *Compare::clone() const { return new Compare(*this); }
 
 
/********* Gt ************/
 Gt::Gt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gt::Gt(const Gt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gt &Gt::operator=(const Gt & other) { Gt tmp(other); swap(tmp); return *this; }
 void Gt::swap(Gt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gt::~Gt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Gt::accept(Visitor *v) { v->visitGt(this); }
 Gt *Gt::clone() const { return new Gt(*this); }
 
 
/********* Gteq ************/
 Gteq::Gteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gteq::Gteq(const Gteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gteq &Gteq::operator=(const Gteq & other) { Gteq tmp(other); swap(tmp); return *this; }
 void Gteq::swap(Gteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gteq::~Gteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Gteq::accept(Visitor *v) { v->visitGteq(this); }
 Gteq *Gteq::clone() const { return new Gteq(*this); }
 
 
/********* Lt ************/
 Lt::Lt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lt::Lt(const Lt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lt &Lt::operator=(const Lt & other) { Lt tmp(other); swap(tmp); return *this; }
 void Lt::swap(Lt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lt::~Lt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Lt::accept(Visitor *v) { v->visitLt(this); }
 Lt *Lt::clone() const { return new Lt(*this); }
 
 
/********* Lteq ************/
 Lteq::Lteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lteq::Lteq(const Lteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lteq &Lteq::operator=(const Lteq & other) { Lteq tmp(other); swap(tmp); return *this; }
 void Lteq::swap(Lteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lteq::~Lteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Lteq::accept(Visitor *v) { v->visitLteq(this); }
 Lteq *Lteq::clone() const { return new Lteq(*this); }
 
 
/********* Minus ************/
 Minus::Minus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Minus::Minus(const Minus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Minus &Minus::operator=(const Minus & other) { Minus tmp(other); swap(tmp); return *this; }
 void Minus::swap(Minus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Minus::~Minus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Minus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Minus::accept(Visitor *v) { v->visitMinus(this); }
 Minus *Minus::clone() const { return new Minus(*this); }
 
 
/********* Noteq ************/
 Noteq::Noteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Noteq::Noteq(const Noteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Noteq &Noteq::operator=(const Noteq & other) { Noteq tmp(other); swap(tmp); return *this; }
 void Noteq::swap(Noteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Noteq::~Noteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Noteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Noteq::accept(Visitor *v) { v->visitNoteq(this); }
 Noteq *Noteq::clone() const { return new Noteq(*this); }
 
 
/********* Or ************/
 Or::Or(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Or::Or(const Or & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Or &Or::operator=(const Or & other) { Or tmp(other); swap(tmp); return *this; }
 void Or::swap(Or & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Or::~Or() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Or::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Or::accept(Visitor *v) { v->visitOr(this); }
 Or *Or::clone() const { return new Or(*this); }
 
 
/********* Plus ************/
 Plus::Plus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Plus::Plus(const Plus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Plus &Plus::operator=(const Plus & other) { Plus tmp(other); swap(tmp); return *this; }
 void Plus::swap(Plus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Plus::~Plus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Plus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Plus::accept(Visitor *v) { v->visitPlus(this); }
 Plus *Plus::clone() const { return new Plus(*this); }
 
 
/********* Times ************/
 Times::Times(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Times::Times(const Times & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Times &Times::operator=(const Times & other) { Times tmp(other); swap(tmp); return *this; }
 void Times::swap(Times & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Times::~Times() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Times::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Times::accept(Visitor *v) { v->visitTimes(this); }
 Times *Times::clone() const { return new Times(*this); }
 
 
/********* Not ************/
 Not::Not(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Not::Not(const Not & other) {
	m_expr = other.m_expr->clone();
 }
 Not &Not::operator=(const Not & other) { Not tmp(other); swap(tmp); return *this; }
 void Not::swap(Not & other) {
	std::swap(m_expr, other.m_expr);
 }
 Not::~Not() {
 	delete(m_expr);
  }
 void Not::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Not::accept(Visitor *v) { v->visitNot(this); }
 Not *Not::clone() const { return new Not(*this); }
 
 
/********* Uminus ************/
 Uminus::Uminus(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Uminus::Uminus(const Uminus & other) {
	m_expr = other.m_expr->clone();
 }
 Uminus &Uminus::operator=(const Uminus & other) { Uminus tmp(other); swap(tmp); return *this; }
 void Uminus::swap(Uminus & other) {
	std::swap(m_expr, other.m_expr);
 }
 Uminus::~Uminus() {
 	delete(m_expr);
  }
 void Uminus::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Uminus::accept(Visitor *v) { v->visitUminus(this); }
 Uminus *Uminus::clone() const { return new Uminus(*this); }
 
 
/********* Ident ************/
 Ident::Ident(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
  }
 Ident::Ident(const Ident & other) {
	m_symname = other.m_symname->clone();
 }
 Ident &Ident::operator=(const Ident & other) { Ident tmp(other); swap(tmp); return *this; }
 void Ident::swap(Ident & other) {
	std::swap(m_symname, other.m_symname);
 }
 Ident::~Ident() {
 	delete(m_symname);
  }
 void Ident::visit_children( Visitor* v ) {
 	m_symname->accept( v );
  }
 void Ident::accept(Visitor *v) { v->visitIdent(this); }
 Ident *Ident::clone() const { return new Ident(*this); }
 
 
/********* ArrayAccess ************/
 ArrayAccess::ArrayAccess(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 ArrayAccess::ArrayAccess(const ArrayAccess & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 ArrayAccess &ArrayAccess::operator=(const ArrayAccess & other) { ArrayAccess tmp(other); swap(tmp); return *this; }
 void ArrayAccess::swap(ArrayAccess & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 ArrayAccess::~ArrayAccess() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void ArrayAccess::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 void ArrayAccess::accept(Visitor *v) { v->visitArrayAccess(this); }
 ArrayAccess *ArrayAccess::clone() const { return new ArrayAccess(*this); }
 
 
/********* IntLit ************/
 IntLit::IntLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 IntLit::IntLit(const IntLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 IntLit &IntLit::operator=(const IntLit & other) { IntLit tmp(other); swap(tmp); return *this; }
 void IntLit::swap(IntLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 IntLit::~IntLit() {
 	delete(m_primitive);
  }
 void IntLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void IntLit::accept(Visitor *v) { v->visitIntLit(this); }
 IntLit *IntLit::clone() const { return new IntLit(*this); }
 
 
/********* CharLit ************/
 CharLit::CharLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 CharLit::CharLit(const CharLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 CharLit &CharLit::operator=(const CharLit & other) { CharLit tmp(other); swap(tmp); return *this; }
 void CharLit::swap(CharLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 CharLit::~CharLit() {
 	delete(m_primitive);
  }
 void CharLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void CharLit::accept(Visitor *v) { v->visitCharLit(this); }
 CharLit *CharLit::clone() const { return new CharLit(*this); }
 
 
/********* BoolLit ************/
 BoolLit::BoolLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 BoolLit::BoolLit(const BoolLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 BoolLit &BoolLit::operator=(const BoolLit & other) { BoolLit tmp(other); swap(tmp); return *this; }
 void BoolLit::swap(BoolLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 BoolLit::~BoolLit() {
 	delete(m_primitive);
  }
 void BoolLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void BoolLit::accept(Visitor *v) { v->visitBoolLit(this); }
 BoolLit *BoolLit::clone() const { return new BoolLit(*this); }
 
 
/********* Deref ************/
 Deref::Deref(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Deref::Deref(const Deref & other) {
	m_expr = other.m_expr->clone();
 }
 Deref &Deref::operator=(const Deref & other) { Deref tmp(other); swap(tmp); return *this; }
 void Deref::swap(Deref & other) {
	std::swap(m_expr, other.m_expr);
 }
 Deref::~Deref() {
 	delete(m_expr);
  }
 void Deref::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Deref::accept(Visitor *v) { v->visitDeref(this); }
 Deref *Deref::clone() const { return new Deref(*this); }
 
 
/********* Variable ************/
 Variable::Variable(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
  }
 Variable::Variable(const Variable & other) {
	m_symname = other.m_symname->clone();
 }
 Variable &Variable::operator=(const Variable & other) { Variable tmp(other); swap(tmp); return *this; }
 void Variable::swap(Variable & other) {
	std::swap(m_symname, other.m_symname);
 }
 Variable::~Variable() {
 	delete(m_symname);
  }
 void Variable::visit_children( Visitor* v ) {
 	m_symname->accept( v );
  }
 void Variable::accept(Visitor *v) { v->visitVariable(this); }
 Variable *Variable::clone() const { return new Variable(*this); }
 
 
/********* DerefVariable ************/
 DerefVariable::DerefVariable(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
  }
 DerefVariable::DerefVariable(const DerefVariable & other) {
	m_symname = other.m_symname->clone();
 }
 DerefVariable &DerefVariable::operator=(const DerefVariable & other) { DerefVariable tmp(other); swap(tmp); return *this; }
 void DerefVariable::swap(DerefVariable & other) {
	std::swap(m_symname, other.m_symname);
 }
 DerefVariable::~DerefVariable() {
 	delete(m_symname);
  }
 void DerefVariable::visit_children( Visitor* v ) {
 	m_symname->accept( v );
  }
 void DerefVariable::accept(Visitor *v) { v->visitDerefVariable(this); }
 DerefVariable *DerefVariable::clone() const { return new DerefVariable(*this); }
 
 
/********* ArrayElement ************/
 ArrayElement::ArrayElement(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 ArrayElement::ArrayElement(const ArrayElement & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 ArrayElement &ArrayElement::operator=(const ArrayElement & other) { ArrayElement tmp(other); swap(tmp); return *this; }
 void ArrayElement::swap(ArrayElement & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 ArrayElement::~ArrayElement() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void ArrayElement::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 void ArrayElement::accept(Visitor *v) { v->visitArrayElement(this); }
 ArrayElement *ArrayElement::clone() const { return new ArrayElement(*this); }
 
 

