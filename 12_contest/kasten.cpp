#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int NODES = 102; // ajusta conforme necessário

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;

    for(int i = 0; i < t; i++){
        vector<vector<int>> dist(NODES, vector<int>(NODES, INF));
    
        int n;
        cin >> n;
        vector<pair<int, int>> pairs(n + 2);

        int V = n + 2;

        for (int i = 0; i < V; i++) {
            int x, y;
            cin >> x >> y;
            pairs[i].first = x;
            pairs[i].second = y;
        
        }

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                dist[i][j] = (abs(pairs[i].first - pairs[j].first) + abs(pairs[i].second - pairs[j].second));
            }
        }

        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
        
        // cout << "max: " << dist[0][n + 1] << '\n';
        if(dist[0][n + 1] <= 1000) cout << "happy" << '\n';
        else cout << "sad" << '\n';
        
    }
}

