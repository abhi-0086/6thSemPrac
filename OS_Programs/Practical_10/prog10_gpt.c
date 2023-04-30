#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int n, i; 
  pid_t pid;

  // check if the number of command line arguments is correct
  if (argc != 2) {
    printf("Usage: %s n\n", argv[0]);
    exit(1);
  }

  // convert the command line argument to an integer
  n = atoi(argv[1]);

  // create the chain of n processes
  for (i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
        printf("Error: fork failed\n");
        exit(1);
        }
        if (pid == 0) {
        printf("Child process %d created, with parent process %d\n", getpid(), getppid());
        while (getppid() != 1);
        printf("Child process %d has completed, with parent process %d\n", getpid(), getppid());
        exit(0);
        }
  }
//   // parent process
//   printf("Parent process exiting\n");
  exit(0);
}
