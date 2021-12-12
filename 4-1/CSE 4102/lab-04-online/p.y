%{
    #include <stdio.h>
    void yyerror(char *s);
    int yylex();
%}

%token NUM ADD SUB IDENTIFIER ASSIGN SEMICOLON IF EQUALITY LB RB LP RP
// %start cal
%start program
%left ADD SUB

%%
// cal: exp {
//     $$=$1;
//     printf("%d\n", $$);
// };
// exp:    exp ADD NUM {$$=$1+$3; printf("ADD\n");}
//     |   exp SUB NUM {$$=$1-$3; printf("SUB\n");}
//     |   NUM         {$$=$1; printf("NUM\n");}
// ;
// exp:    NUM ADD exp {$$=$1+$3; printf("ADD\n");}
//     |   NUM SUB exp {$$=$1-$3; printf("SUB\n");}
//     |   NUM         {$$=$1; printf("NUM\n");}
// ;
program: statement;
id_decalre: IDENTIFIER ASSIGN exp SEMICOLON;
statement: IF LP exp RP LB exp RB; 
exp: exp ADD number
    | exp SUB number
    | exp EQUALITY number
    | number
    | id_decalre
    | IDENTIFIER
    ;
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