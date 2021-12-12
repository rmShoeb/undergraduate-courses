%{
    //declaration
    #include <stdio.h>
%}

%%
//translation rules
[A-Za-z]+ { printf("%s is a word\n", yytext); }
[0-9]+ { printf("%s is a number\n", yytext) }
. { printf("No match\n"); }
%%

int yywrap(){

}

int main(){
    yylex();
}
