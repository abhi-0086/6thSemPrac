#include<pwd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<signal.h>
#include<time.h>
#include<error.h>
#include<ctype.h>

main()
{
    char u_name[10]; // variable to hold the username entered by user
    char ch; // variable to hold the user's choice of input
    uid_t u_id; // variable to hold the user ID entered by user
    struct passwd *p; // pointer to the passwd structure
    
    printf("Enter Your Choice\n");
    printf("Whether you want to enter UNAME or UID?(N or I)"); // prompt user for choice of input
    scanf("%c",&ch); // read the user's choice
    
    if((ch == 'N')|| (ch == 'n')) // if user chooses to enter username
    {
        printf("Enter UNAME");
        scanf("%s",u_name); // read the username entered by user
        p=getpwnam(u_name); // get the passwd structure for the given username
        printf("\n%s\n %s\n %d\n %d\n %s\n %s\n %s\n", p->pw_name, p->pw_passwd, p->pw_uid,p->pw_gid,p->pw_gecos, p->pw_dir, p->pw_shell); // print the information retrieved from passwd structure
    }
    else if((ch == 'I' || 'i')) // if user chooses to enter user ID
    {
        printf("Enter UID");
        scanf("%d",&u_id); // read the user ID entered by user
        p= getpwuid (u_id); // get the passwd structure for the given user ID
        printf("\n%s\n %s\n %d\n %d\n %s\n %s\n %s\n", p->pw_name, p->pw_passwd, p->pw_uid,p->pw_gid,p->pw_gecos, p->pw_dir, p->pw_shell); // print the information retrieved from passwd structure
    }
    else
        printf("Wrong Choice"); // if user enters a wrong choice
}
