#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 1E9;
    typedef pair<int, int> ii;

    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> AdjList[n];
        int s;
        for(int j = 0; j < m; j++){
            int a, b, w;
            cin >> a >> b >> w;
            AdjList[a].push_back({b, w});
            s = a;
        }

        vector<int> dist(n, INF);
        vector<int> pred(n, -1);
        dist[s] = 0;

        for (int i = 1; i <= n - 1; i++)  // relax all E edges V-1 times
            for (int u = 0; u < n; u++)  // these next two loops = O(E), overall O(VE)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];
                    if (dist[u] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;  // relax
                        pred[v.first] = u;  // save predecessor
                    }
                }

        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) // one more pass to check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second) // if this is still possible
                hasNegativeCycle = true; // then negative cycle exists!
        }
        
        if(hasNegativeCycle) cout << "possible" << '\n';
        else cout << "not possible" << '\n';
    

    }


}
