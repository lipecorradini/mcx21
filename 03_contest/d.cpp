#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD;

#define MAX_N 50 // increase this if needed

struct Matrix {
    int mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b, int size) { // O(m^3), but O(1) as n = 2
    Matrix ans;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < size; k++) {
                ans.mat[i][j] += ((a.mat[i][k] % MOD) * 1LL * (b.mat[k][j] % MOD)) % MOD;
                ans.mat[i][j] %= MOD;
            }
        }
    return ans;
}

Matrix matPow(Matrix base, int n, int size) { // O(m^3 log n), but O(log n) as m = 2
    
    Matrix ans;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix

    while (n > 0) { // iterative version of Divide & Conquer exponentiation
        if (n % 2) // check if n is odd
            ans = matMul(ans, base, size);
        base = matMul(base, base, size); // square the base
        n /= 2; // divide n by 2
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Matrix ans; // special matrix for Fibonacci
        int m; long long n;

        cin >> m >> n;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> ans.mat[i][j];
            }
        }
        MOD = 1e9 + 7;

        ans = matPow(ans, n, m); // O(log n)

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cout << ans.mat[i][j] << " ";
            }
            cout << endl;
        }
        // cout << endl;
    }
    return 0;
}
