#include <bits/stdc++.h>
#include <math.h>

using namespace std;


void solve(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rook = 0, king = 0, bishop = 0;

    if(r1 == r2 && c1 == c2){
        cout << rook << " " <<  bishop << " " << king;
        return;
    }
    if(r1 == r2 || c1 == c2){
            rook = 1;    
    }else{
        rook = 2;    
    }

    
    king = max(abs(c1- c2), abs(r1 - r2));
    if(abs(c1 - r1)%2 == abs(c2 - r2)%2){
            if((c1 - r1) == (c2 - r2) || c1 + r1 == c2 + r2){
                bishop = 1;
            }else{
                bishop = 2;
            }
        }
    cout << rook << " " <<  bishop << " " << king;
    return;

}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   solve();
}
