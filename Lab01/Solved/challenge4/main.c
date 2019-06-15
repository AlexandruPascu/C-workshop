#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(int **img, int i, int j, int *sum) {
    if (img[i][j] != 1) {
        return;
    }
    img[i][j] = -1;
    ++(*sum);
    fill(img, i+1, j, sum);
    fill(img, i-1, j, sum);
    fill(img, i, j+1, sum);
    fill(img, i, j-1, sum);
}

int main() {
    int n, m, maxSum = 0;
    int **img;
    FILE *in = fopen("challenge4.txt", "r");
    fscanf(in, "%d %d", &n, &m);
    img = (int**) malloc((n+2) * sizeof(int*));
    for (int i = 0; i < n + 2; i++) {
        img[i] = malloc((m + 2) * sizeof(int));
    }
    for (int i = 0; i < m + 2; ++i) {
        img[0][i] = img[n+1][i] = -1;
    }
    for (int i = 0; i < n+1; ++i) {
        img[i][0] = img[i][m+1] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fscanf(in, "%d", &img[i][j]);
            if (img[i][j] != 0 && img[i][j] != 1) {
                exit(-1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (img[i][j] == 1) {
                int sum = 0;
                fill(img, i, j, &sum);
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }
    free(img);
    printf("Maximum Area: %d\n", maxSum);
    fclose(in);
    return 0;
}
