#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    int n;
    cin >> n;

    string la;
    cin >> la;

    for(int i = 1; i < n; i++){
        int cont = 0;
        for(int j = 0; j < n - i; j++){
            if(la[j] != la[j + i]) cont ++;
            else break;
        }            
        cout << cont << '\n';
    }

}
