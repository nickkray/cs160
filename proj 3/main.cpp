/**
 *  This file is provided for you to run your parser.  You should not have
 *  to edit anything if you did the yacc and lex files correctly.  All this
 *  file does is calls yyparse() and uses the visitor class ast2dot to print
 *  the graph.
 */

#include "ast.hpp"
#include "parser.hpp"
#include <assert.h>

extern int yydebug;
extern int yyparse();

void dopass_ast2dot(Program_ptr ast); // This is defined in ast2dot.cpp
Program_ptr ast;                      // Make sure to set this to the final
                                      // syntax tree in parser.ypp

int main(void)
{
    yydebug = 0;    // Set yydebug to 1 if you want yyparse() to dump a trace
    yyparse();
    if(ast) {       // Walk over the ast and print it out as a dot file
        dopass_ast2dot(ast);
    }

    return 0;
}
