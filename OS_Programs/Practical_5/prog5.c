#include <stdio.h>      // Standard Input/Output library
#include <stdlib.h>     // Standard library
#include <errno.h>      // Error handling library
#include <sys/resource.h>    // System resource limits library

#define NUM_RESOURCES RLIM_NLIMITS   // Define a constant to represent the number of system resources available

int main() {
    struct rlimit rl;   // Declare a structure to hold the resource limits
    int i;
    char* resource_names[NUM_RESOURCES] = {   // Declare an array of strings to hold the names of the system resources
        "RLIMIT_CPU",
        "RLIMIT_FSIZE",
        "RLIMIT_DATA",
        "RLIMIT_STACK",
        "RLIMIT_CORE",
        "RLIMIT_RSS",
        "RLIMIT_NPROC",
        "RLIMIT_NOFILE",
        "RLIMIT_MEMLOCK",
        "RLIMIT_AS",
        "RLIMIT_LOCKS"
    };

    // Print the header row for the output table
    printf("\n%-15s\t%-15s\t%-15s\n", "Resource Name", "Soft Limit", "Hard Limit");

    // Loop through each system resource and retrieve its limits
    for (i = 0; i < NUM_RESOURCES; i++) {
        if (getrlimit(i, &rl) != 0) {   // Get the limits for the current system resource
            perror("getrlimit");    // Print an error message if the limits cannot be retrieved
            exit(EXIT_FAILURE);     // Exit the program with an error code
        }
        // Print the resource name and its corresponding soft and hard limits
        printf("%-15s\t%-15lld\t%-15lld\n", resource_names[i], (long long) rl.rlim_cur, (long long) rl.rlim_max);
    }

    return 0;   // Return 0 to indicate success
}
