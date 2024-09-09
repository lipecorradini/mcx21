#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t;
   cin >> t;

   for(int i = 0; i < t; i++){
        int soma = 0 ,was = 0;
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int j = 0; j < n; j++){
            cin >> arr[j];
            if(arr[j - 1] > arr[j] && j != 0 && !was) {
                soma ++;
                was = 1;
            }else was = 0;
    }
        cout << soma << '\n';
 
   } 


}
