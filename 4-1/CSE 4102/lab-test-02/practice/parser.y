%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror();

    #include "symtab.c"

    extern int lineno;
    extern int yylex();
%}

%union{
    char str_val[100];
    int int_val;
}

%token INT CHAR IF ELSE WHILE CONTINUE BREAK PRINT DOUBLE
%token ADDOP SUBOP MULOP DIVOP EQUOP LT GT
%token LPAREN RPAREN LBRACE RBRACE SEMI ASSIGN
%token<str_val> ID
%token<str_val> ICONST
%token<str_val> FCONST
%token<str_val> CCONST

%type<int_val> type constant exp statement

%left   ADDOP SUBOP
%left   MULOP DIVOP
%left   LT GT
%left   EQUOP
%right  ASSIGN

%start code

%%
code:   statements;

statements: statements statement
        |   // empty terminal means epsilon
        ;

statement:  declaration
        |   ID ASSIGN exp SEMI {
            if(id_check($1) == -1){
                printf("%s is not declared\n", $1);
                yyerror();
            }

            if(type_check(get_type($1), $3) == -1) yyerror();
        }
        |   if_statement
        ;

if_statement:   IF head tail else_statement;
else_statement: ELSE tail
        |
        ;

head:   LPAREN exp RPAREN;
tail:   LBRACE statements RBRACE;

declaration: type ID SEMI {
    insert($2, $1);
}
    |   type ID ASSIGN exp SEMI
    ;
exp:    ID
    |   constant
    |   exp operator exp {
        printf("%d op %d\n", $1, $3);
        if(type_check($1, $3) == -1) yyerror();
        else $$ = type_check($1, $3);
    }
    |   LPAREN exp RPAREN
    ;

type:   INT     { $$=INT_TYPE; }
    |   DOUBLE  { $$=REAL_TYPE; }
    |   CHAR    { $$=CHAR_TYPE; }
    ;
constant:   ICONST  { $$=INT_TYPE; }
        |   FCONST  { $$=REAL_TYPE; }
        |   CCONST  { $$=CHAR_TYPE; }
        ;
operator:   ADDOP | SUBOP | MULOP | DIVOP | GT | LT;
%%

void yyerror(){
    printf("Syntax error at line %d\n", lineno);
    exit(1);
}

int main(int argc, char *argv[]){
    yyparse();
    printf("Parsing finished!\n");
    return 0;
}
