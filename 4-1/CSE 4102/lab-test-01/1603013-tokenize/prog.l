%option noyywrap

%{
    #include <stdio.h>
    /**
    * Roll No: 1603013
    * Question-1
    * int a[10] = {0};
    **/
%}

delim [ \t\n]
ws {delim}+
digit [0-9]
number ({digit}+|{digit}*[.]{digit}+)
letter [A-Za-z]
us [_]
id ({us}|{letter})({letter}|{us}|{digit})*

%%
{ws} {}

{number} {
    ECHO;
    printf(" NUM\n");
}

"int"|"float"|"double" {
    ECHO;
    printf(" TYPE\n");
}
{id} {
    ECHO;
    printf(" ID\n");
}

"=" {
    ECHO;
    printf(" ASSIGN\n");
    // return(ASSIGN);
}
";" {
    ECHO;
    printf(" SEMI\n");
    // return(SEMI);
}

"(" {
    ECHO;
    printf(" LP\n");
}
")" {
    ECHO;
    printf(" RP\n");
}
"{" {
    ECHO;
    printf(" LB\n");
}
"}" {
    ECHO;
    printf(" RB\n");
}
"[" {
    ECHO;
    printf(" LSB\n");
}
"]" {
    ECHO;
    printf(" RSB\n");
}
%%

int main(){
    yylex();
    return 0;
}