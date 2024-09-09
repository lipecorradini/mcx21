#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0){
        
        set<long long> cds;

        for (int i = 0; i < n; i++)
        {
            long long value;
            cin >> value;
            cds.insert(value);
        }

        int cont = 0;

        for (int j = 0; j < m; j++)
        {
            long long value;
            cin >> value;
            if (cds.find(value) != cds.end())
            {
                cont++;
            }
        }

        cin >> n >> m;

        cout << cont;
    }

    
}