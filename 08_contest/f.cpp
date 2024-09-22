#include <bits/stdc++.h>
#include<math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;cin >> t;
    while(t){
        if(t == 1) cout << 1 << endl;
        else if((t - pow(2, int(log2(t)))) == 0) cout << t << endl;
        else cout << (t - pow(2, int(log2(t)))) * 2 << endl;
        cin >> t;
    } 

}