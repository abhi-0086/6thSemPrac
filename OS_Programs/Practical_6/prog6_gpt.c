#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    time_t start, end; // declare two variables of type "time_t" to hold the start and end times
    start = time(NULL); // get the current time and store it in the "start" variable
    printf("Start time: %ld\n", start); // print the start time
    sleep(5); // sleep for 5 seconds
    end = time(NULL); // get the current time again and store it in the "end" variable
    printf("End time: %ld\n", end); // print the end time
    printf("Time slept: %ld seconds\n", end - start); // calculate and print the time slept
    return 0; // return success code
}
