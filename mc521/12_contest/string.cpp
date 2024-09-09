#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int NODES = 100; // ajusta conforme necessário


int mini(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b < a && b <= c) return b;
    return c;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a;
    cin >> b;

    int n;
    cin >> n;

    vector<vector<int>> dist(NODES, vector<int>(NODES, INF));

    int V = 26;
    int E = n;
    
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u -= 97;
        v -= 97;
        if(dist[u][v] > w) dist[u][v] = w; // grafo direcionado
    }
    
    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    long long tot = 0;
    if(a.size() != b.size()){
        cout << -1 << '\n';
        return 0;
    }

    string newstr = "";

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){

            int int_a = a[i] - 97;
            int int_b = b[i] - 97;
            
            int d_ida = dist[int_a][int_b];
            int d_volta = dist[int_b][int_a];


            int d_mid = INF;
            char d_char;

            for(int j = 0; j < V; j++){
                if(j != int_a && j != int_b){
                    int aux_d = dist[int_a][j] + dist[int_b][j];
                    if (aux_d < d_mid){
                        d_mid = aux_d;
                        d_char = (char) j + 97;
                    } 
                }
            }

            // if(i == 2) cout << d_mid << "-- " << d_char << '\n';

            if(mini(d_ida, d_volta, d_mid) == d_ida){
                tot += d_ida;
                newstr += b[i];

            }else if(mini(d_ida, d_volta, d_mid) == d_volta){
                tot += d_volta;
                newstr += a[i];

            }else{
                tot += d_mid;
                newstr += d_char;
            }
        }else{
            newstr += a[i];
        }
    }

    if(tot < INF){
        cout << tot << '\n';
        cout << newstr << '\n';
    }else{
        cout << -1 << '\n';
    }
    
    
}
