#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

// foi utilizado como base o codigo passado pelo professor no slide

ll MOD = 1e9 + 7;

#define MAX_N 2 // increase this if needed

struct Matrix {
    ll mat[MAX_N][MAX_N]; // to let us return a 2D array
};

Matrix matMul(Matrix a, Matrix b) { // O(m^3), but O(1) as n = 2
    Matrix ans;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < MAX_N; k++) {
                ans.mat[i][j] ^= ((a.mat[i][k] % MOD) * 1LL * (b.mat[k][j] % MOD)) % MOD;
            }
        }
    return ans;
}

Matrix matPow(Matrix base, unsigned long long n) { // O(m^3 log n), but O(log n) as m = 2
    Matrix ans;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix

    while (n > 0) { // iterative version of Divide & Conquer exponentiation
        if (n % 2) // check if n is odd
            ans = matMul(ans, base); // update ans
        base = matMul(base, base); // square the base
        n /= 2; // divide n by 2
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t --){
        int a, b, n;

        cin >> a >> b >> n;
        long long c = a ^ b;
        int vec[3];
        vec[0] = a;
        vec[1] = b;
        vec[2] = c;

        int num = n % 3;

        cout << vec[num] << endl;


    }
    
    return 0;
}