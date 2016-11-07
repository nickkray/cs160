#include <algorithm>
#include <functional>
#include <unordered_map>

#include <cassert>
#include <cstdio>
#include <cstring>

#include "symtab.hpp"

/****** SymName Implemenation **************************************/

SymName::SymName(char* const x)
{
    m_spelling = x;
    m_parent_attribute = NULL;
}

SymName::SymName(const SymName & other)
{
    m_spelling = strdup(other.m_spelling);
    m_parent_attribute = other.m_parent_attribute;
}

SymName& SymName::operator=(const SymName & other)
{
    delete m_spelling;
    SymName tmp(other);
    swap(tmp);
    return *this;
}

void SymName::swap(SymName & other)
{
    std::swap(m_spelling, other.m_spelling);
}

SymName::~SymName()
{
    delete(m_spelling);
}

void SymName::accept(Visitor *v)
{
    v->visitSymName(this);
}

SymName* SymName::clone() const
{
    return new SymName(*this);
}

const char* SymName::spelling()
{
    return m_spelling;
}

const Symbol* SymName::symbol()
{
    return m_symbol;
}

void SymName::set_symbol(Symbol* s)
{
    // You should not try to reset a symbol pointer
    // Once it is set, that pointer is used all
    // sorts of places - changes to it once it is
    // set can results in weird behavior
    assert(m_symbol == NULL);
    m_symbol = s;
}


/****** SymScope Def (used by SymTab) **************************************/

// Comparison structure for strings
struct eqstr {
    bool operator()(const char* s1, const char* s2) const
    { return strcmp(s1, s2) == 0; }
};


class SymScope
{
  private:
    SymScope* m_parent;
    std::list<SymScope*> m_child;
    typedef std::unordered_map<char*, Symbol*, std::hash<char*>, eqstr> ScopeTableType;
    ScopeTableType m_scopetable;

    SymScope* parent();
    void add_child(SymScope* c);
    SymScope(SymScope * parent);
    bool is_dup_string(char* name);     // Used for error checking

    void dump(FILE* f, int nest_level);
    SymScope* open_scope();
    SymScope* close_scope();
    bool exist(char* name);
    Symbol* insert(char* name, Symbol * s);
    Symbol* lookup(const char * name);

  public:

    SymScope();
    ~SymScope();

  friend class SymTab;                  // Symtab is a wrapper class
};

/****** SymTab Implementation **************************************/

SymTab::SymTab()
{
    m_head = new SymScope;
    m_cur_scope = m_head;
}

SymTab::~SymTab()
{
    delete m_head;
}

bool SymTab::is_dup_string(char* name)
{
    return m_head->is_dup_string(name);
}

void SymTab::open_scope()
{
    m_cur_scope = m_cur_scope->open_scope();
    assert(m_cur_scope != NULL);
}

void SymTab::close_scope()
{
    //check to make sure we don't pop more than we push
    assert(m_cur_scope != m_head);
    assert(m_cur_scope != NULL);

    m_cur_scope = m_cur_scope->close_scope();
}

bool SymTab::exist(char* name)
{
    assert(name != NULL);
    return m_cur_scope->exist(name);
}

bool SymTab::insert(char* name, Symbol * s)
{
    assert(name != NULL);
    assert(s != NULL);
    // the assert below fails, it is because you tried to insert
    // a pointer to a string that is already in the SymTab.  You
    // can have duplicate names, but each needs to reside it it's
    // own chunk of memory (see example)
    assert(is_dup_string(name));
    Symbol* r = m_cur_scope->insert(name, s);
    if(r == NULL) {
        return true;
    } else {
        return false;
    }
}

bool SymTab::insert_in_parent_scope(char* name, Symbol * s)
{
    assert(name != NULL);
    assert(s != NULL);
    // the assert below fails, it is because you tried to insert
    // a pointer to a string that is already in the SymTab.  You
    // can have duplicate names, but each needs to reside it it's
    // own chunk of memory (see example)
    assert(is_dup_string(name));
    // make sure there is an actual parent scope
    assert(m_cur_scope->m_parent != NULL);
    Symbol* r = m_cur_scope->m_parent->insert(name, s);
    if(r == NULL) {
        return true;
    } else {
        return false;
    }
}

