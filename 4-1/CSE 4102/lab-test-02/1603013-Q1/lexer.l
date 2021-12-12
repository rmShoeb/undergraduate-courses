%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.tab.h"

	int lineno = 1;
	void yyerror();

	/*
	* Roll No: 1603013
	* Question-1
	* while (b_c > 10);
	*/
%}

alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
print       [ -~]
us			[_]

ID          {alpha}({alnum}|{us})*
ICONST      {digit}+
FCONST      {digit}*"."{digit}+
CCONST      (\'{print}\')
%%

"//".*      {}

"int"       { return INT; }
"double"    { return DOUBLE; }
"char"		{ return CHAR; }

"if"		{ return IF; }
"else"		{ return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }

"+"         { return ADDOP; }
"-"         { return SUBOP; }
"*"         { return MULOP; }
"/"         { return DIVOP; }
"=="        { return EQUOP; }
">"         { return GT; }
"<"         { return LT; }
"--"        { return DECR; }
"++"        { return INCR; }
">="        { return GT_OR_EQUOP; }
"<="        { return LT_OR_EQUOP; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMI; }
"="         { return ASSIGN; }

{ID}        { return ID; }
{ICONST}    { return ICONST; }
{FCONST}    { return FCONST; }
{CCONST}    { return CCONST; }

"\n"        { lineno += 1; }
[ \t\r\f]+  {}

.           { yyerror("Unrecognized character"); }
