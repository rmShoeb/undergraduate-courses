%option noyywrap

%{
    #include <stdlib.h>
    # include "cal.tab.h"
%}
delim [ \t]
ws {delim}+
digit [0-9]
number ({digit}+)
letter [A-Za-z]
us [_]
id ({us}|{letter})({letter}|{digit}|{us})*


%%
{ws} {}
{number} {
    yylval = atoi(yytext);
    return NUM;
}
"+" {
    return ADD;
}
"-" {
    return SUB;
}
"=" {
    return ASSIGN;
}
";" {
    return SEMI;
}
{id} {
    return ID;
}
%%
