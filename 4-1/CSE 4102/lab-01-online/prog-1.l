%{
    //declaration
    #include <stdio.h>
%}

%%
//translation rules
"A"|"E"|"I"|"O"|"U" { printf("Vowel found\n"); }
. { printf("Consonant found\n"); }
%%

int yywrap(){

}

int main(){
    yylex();
    //https://theholeintheace.blogspot.com/2012/11/how-to-run-lex-and-yacc-programs-on.html?m=1
}
