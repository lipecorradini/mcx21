#include <bits/stdc++.h>

using namespace std;

// o código utilizado foi amplamente baseado nos slides da disciplina
#include <iostream>
#include <utility>

int f(int x); // Assume this function is defined earlier
int z, i, m;

int floydCycleFinding(int x0) {
    // Phase 1: Finding k * λ, hare's speed is 2x tortoise's
    int tortoise = f(x0);
    int hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // Phase 2: Finding μ, hare and tortoise move at the same speed
    int mu = 0;
    hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    // Phase 3: Finding λ, hare moves, tortoise stays
    int lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda++;
    }

    return lambda; // Returns both μ and λ
}

int f(int l){
    return (z * l + i) % m;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l;
    int cont = 1;
    cin >> z >> i >> m >> l;
    while(z != 0 && i != 0 && m != 0 && l != 0){
        cout << "Case " << cont++ << ": " << floydCycleFinding(l) << endl;
        cin >> z >> i >> m >> l;
    }

}
