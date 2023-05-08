%{
int n = 0;
%}

%%

"while"|"if"|"else" {
    n++;
    printf("\t Keywords: %s", yytext);
}

"int"|"float" {
    n++;
    printf("\t Keywords: %s", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    n++;
    printf("\t identifier: %s", yytext);
}

"<="|">="|"<"|">"|"=="|"="|"++"|"--"|"-"|"*"|"+"|"/" {
    n++;
    printf("\t operator: %s", yytext);
}

[(){}|,;] {
    n++;
    printf("\t separator: %s", yytext);
}

[0-9]*"."[0-9]+ {
    n++;
    printf("\t float: %s", yytext);
}

[0-9]+ {
    n++;
    printf("\t integer: %s", yytext);
}

.;

%%

int main() {
    yylex();
    printf("\n Total number of tokens = %d\n", n);
}




/*
OUTPUT TERMINAL COMMANDS
flex countTokens.l
cc lex.yy.c -o countTokens -lfl
./countTokens
*/
