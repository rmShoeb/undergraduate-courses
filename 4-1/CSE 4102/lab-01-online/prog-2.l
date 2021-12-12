%{
    //declaration
    #include <stdio.h>
%}

%%
//translation rules
[A-Za-z] { printf("%s is letter\n", yytext); }
[0-9] { printf("%s is a digit\n", yytext) }
. { printf("No match\n"); }
%%

int yywrap(){

}

int main(){
    yylex();
}
