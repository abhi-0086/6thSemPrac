#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pro[10][10], first[10][10], follow[10][10], nt[10], ter[10], res[10][10][10], temp[10];
    int npro, noter = 0, nont = 0, i, j, k, flag = 0, count[10][10], row, col, l, m, n, index;

    // Initialize count and res arrays
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            count[i][j] = 0;
            for (k = 0; k < 10; k++) {
                res[i][j][k] = '\0';
            }
        }
    }

    printf("Enter the number of productions: ");
    scanf("%d", &npro);
    printf("Enter the productions: ");
    for (i = 0; i < npro; i++) {
        scanf("%s", pro[i]);
    }

    // Find non-terminals
    for (i = 0; i < npro; i++) {
        flag = 0;
        for (j = 0; j < nont; j++) {
            if (nt[j] == pro[i][0])
                flag = 1;
        }
        if (flag == 0) {
            nt[nont] = pro[i][0];
            nont++;
        }
    }

    printf("\nEnter the first values:\n");
    for (i = 0; i < nont; i++) {
        printf("First value(%c): ", nt[i]);
        scanf("%s", first[i]);
    }

    printf("\nEnter the follow values:\n");
    for (i = 0; i < nont; i++) {
        printf("Follow values(%c): ", nt[i]);
        scanf("%s", follow[i]);
    }

    // Find terminals
    for (i = 0; i < nont; i++) {
        flag = 0;
        for (j = 0; j < strlen(first[i]); j++) {
            for (k = 0; k < noter; k++) {
                if (ter[k] == first[i][j])
                    flag = 1;
            }
        }
        if (flag == 0) {
            if (first[i][j] != '#') {
                ter[noter] = first[i][j];
                noter++;
            }
        }
    }

    // Find terminals in follow
    for (i = 0; i < nont; i++) {
        flag = 0;
        for (j = 0; j < strlen(follow[i]); j++) {
            for (k = 0; k < noter; k++) {
                if (ter[k] == follow[i][j])
                    flag = 1;
            }
            if (flag == 0) {
                ter[noter] = follow[i][j];
                noter++;
            }
        }
    }

    // Construct parsing table
    for (i = 0; i < nont; i++) {
        for (j = 0; j < strlen(first[i]); j++) {
            flag = 0;
            if (first[i][j] == '#') {
                col = i;
                for (m = 0; m < strlen(follow[col]); m++) {
                        for (l = 0; l < noter; l++) {
                        if (ter[l] == follow[col][m]) {
                            row = 1;
                        }
                    }
                    temp[0] = nt[col];
                    temp[1] = '_';
                    temp[2] = '>';
                    temp[3] = '#';
                    temp[4] = '\0';
                    printf("temp %s", temp);
                    strcpy(res[col][row], temp);
                    count[col][row] += 1;
                    for (k = 0; k < 10; k++) {
                        temp[k] = '\0';
                    }
                }
            } else {
                for (l = 0; l < noter; l++) {
                    if (ter[l] == first[i][j]) {
                        row = 1;
                    }
                }
                for (k = 0; k < npro; k++) {
                    if (nt[i] == pro[k][0]) {
                        col = i;
                        if (pro[k][3] == first[i][j] && pro[k][0] == nt[col]) {
                            strcpy(res[col][row], pro[k]);
                            count[col][row] += 1;
                        } else {
                            if (isupper(pro[k][3]) && pro[k][0] == nt[col]) {
                                flag = 0;
                                for (m = 0; m < nont; m++) {
                                    if (nt[m] == pro[k][3]) {
                                        index = m;
                                        flag = 1;
                                    }
                                }
                                if (flag == 1) {
                                    for (m = 0; m < strlen(first[index]); m++) {
                                        if (first[i][j] == first[index][m]) {
                                            strcpy(res[col][row], pro[k]);
                                            count[col][row] += 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    flag = 0;
    for (j = 0; j < nont; j++) {
        for (k = 0; k < noter; k++) {
            if (count[j][k] > 1) {
                flag = 1;
            }
        }
    }

    if (flag == 1) {
        printf("\nThe given grammar is not LL(1).");
    } else {
        printf("\nThe given grammar is LL(1).");
    }

    return 0;
}
