#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

enum Basetype
{
    bt_undef,
    bt_integer,
    bt_intptr,
    bt_boolean,
    bt_char,
    bt_charptr,
    bt_procedure,
    bt_string
};

class Attribute
{
  public:
    Basetype m_basetype;    // Type of the subtree
    int lineno;             // Line number on which that AST node resides

    Attribute()
    {
        m_basetype = bt_undef;
        lineno = 0;
    }
};

#endif // ATTRIBUTE_HPP
