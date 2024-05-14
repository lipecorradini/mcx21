#include <bits/stdc++.h>

using namespace std;

void findSubarraySum(vector<long long> arr, int n){
    
    unordered_map<long long, long long> prevSum;

    prevSum[0] += 1;
    long long res = 0;
    long long curr_sum = 0;

    for(int i = 0; i < n; i++){

        curr_sum = ((curr_sum + arr[i])%n+n)%n;
   
        res += prevSum[curr_sum];
        
        prevSum[curr_sum] ++;

    }
    cout << res;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    findSubarraySum(arr, n);

}
