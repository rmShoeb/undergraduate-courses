%{
    #include <stdio.h>
    void yyerror(char *s);
    int yylex();
%}

%token NUM ADD SUB ASSIGN SEMI ID
// %start cal
%start program
%left '+' '-'

%%
// cal: exp {
//     $$=$1;
//     printf("%d\n", $$);
// }
// exp:  exp ADD NUM   {$$=$1+$3;}
//     | exp SUB NUM   {$$=$1-$3;}
//     | NUM           {$$=$1;}
// ;
program: ID ASSIGN exp SEMI
    ;
exp:  exp ADD number
    | exp SUB number
    | NUM
    ;
number: NUM
    | SUB NUM
    ;
%%

int main(){
    yyparse();
    printf("finised\n");
}

void yyerror(char *s){
    fprintf(stderr, "%s\n", s);
    printf("%s\n", s);
}