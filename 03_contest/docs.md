## Potência de uma variável O(log(n))

```
typedef long long ll;

ll potencia2(ll x, ll p) {
    ll aux;
    if (p == 0)
        return 1;
    else if (p % 2 == 0) {
        aux = potencia2(x, p / 2);
        return aux * aux;
    } else {
        aux = potencia2(x, (p - 1) / 2);
        return x * aux * aux;
    }
}

```

## Calculando n-ésimo Fibonacci com Matrizes


```
typedef long long ll;
ll MOD;

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
                ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
                ans.mat[i][j] %= MOD;
            }
        }
    return ans;
}

Matrix matPow(Matrix base, int n) { // O(m^3 log n), but O(log n) as m = 2
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
    int n, p;
    while (cin >> n >> p) {
        Matrix ans; // special matrix for Fibonacci
        ans.mat[0][0] = 1; ans.mat[0][1] = 1;
        ans.mat[1][0] = 1; ans.mat[1][1] = 0;

        MOD = 1;
        for (int i = 0; i < p; i++) // set MOD = 2^p
            MOD *= 2;

        ans = matPow(ans, n); // O(log n)
        cout << ans.mat[0][1] << endl; // this is fib(n)
    }
    return 0;
}

```