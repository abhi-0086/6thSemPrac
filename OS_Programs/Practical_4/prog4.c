// manual code
#include <stdio.h>  //Include standard input/output library
#include <stdlib.h> //Include standard library

extern char **environ; // Declare an external variable environ of type char**

int main()
{ // Declare the main function

    char *path; // Declare a pointer variable named path of type char*
    int i;      // Declare an integer variable named i

    printf("The environment list is as follows: \n"); // Print a message on the screen

    for (i = 0; environ[i] != NULL; i++)             // For loop to traverse all the environment variables
        printf("Environ[%d] : %s\n", i, environ[i]); // Print the environment variables on the screen

    path = getenv("PATH"); // Retrieve the value of the PATH environment variable and store it in the path variable

    if ((path == NULL))                                  // Check if path is null or not
        printf("Environment variable not set\n");        // Print a message on the screen if path is null
    else                                                 // If path is not null
        printf("The value of Path variable : %s", path); // Print the value of the PATH environment variable on the screen

    return 0; // Return 0 as the program executed successfully
}
