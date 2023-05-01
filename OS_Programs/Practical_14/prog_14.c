/*DEFUNCT MEANS ZOMBIE
Zombie process is a process that has terminated, but whose parent
has not yet waited for it. So parent's parent will become parent of
this process
Also remember if parent process dies before child process then init
process (process id = 1) becomes the parent of the executing child
process*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
main()
{
    int fd;

    // Creating a child process using fork()
    if((fd=fork())<0)
    {
        printf("error in creating child");
        exit(1);
    }

    // Child process code: send a signal to itself to terminate
    if(fd==0)
        kill(getpid(),SIGKILL);

    // Parent process code: wait for 2 seconds
    else
        sleep(2);

    // Print process information using the "ps" command
    system("ps -f");
}
