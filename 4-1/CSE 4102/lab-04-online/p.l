%option noyywrap

%{
    #include "p.tab.h"
%}

delim [ \t\n]
whitespace {delim}+
digit [0-9]
number {digit}+
letter [A-Za-z]
underscore [_]
identifier ({underscore}|{letter})({letter}|{digit}|{underscore})*

%%
"if" {
    return IF;
}

{whitespace} {}
{number} {
    // printf("%s number\n", yytext);
    yylval = atoi(yytext);
    return NUM;
}
{identifier} {
    return IDENTIFIER;
}

"==" {
    return EQUALITY;
}

"{" {
    return LB;
}
"}" {
    return RB;
}
"(" {
    return LP;
}
")" {
    return RP;
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
    return SEMICOLON;
}
%%
