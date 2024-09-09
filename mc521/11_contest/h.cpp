#include <bits/stdc++.h>

using namespace std;

void set_vec(vector<int> dist, vector<int> new_dist, 
vector<int> pred, vector<int> new_pred, int n){

    for(int i = 0; i < n; i++){
        new_dist[i] = dist[i];
        new_pred[i] = pred[i];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 1E9;
    typedef pair<int, int> ii;

    int c;
    cin >> c;

    for(int l = 0; l < c; l++){
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;
        s--;
        t --;

        vector<pair<int, int>> AdjList[n];
        for(int i = 0; i < m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            a--;
            b--;
            AdjList[a].push_back({b, w});
        }

        int min_dist = INF;

        typedef pair<int, int> ii;
        
        vector<int> dist(n, INF);  // INF = 1E9 to avoid overflow
        vector<int> pred(n, -1);
        
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        dist[s] = 0;
        pq.push(ii(dist[s], s));

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


        // cout << "antes: " << dist[t] << '\n';

        for(int j = 0; j < k; j++){

            vector<int> new_dist(n, INF);  // INF = 1E9 to avoid overflow
            vector<int> new_pred(n, -1);

            for(int i = 0; i < n; i++){
                new_dist[i] = dist[i];
                new_pred[i] = pred[i];
            }

            int a, b, w;
            cin >> a >> b >> w;
            a--;
            b--;
            AdjList[a].push_back({b, w});
            AdjList[b].push_back({a, w});

            int initial = a;
            if(dist[a] > dist[b]) initial = b;
            
            // cout << "adicionando aresta" << a << " " << b << '\n';
            new_dist[s] = 0;
            pq.push(ii(new_dist[initial], initial));

            while (!pq.empty()) {  // main loop
                ii front = pq.top(); pq.pop();  // greedy: get shortest unvisited vertex
                int d = front.first, u = front.second;
                // cout << d << " " << u << '\n';
                if (d > new_dist[u]) continue;  // check for duplicates
                for (int j = 0; j < AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];  // all outgoing edges from u
                    if (new_dist[u] + v.second < new_dist[v.first]) {
                        new_dist[v.first] = new_dist[u] + v.second;  // relax operation
                        new_pred[v.first] = u;  // save predecessor
                        pq.push(ii(new_dist[v.first], v.first));
                    }
                }
        }
            // cout << new_dist[t] << '\n';
            
            if(new_dist[t] < min_dist) min_dist = new_dist[t];

            AdjList[a].pop_back();
            AdjList[b].pop_back();
            
        }

        if(min_dist < INF) cout << min_dist << '\n';
        else cout << -1 << '\n';
    }

}
