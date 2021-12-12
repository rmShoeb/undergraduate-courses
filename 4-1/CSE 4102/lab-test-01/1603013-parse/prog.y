%{
    #include <stdio.h>
    void yyerror(char *s);
    int yylex();
%}

%token IF WHILE NUM ID TYPE EQUAL SEMI LB RB LP RP LE DECREMENT
%start program

%%
program: WHILE LP exp RP LB statement RB;
statement: IF LP exp RP LB statement RB
        | exp SEMI
        ;
exp: ID
    | TYPE ID LE NUM
    | DECREMENT ID EQUAL NUM
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