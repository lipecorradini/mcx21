#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int NODES = 100; // ajusta conforme necessário

int main() {

    ios::sync_with_stdio(false);
   cin.tie(0);

    
    int V, E;
    vector<vector<int>> dist(NODES, vector<int>(NODES, INF));
    cin >> V >> E;
    int contnet = 1;

    while(V != 0 && E != 0){

        map<string, int> setNum;

        string a, b;
        int cont = 0;
        for(int i = 0; i < E; i++){
            cin >> a >> b;
            if(setNum.find(a) == setNum.end()){
                setNum[a] = cont;
                cont ++;
            }
            if(setNum.find(b) == setNum.end()){
                setNum[b] = cont;
                cont ++;
            }

            dist[setNum[a]][setNum[b]] = 1;
            dist[setNum[b]][setNum[a]] = 1;
        }

        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }   
    
    
        // Algoritmo de Floyd-Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        
        int great = 0;

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][j] == INF){
                    cout << "Network " << contnet << ":DISCONNECTED" << '\n';
                    break;
                }
                else if(dist[i][j] > great && dist[i][j] < INF){
                    great = dist[i][j];
                }

            }
        }

        if(great > 0 && great < INF){
            cout << "Network " << contnet << ":" << great << '\n';

        }

        contnet ++;
        cin >> V >> E;
    }
}