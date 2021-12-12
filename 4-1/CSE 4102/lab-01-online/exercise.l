%{
    #include <stdio.h>
%}

%%
(B|R|K|C)UET[ ](CS|EE|M|C)E[ ]1(6-9) {
    printf("Matched\n");
}
.* {
    printf("Invalid\n");
}
%%

int main(){
    yylex();
}