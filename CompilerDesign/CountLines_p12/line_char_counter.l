%{
int line_count = 0;
int char_count = 0;
%}

%%
\n      { line_count++; }   // Increment line count on newline character
.       { char_count++; }  // Increment character count for all other characters
%%

int main() {
    yylex();
    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", char_count);
    return 0;
}


/*
flex line_char_counter.l 
cc lex.yy.c -o line_char_counter -lfl
./line_char_counter
*/