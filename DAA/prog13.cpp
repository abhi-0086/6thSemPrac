//program 13 - Matrix Chain multiplication

#include<bits/stdc++.h>
using namespace std;

// Function to find the minimum number of scalar multiplications required to
// multiply the given sequence of matrices
void matrixChainOrder(int p[], int n) {
    int m[n][n]; // to store the minimum number of scalar multiplications
    int s[n][n]; // to store the optimal split position
    for (int i = 1; i < n; i++) {
        m[i][i] = 0; // a single matrix requires no multiplication
    }
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1; // set the end index of current subsequence
            m[i][j] = INT_MAX; // initialize to maximum value
            for (int k = i; k <= j - 1; k++) {
                // calculate the number of scalar multiplications required
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    // update the minimum number of scalar multiplications
                    m[i][j] = q;
                    // record the optimal split position
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of scalar multiplications: " << m[1][n - 1] << endl;
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[n + 1]; // to store the dimensions of the matrices
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i < n + 1; i++) {
        cin >> p[i];
    }
    matrixChainOrder(p, n + 1); // find the minimum number of scalar multiplications
    return 0;
}
