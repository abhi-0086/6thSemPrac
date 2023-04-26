//program 11 - Strassen Multiplication Algo

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_add(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrix_subtract(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // split matrices into submatrices
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // calculate 7 products using recursion
    vector<vector<int>> P1 = strassen(matrix_add(A11, A22), matrix_add(B11, B22));
    vector<vector<int>> P2 = strassen(matrix_add(A21, A22), B11);
    vector<vector<int>> P3 = strassen(A11, matrix_subtract(B12, B22));
    vector<vector<int>> P4 = strassen(A22, matrix_subtract(B21, B11));
    vector<vector<int>> P5 = strassen(matrix_add(A11, A12), B22);
    vector<vector<int>> P6 = strassen(matrix_subtract(A21, A11), matrix_add(B11, B12));
    vector<vector<int>> P7 = strassen(matrix_subtract(A12, A22), matrix_add(B21, B22));

    // calculate submatrices of result matrix
    vector<vector<int>> C11(mid, vector<int>(mid));
    vector<vector<int>> C12(mid, vector<int>(mid));
    vector<vector<int>> C21(mid, vector<int>(mid));
    vector<vector<int>> C22(mid, vector<int>(mid));
    C11 = matrix_add(matrix_subtract(matrix_add(P1, P4), P5), P7);
    C12 = matrix_add(P3, P5);
    C21 = matrix_add(P2, P4);
    C22 = matrix_add(matrix_add(matrix_subtract(P1, P2), P3), P6);

    // combine submatrices into result matrix
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    return C;
}

int main() {
int n;
cout << "Enter the size of the matrix: ";
cin >> n;
vector<vector<int>> A(n, vector<int>(n));
vector<vector<int>> B(n, vector<int>(n));
cout << "Enter elements of matrix A: " << endl;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> A[i][j];
    }
}
cout << "Enter elements of matrix B: " << endl;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> B[i][j];
    }
}
vector<vector<int>> C = strassen(A, B);

cout << "Result matrix C: " << endl;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << C[i][j] << " ";
    }
    cout << endl;
}
return 0;
}
