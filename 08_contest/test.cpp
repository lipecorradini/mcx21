#include <bits/stdc++.h>
#include<math.h>

using namespace std;

void teste(int t) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    if(t){
        if(t == 1) cout << 1 << endl;
        if((t - pow(2, int(log2(t)))) == 0) cout << t << endl;
        else cout << (t - pow(2, int(log2(t)))) * 2 << endl;
    }else{
        cout << "cabou" << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 0; i < 20; i++){
        cout << pow(2, i) << ": ";
        teste(pow(2, i));
    }

}


