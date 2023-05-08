%{
#include <stdio.h>

int positiveCount = 0;
int negativeCount = 0;
int positiveFractionCount = 0;
int negativeFractionCount = 0;
%}

%%
[+-]?[0-9]+          { /* Positive or negative integer */
                        if (atoi(yytext) > 0)
                            positiveCount++;
                        else if (atoi(yytext) < 0)
                            negativeCount++;
                    }
[+-]?[0-9]+\.[0-9]+  { /* Positive or negative fraction */
                        if (atof(yytext) > 0)
                            positiveFractionCount++;
                        else if (atof(yytext) < 0)
                            negativeFractionCount++;
                    }
.|\n                ; /* Ignore any other characters */
%%

int main() {
    yylex();
    printf("Positive Numbers: %d\n", positiveCount);
    printf("Negative Numbers: %d\n", negativeCount);
    printf("Positive Fractions: %d\n", positiveFractionCount);
    printf("Negative Fractions: %d\n", negativeFractionCount);
    return 0;
}



/*
OUTPUT TERMINAL COMMANDS
flex count_pos_neg.l
cc lex.yy.c -o count_pos_neg -lfl
 ./count_pos_neg
*/