Symbol* SymTab::lookup( const char * name )
{
    assert(name != NULL);
    return m_cur_scope->lookup(name);
}

void SymTab::dump(FILE* f)
{
    m_head->dump(f, 0);
}

/****** SymScope Implementation **************************************/

SymScope::SymScope()
{
    m_parent = NULL;
}

SymScope::SymScope(SymScope * parent)
{
    m_parent = parent;
    if(parent!=NULL) {
        parent->add_child(this);
    }
}

SymScope::~SymScope()
{
    // Delete the keys, but not the symbols (symbols are linked elsewhere)
    ScopeTableType::iterator si, this_si;

    si = m_scopetable.begin();
    while(si!=m_scopetable.end())
    {
        char* oldkey = si->first;
        this_si = si;
        ++si;

        m_scopetable.erase(this_si);
        free(oldkey);
    }

    // Now delete all the children
    std::list<SymScope*>::iterator li;
    for(li=m_child.begin(); li!=m_child.end(); ++li)
    {
        delete *li;
    }
}

void SymScope::dump(FILE* f, int nest_level)
{
    // Recursively prints out the symbol table
    // from the head down through all the childrens

    ScopeTableType::iterator si;

    // Indent appropriately
    for(int i=0; i<nest_level; i++) {
        std::fprintf(f, "\t");
    }
    std::fprintf(f, "+-- Symbol Scope ---\n");

    for(si = m_scopetable.begin(); si != m_scopetable.end(); ++si)
    {
        // Indent appropriately
        for(int i=0; i<nest_level; i++) {
            std::fprintf(f, "\t");
        }
        std::fprintf(f, "| %s \n", si->first);
    }
    for(int i=0; i<nest_level; i++) {
        std::fprintf(f, "\t");
    }
    std::fprintf(f,"+-------------\n\n");

    // Now print all the children
    std::list<SymScope*>::iterator li;
    for(li=m_child.begin(); li!=m_child.end(); ++li)
    {
        (*li)->dump(f, nest_level+1);
    }
}

bool SymScope::is_dup_string(char* name)
{
    ScopeTableType::iterator si;

    si = m_scopetable.find(name);
    if(si != m_scopetable.end()) {
        // Check if the pointers match
        if(si->first == name) {
            return false;
        }
    }

    std::list<SymScope*>::iterator li;
    for(li=m_child.begin(); li!=m_child.end(); ++li)
    {
        bool r = (*li)->is_dup_string(name);
        if(r==false) {
            return false;
        }
    }

    // If it gets this far, there is no duplicate
    return true;
}

void SymScope::add_child(SymScope* c)
{
    m_child.push_back(c);
}

SymScope* SymScope::open_scope()
{
    return new SymScope(this);
}

SymScope* SymScope::close_scope()
{
    return m_parent;
}

bool SymScope::exist( char* name )
{
    Symbol* s;
    s = lookup(name);
    // Return true if name exists
    if(s!=NULL) {
        return true;
    } else {
        return false;
    }
}

Symbol* SymScope::insert( char* name, Symbol * s )
{
    std::pair<ScopeTableType::iterator,bool> iret;
    typedef std::pair<char*,Symbol*> hpair;
    iret = m_scopetable.insert(hpair(name, s));
    if(iret.second == true) {
        // Insert was successfull
        return NULL;
    } else {
        // Cannot insert, there was a duplicate entry
        // Return a pointer to the conflicting symbol
        return iret.first->second;
    }
}

Symbol* SymScope::lookup( const char * name )
{
    // First check the current table;
    ScopeTableType::const_iterator i;
    i = m_scopetable.find( (char*) name );
    if(i != m_scopetable.end()) {
        return i->second;
    }

    // Failing that, check all the parents;
    if( m_parent != NULL) {
        return m_parent->lookup( name );
    } else {
        // If this has no parents, then it cannot be found
        return NULL;
    }
}
