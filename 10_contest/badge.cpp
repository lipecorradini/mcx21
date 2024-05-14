#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   vector<int> visited(n);
   vector<int> arr(n + 1);

    for(int i = 1; i < n + 1; i++){
        cin >> arr[i];
    }

    // cout << 21;

    for(int i = 1; i < n + 1; i++){
        for(int k = 1; k < n + 1; k++){
            visited[k] = 0;
        }

        int j = i;
        visited[j] = 1;

        while(visited[j] < 2){
            // cout <<"v[" << arr[j] << "]" << "=" << visited[arr[j]] + 1 << '\n'; 
            visited[arr[j]] ++;
            j = arr[j];
        }

        cout << j << " ";
    }

}

