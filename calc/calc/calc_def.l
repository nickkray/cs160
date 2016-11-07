%{

#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"

%}

%%

[\*\(\)\.\+\-%]		{ return *yytext; }
[0-9][0-9]*		{ return 'n'; }

[ \t\n]  		; /* skip whitespace */


.	yyerror("invalid character");

%%

int yywrap(void) {
	return 1;
}
