%{
    //declaration
    #include <stdio.h>
%}

letter [A-Za-z]
digit [0-9]

%%
("_"|{letter})({letter}|{digit}|"_")* {printf("%s is identifier\n", yytext);}
. { printf("No match\n"); }
%%

int yywrap(){

}

int main(){
    yylex();
}
