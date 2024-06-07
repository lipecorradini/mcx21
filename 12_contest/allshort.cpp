#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int NODES = 150; 

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, m, q;
   cin >> n >> m >> q;

   while(n != 0 && m != 0 && q != 0){

        vector<int> ver(n, 0);
        vector<vector<int>> dist(NODES, vector<int>(NODES, INF));
        
        int V = n;
        int E = m;        
        
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(w < dist[u][v]) dist[u][v] = w; // grafo direcionado
        }

        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
        
        // Algoritmo de Floyd-Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if(dist[i][k] != INF && dist[k][j] != INF && dist[k][k] < 0)
                        dist[i][j] = -INF;  

        
        for(int i = 0; i < q; i ++){
            int a, b;
            cin >> a >> b;
            if(dist[a][b] == -INF) cout << "-Infinity" << '\n';
            else if(dist[a][b] == INF) cout << "Impossible" << '\n';
            else cout << dist[a][b] << '\n';
        
        }

        cout << '\n';
        cin >> n >> m >> q;

    }
}
