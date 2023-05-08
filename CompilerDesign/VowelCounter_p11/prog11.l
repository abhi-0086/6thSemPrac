%{
int vowel_count = 0;
%}

%%
[aeiouAEIOU]    { vowel_count++; }
.               { /* Ignore other characters */ }
\n              { return vowel_count; }
%%

int main() {
    yylex();
    printf("Total number of vowels: %d\n", vowel_count);
    return 0;
}
