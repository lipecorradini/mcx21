#include <iostream>
#include <vector>
#include <algorithm> // For the gcd function

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> trees(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> trees[i];
    }

    std::vector<int> dist(n - 1);
    for (int i = 1; i < n; ++i) {
        dist[i - 1] = trees[i] - trees[i - 1];
    }

    int greater = dist[0];
    for (int i = 1; i < n - 1; ++i) {
        greater = gcd(dist[i], greater);
    }

    std::cout << (trees[n - 1] - trees[0]) / greater - n + 1 << std::endl;

    return 0;
}
