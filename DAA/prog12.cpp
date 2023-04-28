//program 12 - Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

// Function to find the length of longest common subsequence
int lcs(string X, string Y, int m, int n){

    int L[m + 1][n + 1];  // Create a 2D array to store the LCS lengths

    // Loop through the two strings
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If one of the strings is empty, then there can be no common subsequence
            if (i == 0 || j == 0)
                L[i][j] = 0;

            // If the last characters of the two strings match, then the length of LCS is 1 + LCS of the remaining strings
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            // If the last characters of the two strings do not match, then the LCS is the maximum of LCS of the two strings with the last character removed
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];  // Return the length of LCS
}

int main()
{
    string X, Y;  // Declare two string variables for user input

    cout << "Enter first string: ";
    getline(cin, X);  // Read the first string from user input

    cout << "Enter second string: ";
    getline(cin, Y);  // Read the second string from user input

    int m = X.length();  // Length of first string
    int n = Y.length();  // Length of second string

    cout << "Length of LCS is " << lcs(X, Y, m, n) << endl;  // Call the lcs() function and print the result

    return 0;  // Exit the program
}
