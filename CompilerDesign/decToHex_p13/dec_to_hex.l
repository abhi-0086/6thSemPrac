%{
#include <stdio.h>
%}

%%
[0-9]+   { 
            int decimal = atoi(yytext);
            printf("%d in hexadecimal: 0x%X\n", decimal, decimal);
            fprintf(yyout, "%d in hexadecimal: 0x%X\n", decimal, decimal);
         }
.        ;

%%

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./decimal_to_hexadecimal <input_file> <output_file>\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (!input_file) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    if (!output_file) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }

    yyin = input_file;
    yyout = output_file;

    yylex();

    fclose(input_file);
    fclose(output_file);

    return 0;
}




/*
OUTPUT TERMINAL COMMANDS

flex dec_to_hex.l
cc lex.yy.c -o dec_to_hex -lfl
./dec_to_hex input.txt output.txt
*/
