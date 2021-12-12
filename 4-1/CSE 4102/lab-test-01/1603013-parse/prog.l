%option noyywrap

%{
    #include "prog.tab.h"
    /**
    * Roll No: 1603013
    * Question-2
    * while(myvar line =< 12.0) { if(--num == 0) { last; }}
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

"if" {
    return(IF);
}
"while" {
    return (WHILE);
}

{number} {
    yylval = atoi(yytext);
    return(NUM);
}

"myvar" {
    return (TYPE);
}
{id} {
    return(ID);
}

"==" {
    return(EQUAL);
}
"=<" {
    return (LE);
}
";" {
    return(SEMI);
}

"--" {
    return (DECREMENT);
}

"(" {
    return(LP);
}
")" {
    return(RP);
}

"{" {
    return(LB);
}
"}" {
    return(RB);
}
%%
