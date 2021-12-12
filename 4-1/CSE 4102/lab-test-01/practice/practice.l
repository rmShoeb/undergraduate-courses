%option noyywrap

%{
    #include "practice.tab.h"
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

"main" {
    printf("MAIN\n");
    return (MAIN);
}
"if" {
    printf("IF\n");
    return(IF);
}
"while" {
    printf("WHILE\n");
    return (WHILE);
}

{number} {
    printf("NUM\n");
    yylval = atoi(yytext);
    return(NUM);
}

"int"|"float"|"double" {
    printf("KEYWORD\n");
    return (KEYWORD);
}
{id} {
    printf("ID\n");
    return(ID);
}

"==" {
    printf("EQUAL\n");
    return(EQUAL);
}
"=" {
    printf("ASSIGN\n");
    return(ASSIGN);
}
";" {
    printf("SEMI\n");
    return(SEMI);
}

"+" {
    printf("ADD\n");
    return(ADD);
}
"-" {
    printf("SUB\n");
    return(SUB);
}

"(" {
    printf("LP\n");
    return(LP);
}
")" {
    printf("RP\n");
    return(RP);
}

"{" {
    printf("LB\n");
    return(LB);
}
"}" {
    printf("RB\n");
    return(RB);
}
%%

// int main(){
//     yylex();
//     return 0;
// }