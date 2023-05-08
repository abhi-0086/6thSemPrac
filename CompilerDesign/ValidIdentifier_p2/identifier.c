#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int i = 0, flag = 0;
    char keyw[10][10] = {"int", "float", "break", "long", "char", "for", "if", "switch", "else", "while"};
    char a[10];
    printf("Enter Identifier: ");
    scanf("%s", a);
    for (i = 0; i < 10; i++)
    {
        if ((strcmp(keyw[i], a) == 0))
            flag = 1;
    }
    if (flag == 1)
        printf("\n %s is Keyword", a);
    else
    {
        if (a[0] == '_' || isalpha(a[0]) != 0)
        {
            for (i = 1; a[i] != '\0'; i++)
            {
                if (isalnum(a[i]) == 0 && a[i] != '_')
                    flag = 1;
            }
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
        printf("\n %s is an Identifier.", a);
    else
        printf("\n %s is not an identifier,", a);
    return 0;
}
// ouput
// enter Identiifer: myVariable
