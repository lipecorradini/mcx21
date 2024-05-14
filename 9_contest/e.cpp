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

        vector<long> arr(n * k);

        for(int j = 0; j < n * k; j++){
            cin >> arr[j];
        }

        
        for(int j = n*k - n; j >=0; j-= n){
            cout << arr[j] << " ";
        }

        cout << endl;
    }

}
