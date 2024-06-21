#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<double>> adjMatrix;

const double INF = 1e9;

bool arbitrage(int V, adjMatrix &dist) {
    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < V; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (dist[u][v] > dist[u][k] * dist[k][v]) {
                    dist[u][v] = dist[u][k] * dist[k][v];
                }
            }
        }
    }

    // Check for arbitrage: look for a cycle with product > 1
    for (int u = 0; u < V; ++u) {
        if (dist[u][u] < 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;

    while ((cin >> V) && V) {
        adjMatrix dist(V, vector<double>(V, INF));
        map<string, int> id;

        for (int i = 0; i < V; i++) {
            string name;
            cin >> name;
            id[name] = i;
            dist[i][i] = 1.0; // Initialize self-loop to 1
        }

        cin >> E;
        while (E--) {
            string orig, dest;
            unsigned num, denom;
            cin >> orig >> dest;
            scanf("%u:%u\n", &num, &denom);
            dist[id[orig]][id[dest]] = (num * 1.0) / denom;
        }

        if (arbitrage(V, dist)) {
            cout << "Arbitrage" << endl;
        } else {
            cout << "Ok" << endl;
        }
    }
}
