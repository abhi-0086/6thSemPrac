#include <stdio.h> // standard input/output header file
#include <stdlib.h> // standard library header file
#include <unistd.h> // UNIX standard header file
#include <sys/times.h> // system times header file
#include <time.h> // time header file, used for time related functions

static void showtimes(void) // define a static function "showtimes"
{
    time_t time1, time2; // declare two variables of type "time_t"
    time_t time_dif; // declare a variable of type "time_t"

    time1 = time(NULL); // set "time1" to current time in seconds

    printf("time1 : %ld",time1); // print the value of "time1"

    sleep(5); // suspend execution of the calling thread for 5 seconds

    time2 = time(NULL); // set "time2" to current time in seconds
    printf("\ntime2 : %ld",time2); // print the value of "time2"

    time_dif = difftime(time2,time1); // calculate the time difference between "time2" and "time1"
    printf("\nthe showtime slept for: %ld seconds\n",time_dif); // print the time difference
}

int main(void)
{
    if (atexit(showtimes)) // register "showtimes" function to be called when program exits
    {
        fprintf(stderr, "Failed to install showtimes exit handler\n"); // print error message if registration fails
        return 1; // return error code
    }

    /* rest of main program goes here */

    return 0; // return success code
}
