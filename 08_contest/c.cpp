#include <bits/stdc++.h>

using namespace std;

// o código utilizado foi amplamente baseado nos slides da disciplina
#include <iostream>
#include <utility>

long long counter = 0;
int f(int x); // Assume this function is defined earlier
int a, b;
long long n;

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

int f(int x){
    return ((a * 1ll * x % n * x) + b) % n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    int cont = 1, isvalid = 1;
    while(cin >> n){
        if(n == 0) break;
        cin >> a >> b;
        cout << n - floydCycleFinding(0) << endl;
        
    }

}
