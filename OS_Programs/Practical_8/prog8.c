#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // Print the real user ID of the current process
    printf("My real user ID is %5ld\n", (long)getuid());
    
    // Print the effective user ID of the current process
    printf("My effective user ID is %5ld\n", (long)geteuid());
    
    // Print the real group ID of the current process
    printf("My real group ID is %5ld\n", (long)getgid());
    
    // Print the effective group ID of the current process
    printf("My effective group ID is %5ld\n", (long)getegid());
    
    return 0;
}
