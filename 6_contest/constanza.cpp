#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& memo) {
    if (n < 2) {
        return n;
    } else if (memo[n] != -1) {
        return memo[n] % static_cast<int>(1e9 + 7);
    } else {
        memo[n] = (fib(n - 1, memo) + fib(n - 2, memo)) % static_cast<int>(1e9 + 7);
        return memo[n];
    }
}

int main() {
    string word;
    cin >> word;

    vector<int> memo(10'000, -1);
    int i = 0;
    int tot = 1;
    int curr_u = 0;
    int curr_n = 0;
    vector<int> vec;
    char last = '\0';

    while (i < word.size()) {
        char a = word[i];

        if (a == 'm' || a == 'w') {
            cout << 0 << endl;
            return 0;
        } else if (last == 'u' && a == 'u') {
            curr_u = (curr_u == 0) ? 2 : curr_u + 1;
        } else if (last == 'n' && a == 'n') {
            curr_n = (curr_n == 0) ? 2 : curr_n + 1;
        } else if (last == 'u' && curr_u > 0) {
            vec.push_back(curr_u);
            curr_u = 0;
        } else if (last == 'n' && curr_n > 0) {
            vec.push_back(curr_n);
            curr_n = 0;
        }

        last = a;
        i++;
    }

    if (i > 1 && word[i - 1] == 'u' && word[i - 2] == 'u') {
        vec.push_back(curr_u);
    }

    if (i > 1 && word[i - 1] == 'n' && word[i - 2] == 'n') {
        vec.push_back(curr_n);
    }

    for (int x : vec) {
        if (x < 5) {
            tot = (tot * (x % static_cast<int>(1e9 + 7))) % static_cast<int>(1e9 + 7);
        } else {
            tot = (tot * (fib(x + 1, memo) % static_cast<int>(1e9 + 7))) % static_cast<int>(1e9 + 7);
        }
        if (tot > static_cast<int>(1e9 + 7)) {
            tot %= static_cast<int>(1e9 + 7);
        }
    }

    if (tot == 0) {
        cout << 1 << endl;
    } else {
        cout << tot << endl;
    }

    return 0;
}
