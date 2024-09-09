#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;
#define long unsigned long long
long dice_sum_dp(long  n, int x) {
    // set up dsum (dp table)
    int mx = min(x, 6);
    vector<vector<long >> dsum(n, vector<long >(x, 0));
    
    for (int i = 0; i < mx; ++i) {
        dsum[0][i] = 1;
    }

    for (long i = 1; i < n; ++i) {
        for (int j = 1; j < x; ++j) {
            int k = 1;
            while (j - k >= 0 && k <= 6) {
                dsum[i][j] += dsum[i - 1][j - k];
                ++k;
            }
        }
    }

    return dsum[n - 1][x - 1];
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    long tot = 0;

    for (int i = a; i <= b; ++i) {
        tot += dice_sum_dp(n, i);
    }
    cout << tot << endl;
    cout << fixed << setprecision(6) << static_cast<double>(tot) / pow(6, n) << endl;

    return 0;
}
