#include <bits/stdc++.h>

using namespace std;

int mat[1000][1000];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int cont = 0;
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char curr; cin >> curr;
            if(curr == '#') mat[i][j] = 0;
            else mat[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1){
                // cout << i << " " << j << endl;
                if(i == 0){
                    if(j == 0) cont ++;
                    if(mat[i][j - 1] == 0) cont ++;
                }
                else if (j == 0){
                    if(mat[i - 1][j] == 0) cont ++;
                }
                else{
                    if(!(mat[i - 1][j] | mat[i][j - 1])) cont ++;
                    
             
                }
            }
        }
    }

    cout << cont << endl;

}
