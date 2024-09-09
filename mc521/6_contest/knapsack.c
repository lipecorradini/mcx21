#include <stdio.h>
#include <string.h>

int z[2001][2001];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int w[], int c[], int n) {
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) 
                z[i][j] = 0;
            else if (w[i - 1] <= j)
                z[i][j] = max(c[i - 1] + z[i - 1][j - w[i - 1]], z[i - 1][j]);
            else
                z[i][j] = z[i - 1][j];
        }
    }
    return z[n][W];
}

int main() {

    int s, n;
    scanf("%d %d", &s, &n);

    int W = s; // knapsack capacity
    int c[n]; // item costs
    int w[n]; // item weights
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &w[i], &c[i]);
    }

    memset(z, 0, (n + 1) * (s + 1) * sizeof(int)); 
    printf("%d\n", knapSack(W, w, c, n));
    return 0;
}
