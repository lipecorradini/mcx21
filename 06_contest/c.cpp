#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, x;
   cin >> n;

   for(int i = 0; i < n; i++){
        cin >> x;
        int cont = 0;
        for(int j = 0; j <= (sqrt(x)) + 1; j++){
            if(x % j == 0){
                cont += 2;
                if(j == sqrt(x)) cont --;
            }

        }
        cout << cont << endl;

   }

}
