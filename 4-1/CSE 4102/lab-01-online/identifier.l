%{
    //declaration
    #include <stdio.h>
%}

%%
("_"|[A-Za-z])([A-Za-z]|[0-9]|"_")* {printf("%s is identifier\n", yytext);}
. { printf("No match\n"); }
%%

int yywrap(){

}

int main(){
    yylex();
    //to add space
    //"_"|[A-Za-z])([A-Za-z]|(" ")|[0-9]|"_")*
    //"_"|[A-Za-z])([A-Za-z]|[( )]|[0-9]|"_")*
}
