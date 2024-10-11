#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string a;

int recursion(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];

    if (l > r)
    {
        return dp[l][r] = 0;
    }
    else if (l == r)
        return dp[l][r] = 1;

    if (a[l] == a[r])
    {
        return dp[l][r] = 2 + recursion(l + 1, r - 1);
    }

    else
    {
        return dp[l][r] = max(recursion(l, r - 1), recursion(l + 1, r));
    }
}

int main()
{
    getline(cin, a);
    int t = stoi(a);

    for (int i = 0; i < t; i++)
    {
        getline(cin, a);
        memset(dp, -1, sizeof(dp));
        if (a.size() == 0)
            cout << 0 << endl;
        else
            cout << recursion(0, a.size() - 1) << endl;
    }

    return 0;
}
