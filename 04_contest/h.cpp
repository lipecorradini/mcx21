#include <bits/stdc++.h>
#include <string>
using namespace std;

#define MAXDIGITS 100000
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    string palavra;
    cin >> palavra;

    int ini = 0; int final = 0;
    set<char> curr;

    int tam = palavra.length();
    int cont = 0, curr_size = 0;

    for(int i = 0; i < tam; i++){
        while(curr.find(palavra[final]) == curr.end() && final < tam){
            curr.insert(palavra[final]);
            cont += curr.size();
            // cout << endl << "tamanho: " << curr.size() << endl;
            final ++;
        }

        if(final <= tam - 1){
            ini ++;
            final = ini;
            i = ini;
            curr.clear();
            cont --;
        }
        
    }
    cout << cont << '\n';
}
