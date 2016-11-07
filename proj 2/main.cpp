/**
 *  This file is provided for you to run your parser.  You should not have
 *  to edit anything if you did the yacc and lex files correctly.  All this
 *  file does is calls yyparse().
 */

#include "parser.hpp"
#include <assert.h>

extern int yydebug;
extern int yyparse();

int main(void)
{
    yydebug = 0;    // Set yydebug to 1 if you want yyparse() to dump a trace
    yyparse();
    return 0;
}
