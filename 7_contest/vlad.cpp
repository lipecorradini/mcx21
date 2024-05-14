#include <bits/stdc++.h>

using namespace std;

int soma_digitos(int n){
    int soma = 0;
    while(n > 0){
        soma += n % 10;
        n = n / 10;
    }
    return soma;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t;
   cin >> t;

   int num;

   vector <long> f(2 * 1e5);

    for(int i = 0; i < 2 * 1e5; i++){
        if(i == 0) f[i] = 0;
        else f[i] = f[i - 1] + soma_digitos(i);
    }
    f[200000] = 4600002;

   for(int i = 0; i < t; i++){
        cin >> num;
        cout << f[num] << '\n';
    
   }

}
