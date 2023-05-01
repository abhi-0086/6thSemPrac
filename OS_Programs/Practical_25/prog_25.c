//Include necessary header files
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
pid_t childpid; //Variable to hold child process ID
int fd[2]; //Array to hold read and write file descriptors

//Create pipe and fork child process
if ((pipe(fd) == -1) || ((childpid = fork()) == -1))
{
    perror("Failed to setup pipeline"); //Print error message if pipe or fork fails
    return 1;
}

//Child process for ls command
if (childpid == 0)
{
    //Redirect the standard output of child to the write end of the pipe
    if (dup2(fd[1], STDOUT_FILENO) == -1)
        perror("Failed to redirect stdout of ls");
    //Close read and write file descriptors not required by child
    else if ((close(fd[0]) == -1) || (close(fd[1]) == -1))
        perror("Failed to close extra pipe descriptors on ls");
    else
    {
        //Execute ls command with options "-l" to list files in long format
        execl("/bin/ls", "ls", "-l", NULL);
        perror("Failed to exec ls"); //Print error message if execution of ls fails
    }
    return 1;
}

//Parent process for sort command
if (dup2(fd[0], STDIN_FILENO) == -1)
    perror("Failed to redirect stdin of sort"); //Redirect the standard input of parent to the read end of the pipe
//Close read and write file descriptors not required by parent
else if ((close(fd[0]) == -1) || (close(fd[1]) == -1))
    perror("Failed to close extra pipe file descriptors on sort");
else
{
    //Execute sort command with options "-n" to sort numerically and "+4" to skip first four fields of input
    execl("/bin/sort", "sort", "-n", "+4", NULL);
    perror("Failed to exec sort"); //Print error message if execution of sort fails
}
return 1;
