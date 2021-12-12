%{
    #include <stdio.h>
    void yyerror(char *s);
    int yylex();
%}

%token MAIN KEYWORD IF WHILE ID NUM ADD SUB ASSIGN SEMI EQUAL LB RB LP RP
%start program
%left ADD SUB

%%
program: KEYWORD MAIN LP RP LB statement RB;
statement: declaration statement
        | declaration
        | exp statement
        | exp
        | loop statement
        |loop
        ;
exp: ID ASSIGN ID ADD ID SEMI;
declaration: KEYWORD ID ASSIGN number SEMI;
loop: WHILE LP number RP LB statement RB;
number: NUM
    |   SUB NUM
    ;
%%

int main(){
    yyparse();
    printf("successful parsing\n");
    return 0;
}

void yyerror(char *s){
    fprintf(stderr, "error: %s\n", s);
}