#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a given identifier is valid
bool isValidIdentifier(const char *identifier) {
    // Check the first character of the identifier
    if (!isalpha(identifier[0]) && identifier[0] != '_')
        return false;

    // Check the remaining characters of the identifier
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_')
            return false;
    }

    // If all checks pass, the identifier is valid
    return true;
}

int main() {
    char identifier[100];
    
    // Read the identifier from the user
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    // Check if the identifier is valid
    if (isValidIdentifier(identifier))
        printf("The identifier '%s' is valid.\n", identifier);
    else
        printf("The identifier '%s' is not valid.\n", identifier);

    return 0;
}
