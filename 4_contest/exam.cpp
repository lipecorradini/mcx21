#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        int k;
        cin >> n >> k;
        priority_queue<int> maxH;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool flag = true;

        sort(arr.begin(), arr.end(), arr.size());

        for (i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];
                maxH.push(sum);
                if(maxH.size() == k) flag = false; break;
            }

            if(!flag){
                break;
            }
        }

        cout << maxH.top() << '\n';
    }
}
