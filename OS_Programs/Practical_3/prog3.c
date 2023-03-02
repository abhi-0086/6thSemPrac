#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
// included header file `stdlib.h` for exit failure and sucess macros value, `sys/utsname.h` to get system information
int main()
{
    struct utsname sys_data;
    if (uname(&sys_data) != 0) // checks if there is any error in calling uname i.e. getting system info as uname return a dtructured info of the system
    {
        fprintf(stderr, "Error calling uname\n");
        return EXIT_FAILURE; // EXIT_FAILURE is a macro defined in stdlib.h
    }
    printf("Operating System : %s\n", sys_data.sysname);
    printf("Nodename : %s\n", sys_data.nodename);
    printf("Release : %s\n", sys_data.release);
    printf("Version : %s\n", sys_data.version);
    printf("Machine : %s\n", sys_data.machine);
    return EXIT_SUCCESS; // EXIT_SUCESS is a macro defined in stdlib.h
}