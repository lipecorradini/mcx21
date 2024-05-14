#include <bits/stdc++.h>

using namespace std;
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W

int knapSackRec(int W, int wt[], int val[], int index, int** dp)
{
    // base condition
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {

        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    }
    else {

        dp[index][W] = max(val[index]
                           + knapSackRec(W - wt[index], wt, val,
                                         index - 1, dp),
                       knapSackRec(W, wt, val, index - 1, dp));

        return dp[index][W];
    }
}
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int s, n;
    cin >> s >> n;

    int c[n];
    int w[n];

    for(int i = 0; i < n; i++){
        cin >> w[i] >> c[i];
    }

    int W = s;
    cout << knapSack(W, w, c, n);
    return 0;
}
