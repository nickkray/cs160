
%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}


%%

List    : Expr ',' List {printf("parsed expresion\n");}
| {printf("parsed expresion\n");}
;

Expr    : Term ExprP
;

ExprP   : '+' Term ExprP
| '-' Term ExprP
|
;

Term    : Factor TermP
;

TermP   : '*' Factor TermP
| '/' Factor TermP
|
;

Factor  : 'n'
| '{' Expr ')'
;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return;
}

int main(void) {
	yyparse();
	return 0;
}
