#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;

#define MAX_N 2 // increase this if needed

#define size 2
struct Matrix {
    int mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b) { // O(m^3), but O(1) as n = 2
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

Matrix matPow(Matrix base, unsigned long long n) { // O(m^3 log n), but O(log n) as m = 2
    
    Matrix ans;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix

    while (n > 0) { // iterative version of Divide & Conquer exponentiation
        if (n % 2) // check if n is odd
            ans = matMul(ans, base);
        base = matMul(base, base); // square the base
        n /= 2; // divide n by 2
    }
    return ans;
}

int main() {

    Matrix ans; // special matrix for Fibonacci

    unsigned long long n; cin >> n;
    if(n == 0) cout << 1;
    else{
        ans.mat[0][0] = 3; ans.mat[0][1] = 1;
        ans.mat[1][0] = 1; ans.mat[1][1] = 3;

        ans = matPow(ans, n-1);

        int resp = (((ans.mat[0][0]) * 1LL * 3)%MOD + ans.mat[1][0]%MOD)%MOD;

        cout << resp << endl;
    }
    
    
    return 0;
}
