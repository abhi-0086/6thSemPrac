#include<grp.h>    // header file that provides access to group-related functions
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>

int main()    // the main function
{
    char g_name[10];
    gid_t gid;
    char ch;
    struct group *g;    // a pointer to a group structure
    
    printf("Enter Your Choice: \nEnter Group Name(N) \nEnter Group ID (I)\n");
    printf("Enter Choice");
    scanf("%c",&ch);    // prompts the user to enter their choice
    
    switch(ch)    // evaluates the user's choice
    {
        case 'N':
        case 'n':
            printf("Enter GNAME:");
            scanf("%s",g_name);    // reads the group name entered by the user
            g=getgrnam(g_name);    // retrieves the group information using the group name
            printf("\n %s %s %d\n", g->gr_name, g->gr_passwd, g->gr_gid);    // prints the group information
            break;
            
        case 'I':
        case 'i':
            printf("Enter GID:");
            scanf("%d",&gid);    // reads the group ID entered by the user
            g=getgrgid(gid);    // retrieves the group information using the group ID
            printf("\n %s %s %d\n", g->gr_name, g->gr_passwd, g->gr_gid);    // prints the group information
            break;
            
        default:
            printf("Wrong Choice");
    }
}
