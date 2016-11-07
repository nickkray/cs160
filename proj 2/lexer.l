%option yylineno
%pointer

%{
    #include <stdlib.h>
    #include <string.h>
    #include "parser.hpp"

    void yyerror(const char *);
%}

/** WRITE ME:
 *  Put any definitions you need here. Add your own regular expressions
 *  below for ALL tokens defined in the manual. You can choose not to use
 *  definitions here.
 */

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

"true"			{return TRUE;}
"false"			{return FALSE;}
"null"			{return NULLTOKEN;}

[01]+b                    { return INT;     } /* binary      */
0[xX][0-9A-F]+            { return INT;     } /* hexadecimal */
0[0-7]+                   { return INT;     } /* octal       */
[0-9]+                    { return INT;     } 
[a-zA-Z][a-zA-Z0-9_]* 		{printf("A");return VARNAME; }
\".*?\"						{return STRING;}
\'[a-zA-Z0-9]\'				{return CHAR;}
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
