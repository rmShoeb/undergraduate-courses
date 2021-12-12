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
	// #typedef float YYSTYPE;
%}
/**
    yacc declarations, e.g: tokens
    %left -> left associativity
    %right -> right associativity
    %nonassoc -> non-assosiativity
**/
%token DIGIT
%left '+' '-'
%left '*' '/'
%left '(' ')'

/**
    Rules section
**/
%%
start: expr '\n'	{
		printf("%d\n", $$);
		exit(1);
	}
    ;
expr: expr '+' expr	{
		$$=$1+$3;
		printf("%d\n", $1);
		printf("%d\n", $2);
		printf("%d\n", $3);
	}
	| expr '-' expr	{
		$$=$1-$3;
	}
    | expr '*' expr	{
		$$=$1*$3;
	}
	| expr '/' expr	{
		$$=$1/$3;
	}
    | '(' expr ')'	{
		$$=$2;
	}
    | DIGIT			{
		$$=$1;
	}
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