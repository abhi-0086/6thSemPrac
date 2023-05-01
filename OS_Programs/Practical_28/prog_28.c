#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>

void sig_hand(int); // declaration of signal handler function

main()
{
    int i=1;
    pid_t pid;
    if(signal(SIGALRM,sig_hand)==SIG_ERR) // register the signal handler
    {
        printf("Not Registered");
    }
    while(i<=5) // loop to send signals after 2 seconds delay
    {
        i++;
        pid=getpid();
        sleep(2); // wait for 2 seconds
        kill(pid,SIGALRM); // send the signal
    }
}

void sig_hand(int sig)
{
    struct tm *t; // structure to hold the broken-down time
    time_t tt; // variable to hold the time in seconds
    if(sig==SIGALRM) // check if the received signal is SIGALRM
    {
        tt=time(NULL); // get the current time in seconds since epoch
        t=localtime(&tt); // convert the time to broken-down time
        printf("%d\n",t->tm_sec); // print the seconds field of the time
    }
}
