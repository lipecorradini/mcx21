#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int q;
   cin >> q;

   for(int i = 0; i < q; i++){
      int n;
      long long k;
      queue<int> fila;
      cin >> n >> k;

      int cont_0 = 0;

      string s;
      cin >> s;

      while(s[cont_0] == '0'){
         cont_0 ++;
      }

      for(int j = cont_0; j < n ; j++){
         if(s[j] == '0'){
            fila.push(j);
         }
      }
   
      while(!fila.empty() && k > 0){
         
         int u = fila.front();
         fila.pop();

         int swaps = u - cont_0;
         if(k >= swaps){
            s[cont_0] = '0';
            k -= swaps;
         } else {
            s[u - k] = '0';
            k = 0;
         }
         s[u] = '1';
         cont_0 ++;
      }

      cout << s << endl;

   }
}
