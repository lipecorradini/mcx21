#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   const int INF = 1E9;
   int N; 
   cin >> N;

    for(int i = 0; i < N; i++){
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        vector<pair<int, int>> AdjList[n];
        for(int j = 0; j < m; j++){
            int a, b, w;
            cin >> a >> b >> w;
            AdjList[a].push_back({b, w});
            AdjList[b].push_back({a, w});
        }

        typedef pair<int, int> ii;
        
        vector<int> dist(n, INF);  // INF = 1E9 to avoid overflow
        vector<int> pred(n, -1);
        
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        dist[S] = 0;
        pq.push(ii(dist[S], S));

        while (!pq.empty()) {  // main loop
            ii front = pq.top(); pq.pop();  // greedy: get shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;  // check for duplicates
            for (int j = 0; j < AdjList[u].size(); j++) {
                ii v = AdjList[u][j];  // all outgoing edges from u
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;  // relax operation
                    pred[v.first] = u;  // save predecessor
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
        
        if(dist[T] < INF) cout << "Case #" << i + 1 << ": " << dist[T] << '\n';
        else cout << "Case #" << i + 1 << ": unreachable" << '\n';

    }

}
