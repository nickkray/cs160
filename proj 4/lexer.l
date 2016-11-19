%option yylineno
%pointer

%{
    #include <cstdlib>
    #include <cstring>
    #include "ast.hpp"
    #include "parser.hpp"

    void yyerror(const char *);
%}

/** WRITE ME:
 *  Put any definitions you need here. Add your own regular expressions
 *  below for ALL tokens defined in the manual. You can choose not to use
 *  definitions here.
 */

/* HERE */

/** The example below is very simple, but it shows almost everything you will
 *  need to do for this first part. The syntax is as follows:
 *
 *  regular_expression      {  c code  }
 *
 * The lexer will try to match each regular expression. When it does it will
 * execute the corresponding C code.
*/


%x comment

%%

"integer"		{return _INT; }
"boolean"		{return _BOOL; }
"char"			{return _CHAR; }
"string"		{return _STRING; }
"intptr"		{return _INTPTR; }
"charptr"		{return _CHARPTR; }
"if"			{return IF; }
"else"			{return ELSE; }
"while"			{return WHILE; }
"var"			{printf("var\n");return VAR; }
"procedure"		{printf("procedure\n");return PROCEDURE; }
"return"		{return RET; }

"true"			{  yylval.u_base_int = 1; return TRUE;}
"false"		    { yylval.u_base_int = 0; return FALSE; }
"null"			{yylval.u_base_int = 0;return NULLTOKEN;}

[a-zA-Z][a-zA-Z0-9_]* 		{yylval.u_base_charptr = strdup(yytext);return VARNAME; }

[0][x|X][0-9A-F]* {   yylval.u_base_int = strtol(yytext,NULL, 16); return INT; }
[0][0-7]+ {           yylval.u_base_int = strtol(yytext,NULL, 8); return INT;  }
[0-1]+[b] {          yylval.u_base_int = strtol(yytext,NULL, 2); return INT; }
[1-9][0-9]* {        yylval.u_base_int = atoi(yytext); return INT; }
[0] {                yylval.u_base_int = atoi(yytext); return INT; }



\"([^"]*)\"						{yylval.u_base_charptr = strndup(yytext, strlen(yytext)-1)+1;return STRING;}
\'[a-zA-Z0-9]\'				{yylval.u_base_int = int(yytext[1]);return CHAR;}
\'[a-zA-Z0-9][a-zA-Z0-9]+\'			yyerror("char spans multiple characters");exit(1);

";"				{return SEMI_COLON; }
","				{return COMMA;}
":"				{return COLON; }
"|"				{return PIPE; }
"{"				{printf("{");return LEFT_BRACE; }
"}"				{printf("}");return RIGHT_BRACE; }
"["				{return LEFT_BRACKET;}
"]"				{return RIGHT_BRACKET;}
"("				{printf("(");return LEFT_PAREN;}
")"				{printf(")");return RIGHT_PAREN;}

"&&"			{return ANDAND; }
"=="			{return EQEQ; }
">="			{return GTEQ; }
"<="			{return LTEQ; }
"!="			{return NE; }
"!"				{return NOT; }
"||"			{return OR; }
"="				{return EQ; }
">"				{return GT; }
"<"				{return LT; }

"&"				{return AND; }
"^"				{return XOR; }
"-"				{return MINUS; }
"*"				{return MULT; }
"+"				{return PLUS; }
"/"				{return DIV; }


"/%"              BEGIN(comment);
<comment>"%"+"/"  BEGIN(INITIAL);
<comment><<EOF>>  yyerror("dangling comment");exit(1);
<comment>.        ;

[ \r\t\n]             ; /* skip whitespace */

.                   yyerror((char *) "invalid character"); exit(1);

%%


/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

int yywrap(void) {
    return 1;
}
