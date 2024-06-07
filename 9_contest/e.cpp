#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;

        vector<long long> arr(n * k);

        for(int j = 0; j < n * k; j++){
            cin >> arr[j];
        }

        long long soma = 0;  
        int l = 0;
        while(l < k){
            // cout << arr[n * k - (n/2 + 1) * (l + 1)] << endl;
            soma += arr[n * k - (n/2 + 1) * (l + 1)];
            l++;
        }

        cout << soma << endl;
        
    }

}
