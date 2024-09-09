
dijkstra:

    typedef pair<int, int> ii;
    const int INF = 1E9;

    vector<int> dist(V, INF);  // INF = 1E9 to avoid overflow
    vector<int> pred(V, -1);
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[s] = 0;
    pq.push(ii(dist[s], s));

    while (!pq.empty()) {  // main loop
        ii front = pq.top(); pq.pop();  // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;  // check for duplicates
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];  // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;  // relax operation
                pred[v.first] = u;  // save predecessor
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }


bellman-ford:

    vector<int> dist(V, INF);
    vector<int> pred(V, -1);
    dist[s] = 0;

    for (int i = 1; i <= V - 1; i++)  // relax all E edges V-1 times
        for (int u = 0; u < V; u++)  // these next two loops = O(E), overall O(VE)
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;  // relax
                    pred[v.first] = u;  // save predecessor
                }
            }

bellman find neg cycle:

    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++) // one more pass to check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second) // if this is still possible
                hasNegativeCycle = true; // then negative cycle exists!
        }
    printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

