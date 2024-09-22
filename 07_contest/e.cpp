#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a; cin >> a;
        if(a % 2 == 0) cout << a/2;
        else cout << (a - 1)/2;
        cout << endl;
    }

}
