#include <bits/stdc++.h>

using namespace std;

// codigo amplamente baseado nos slides da disciplina 

typedef vector<int> vi;
vi primes; 

long long EulerPhi(long long N) {
    
    long long ans = N;
    long long PF_idx = 0, PF = primes[PF_idx];
    ans = N;
    
    while (N != 1 && (PF * PF <= N)) {
        if (N % PF == 0) ans -= ans / PF; 
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    
    if (N != 1) ans -= ans / N; 
    return ans;
}

typedef long long ll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs; 

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1; 
    bs.set();                        
    bs[0] = bs[1] = 0;               

    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i); 
        }
    }
}

bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N]; 
    for (int i = 0; i < (int)primes.size(); i++) {
        if (N % primes[i] == 0) return false;
    }
    return true; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(1e6 + 1);

    int t; cin >> t;
    while(t -- ){
        int a; cin >> a;
        cout << EulerPhi(a) << endl;
    }

}
