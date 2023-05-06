#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

// Declare global variables
int n=0,m=0,p,i=0,j=0;
char a[10][10],f[10];

void first(char c);
void follow(char c);

// Function to calculate the FIRST set of a non-terminal symbol
void first(char c) {
    int k;
    if(!isupper(c))  // if the symbol is a terminal, add it to the FIRST set
        f[m++] = c;
    for(k=0;k<n;k++) {
        if(a[k][0] == c) {  // if the production rule starts with the symbol c
            if(a[k][2] == '$')  // if the production rule has an epsilon as the second symbol
                follow(a[k][0]);  // add the FOLLOW set of the symbol on the left side of the production rule to its FIRST set
            else if(islower(a[k][2]))  // if the second symbol is a lowercase terminal
                f[m++] = a[k][2];  // add it to the FIRST set
            else first(a[k][2]);  // if the second symbol is a non-terminal, calculate its FIRST set recursively
        }
    }
}

// Function to calculate the FOLLOW set of a non-terminal symbol
void follow(char c) {
    if(a[0][0] == c)  // if c is the starting symbol, add $ to its FOLLOW set
        f[m++] = '$';
    for(i=0;i<n;i++) {
        for(j=2;j<strlen(a[i]);j++) {
            if(a[i][j] == c) {  // if c is found in the right-hand side of a production rule
                if(a[i][j+1] != '\0')  // if there are symbols after c in the production rule
                    first(a[i][j+1]);  // add their FIRST set to c's FOLLOW set
                if(a[i][j+1] == '\0' && c != a[i][0])  // if c is the last symbol in the production rule and it's not the left-hand side of the rule
                    follow(a[i][0]);  // add the FOLLOW set of the left-hand side of the production rule to c's FOLLOW set
            }
        }
    }
}

// Main function
int main() {
    int i,z;
    char c,ch;
    printf("Enter the number of productions: ");
    scanf("%d",&n);
    printf("\nEnter the productions: \n");
    for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);
    do {
        m=0;  // reset the size of the FIRST and FOLLOW sets
        printf("\nEnter the symbol whose FIRST and FOLLOW sets are to be found: ");
        scanf("%c",&c);
        first(c);
        printf("First(%c) = {",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        strcpy(f,"");  // reset the string containing the FOLLOW set
        m=0;  // reset the size of the FOLLOW set
        follow(c);
        printf("Follow(%c)={",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        printf("Continue(0/1) ?");
        scanf("%d%c",&z,&ch);
    } while(z==1);
    return 0;
}
