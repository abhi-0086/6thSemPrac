%option noyywrap

%{
#include <stdio.h>
int line_count = 0;
int char_count = 0;
%}

%%
\n    { line_count++; }
.     { char_count++; }
%%

int main() {
    char input[1000];
    printf("Enter your input (Press Ctrl+D to indicate end of input):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        yy_scan_string(input);
        yylex();
    }
    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", char_count);
    return 0;
}
