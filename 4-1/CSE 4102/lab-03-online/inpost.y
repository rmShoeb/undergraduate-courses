/**
    Declarations
**/
%{
    /**
    C declarations for:
    - actions part in rules section
    - auxiliary functions section
    **/
    #include <stdio.h>
    #include <stdlib.h>
%}
/**
    yacc declarations, e.g: tokens
    %left -> left associativity
    %right -> right associativity
    %nonassoc -> non-assosiativity
**/
%token DIGIT
%left '+'
%left '*'

/**
    Rules section
**/
%%
start: expr '\n'    {printf("\ncomplete\n");exit(1);}
    ;
expr: expr '+' expr {printf(" + ");}
    | expr '*' expr {printf(" * ");}
    | '(' expr ')'
    | DIGIT         {printf("%d ", $1);}
    ;
%%

/**
    Auxiliary functions section
**/
yyerror(){
    printf("Error");
}

yylex(){
    int c;
    c = getchar();
    if(isdigit(c)){
        yylval = c - '0';
        return DIGIT;
    }
    return c;
}

main(){
    yyparse();
    return 1;
}