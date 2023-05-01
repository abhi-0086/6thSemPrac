#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_alrm(int); // declaration of signal handler function

main(int argc, char *argv[])
{
    // register signal handler for SIGALRM
    if((signal(SIGALRM, sig_alrm))==SIG_ERR)
        printf("Not Registered");

    // set a timer for 5 seconds using alarm()
    alarm(5);

    // pause the program until a signal is received
    pause();
}

// implementation of signal handler function
void sig_alrm(int sig)
{
    // check if the signal received is SIGALRM
    if(sig==SIGALRM)
        printf("Wake Up");
}
