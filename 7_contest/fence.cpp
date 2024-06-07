#include <bits/stdc++.h>

using namespace std;

   
int min_sum_of_subarray(vector<int> arr, int n, int k, vector<int> somas)
{
    int min_sum;
    int min_ind = -1;
    for (int i = 0; i + k <= n; i++) {
        int temp = 0;
    
        if(i == 0){
            for (int j = i; j < i + k; j++) {
                temp += arr[j];
                somas[j] = temp;
            }
        }

        else{
            somas[i + k - 1] = somas[i + k - 2] + arr[i + k - 1];
            temp = (somas[i + k - 1]) - somas[i - 1];
        } 
        
        if (temp < min_sum || i == 0){
            min_sum = temp;
            min_ind = i;
        }
            
    }
 
    return min_ind + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int min_ind;
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> somas(n);
    
    int iseq = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != 0 && arr[i] != arr[i-1] && n > 1) iseq = 0;
        somas[i] = 0;
    }

    if(iseq == 1){
        cout << 1 << '\n';
    }
    else{
        // by brute force
        min_ind = min_sum_of_subarray(arr, n, k, somas);
        cout << min_ind << endl;
    }
    
 
    return 0;
}

