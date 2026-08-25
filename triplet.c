#include <stdio.h>

int main() {
    int matrix[4][4] = {
        {0, 0, 0, 5},
        {0, 8, 0, 0},
        {0, 0, 3, 0},
        {0, 6, 0, 0},
    };

    int triplet[5][3];
    int k = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    triplet[0][0] = 4;
    triplet[0][1] = 4;
    triplet[0][2] = k - 1;
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
    return 0;
}
