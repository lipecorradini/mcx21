#include <bits/stdc++.h>

using namespace std;

int divisors(int a, vector<long long> div) {
    
    for(int i = pow(a, 0.5) + 1; i > 0; i--){
        if(a % i == 0)div.push_back(i);
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   long long m;

   cin >> n >> m;

   vector<long long> div;
   divisors(m, div);



   while(true){
        long long last = div.pop_back();
        
   }
}
