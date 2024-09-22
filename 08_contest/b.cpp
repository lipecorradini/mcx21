#include <bits/stdc++.h>

using namespace std;

// o código utilizado foi amplamente baseado nos slides da disciplina
#include <iostream>
#include <utility>

int f(long long x); // Assume this function is defined earlier

set<long long> seen;

int floydCycleFinding(int x0) {

    int hare = (x0);
    // cout << "x0: " << x0 << endl;
    while(seen.find(hare) == seen.end()){
        // cout << hare << " ";
        if(hare == 1) return 1;
        seen.emplace(hare);
        hare = f(hare);
    }
    // cout << endl;

    return 0; 
}

int f(long long n){
       long long sum = 0;
       while(n >= 10){
            sum += (n % 10) * (n % 10);
            n /= 10;
       }
       sum += n * n;
       return sum;
    }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;cin >> n;
    int cont = 1;
    
    while(n--){
        seen.clear();
        int v; cin >> v;
        if(floydCycleFinding(v)){
            cout << "Case #" << cont++ << ": " << v << " is a Happy number." << endl;
        }else{
            cout << "Case #" << cont++ << ": " << v << " is an Unhappy number." << endl;

        }

    }

}
