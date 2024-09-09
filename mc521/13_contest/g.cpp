#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    long n;
    cin >> n >> t;
    vector<int> arr(n);
    int curr_cell = 1;
    arr[0] = -11111;

    for (int i = 1; i < n; i++){
        cin >> arr[i];
    }
    bool isvalid = false;

    while(curr_cell < t){
        curr_cell += arr[curr_cell];
        if(curr_cell == t) isvalid= true;
    }
    if(isvalid) cout << "YES" << endl;
    else cout << "NO" << endl;
}
