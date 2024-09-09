#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, k, r = 1;
   cin >> n >> k;
   
   for(int i = 0; i < n; i++){
        if(r < k) r *= 2;
        else r += k; 
   }

   cout << r << '\n';
}
