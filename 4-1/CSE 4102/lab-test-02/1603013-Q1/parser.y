%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void yyerror();

	extern int lineno;
	extern int yylex();
%}

%token INT IF ELSE WHILE FOR CONTINUE BREAK PRINT DOUBLE CHAR
%token ADDOP SUBOP MULOP DIVOP EQUOP LT GT DECR INCR
%token GT_OR_EQUOP LT_OR_EQUOP
%token LPAREN RPAREN LBRACE RBRACE SEMI ASSIGN
%token ID
%token ICONST
%token FCONST
%token CCONST

%left ADDOP SUBOP
%left MULOP DIVOP
%left LT GT
%left EQUOP
%right ASSIGN

%start code

%%
code: statements;

statements: statements statement
    |
    ;

statement: declaration
    | for_statement
    | while_statement
    | if_statement
    | ID ASSIGN exp SEMI
    | ID INCR SEMI
    | ID DECR SEMI
    ;

declaration: type ID LPAREN RPAREN tail
    | type ID SEMI
    | type ID ASSIGN exp SEMI
    ;

type: INT
    | DOUBLE
    | CHAR 
    ;

exp: ID
    | constant
    | exp operator exp
    | exp INCR
    | exp DECR
    | LPAREN exp RPAREN
    ;

constant: ICONST
    | FCONST
    | CCONST
    ;
operator: ADDOP
    | SUBOP
    | MULOP
    | DIVOP
    | GT
    | GT_OR_EQUOP
    | LT
    | LT_OR_EQUOP
    | EQUOP
    ;

for_statement: FOR LPAREN exp ASSIGN exp SEMI exp SEMI RPAREN tail;
while_statement: WHILE LPAREN exp RPAREN SEMI;

if_statement: IF LPAREN exp RPAREN tail else_if_statement
    | IF LPAREN exp RPAREN tail else_statement
    ;
else_if_statement: ELSE IF LPAREN exp RPAREN tail else_statement;
else_statement: ELSE tail | ;

tail: LBRACE statements RBRACE;

%%

void yyerror ()
{
	printf("Syntax error at line %d\n", lineno);
	exit(1);
}

int main (int argc, char *argv[])
{
	yyparse();
	printf("Parsing finished!\n");	
	return 0;
}
