// Client

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

#define FIFOARG 1 // Argument index for the name of the server FIFO.

int main(int argc, char *argv[])
{
    time_t curtime;
    int len;
    char requestbuf[_PC_PIPE_BUF];
    int requestfd;
    if (argc != 2)
    { // Check if the argument count is correct.
        fprintf(stderr, "Usage: %s fifoname\n", argv[0]);
        return 1;
    }
    // Open the FIFO for writing.
    if ((requestfd = open(argv[FIFOARG], O_WRONLY)) == -1)
    {
        perror("Client failed to open log fifo for writing");
        return 1;
    }

    // Get the current time and format the message to be sent to the server.
    curtime = time(NULL);
    snprintf(requestbuf, _PC_PIPE_BUF, "%d: %s", (int)getpid(), ctime(&curtime));
    len = strlen(requestbuf);

    // Write the message to the server and check for errors.
    if (write(requestfd, requestbuf, len) != len)
    {
        perror("Client failed to write");
        return 1;
    }
    // Close the FIFO.
    close(requestfd);
    return 0;
}
