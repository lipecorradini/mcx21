#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> cds;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        cds.insert(value);
    }

    int cont = 0;

    for (int j = 0; j < m; j++)
    {
        int value;
        cin >> value;
        if (cds.find(value) != cds.end())
        {
            cont++;
        }
    }

    int a, b;
    cin >> a >> b;

    cout << cont;
}