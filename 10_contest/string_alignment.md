```c++

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    // Needleman-Wunsch’s algorithm
    char P[20] = "ACAATCC";
    char Q[20] = "AGCATGC";
    int n = static_cast<int>(strlen(P));
    int m = static_cast<int>(strlen(Q));
    int table[20][20] = {0};

    // insert/delete = -1 point
    for (int i = 1; i <= n; i++) table[i][0] = i * -1;
    for (int j = 1; j <= m; j++) table[0][j] = j * -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // match = 2 points, mismatch = -1 point
            table[i][j] = table[i - 1][j - 1] + (P[i - 1] == Q[j - 1] ? 2 : -1);

            // gap = -1 point
            table[i][j] = max(table[i][j], table[i - 1][j] - 1); // delete character from P
            table[i][j] = max(table[i][j], table[i][j - 1] - 1); // delete character from Q
        }
    }

    // Print DP table
    cout << "DP table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << setw(3) << table[i][j] << " ";
        }
        cout << endl;
    }

    // Print maximum alignment score
    cout << "Maximum Alignment Score: " << table[n][m] << endl;

    return 0;
}

```
