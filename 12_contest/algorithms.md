
FLOYD-WARSHALL:

    const int INF = 1e9;
    const int NODES = 100; // ajusta conforme necessário

    int main() {
        int V, E, u, v, w;
        vector<vector<int>> dist(NODES, vector<int>(NODES, INF));
        
        cin >> V >> E;
        
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            dist[u][v] = w; // grafo direcionado
        }
        
        // Algoritmo de Floyd-Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        return 0;
    }



PRINTANDO FLOYD-WARSHALL:

    void printPath(int i, int j, const vector<vector<int>>& pred) {
        if (i != j) printPath(i, pred[i][j], pred);
        cout << j << " ";
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            pred[i][j] = i;
        }
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w; // grafo direcionado
    }
    
    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j]; // atualiza a matriz pred
                }
            }
        }
    }

    // Exemplo de como chamar a função printPath
    int start = 0, end = V - 1; // ajusta conforme necessário
    cout << "Caminho mais curto de " << start << " para " << end << ": ";
    printPath(start, end, pred);
    cout << endl;


FECHO TRANSITIVO:
    definir se existe caminho de i até j em um grafo G

    for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);


CAMINHO MINIMAX:
    encontrar caminho cuja aresta de maior comprimento seja mínima

    for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));


ALGORIMTO DE JOHNSON:
    algoritmo mais eficiente do que floyd-warshall para grafos esparsos

    #define INF 99999
    
    #define V 4
    
    int minDistance(int dist[], bool sptSet[])
    {
        int min = INT_MAX, min_index;
    
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
    
        return min_index;
    }
    
    void printSolution(int dist[][V])
    {
        printf("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    printf("%7s", "INF");
                else
                    printf("%7d", dist[i][j]);
            }
            printf("\n");
        }
    }
    
    void floydWarshall(int graph[][V])
    {
        int dist[V][V], i, j, k;
    
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
    
        for (k = 0; k < V; k++) {
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    
        printSolution(dist);
    }

    na main, so chamar essa floyd warshall
    

