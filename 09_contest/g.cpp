#include <bits/stdc++.h>

using namespace std;

#define MAX 40001
// The functions above are largely based on the slides of the discipline


// Function to compute the LPS array
void computeLPSArray(string P, int M, int lps[]) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // Calculate lps[i] for i = 1 to M-1
    while (i < M) {
        if (P[i] == P[len]) {
            len++;
            // if(i >= MAX - 1) cout << i << endl;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lps[MAX];
    string input;
    cin >> input;

    int M = input.length();
    // cout << M << endl;
    computeLPSArray(input, M, lps);

    int max = 0;
    int imax = 0;
    int ini_final = 0;
    int max_0;

    for(int i = 0; i < M; i++){
        if(lps[i] == 2) ini_final = i; // ultimo i
        if(lps[i] == 0) max_0 = i;

    }
    // cout << lps[M - 1] << endl;

    if(max_0 > ini_final) ini_final = 0; 

    // for(int i = 0; i < M; i++){
    //     cout << "i: " << i << ") lps: " << lps[i] << " " << input[i] << endl;

    // }

    ini_final --;
    // cout << ini_final << endl;
    int save_final = ini_final;
    int j = 0;

    if(ini_final > 0){
        while(ini_final < M && input[j] == input[ini_final]){
            j ++;
            ini_final ++;
        }

    }

    // cout << j << endl;
    if(j > save_final && save_final >= 0){
        cout << "YES" << endl;

        for(int i = save_final; i < M; i++){
            cout << input[i] << "";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }



}
