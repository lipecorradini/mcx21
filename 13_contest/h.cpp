#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi taken; // global boolean flag to avoid cycles
priority_queue<ii> pq; // priority queue to help choose shorter edges
vvii AdjList; // adjacency list

void process(int vtx) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ii(-v.second, -v.first));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V; // number of vertices

    int t; cin >> t;

    while(t != 0){

        int n, m; cin >> n >> m;
        V = n;
        AdjList.assign(n + 1, vii());

        for(int i = 0; i < m; i++){

            long long a, b, w; cin >> a >> b >> w;
            w = log2(w);
            // cout << a << " " << b << " " << w << endl;

            if(w == 0) w = 1;
            a -= 1;
            b -= 1;
            AdjList[a].push_back(ii(b, w));
            AdjList[b].push_back(ii(a, w));
        }

        long long mst_cost = 1;

        taken.assign(V, 0); // no vertex is taken at the beginning
        process(0); // take vertex 0 and process all edges incident to vertex 0

        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            int u = -front.second, w = -front.first; // negate the id and weight again
            if (!taken[u]) { // we have not connected this vertex yet
                // cout << "temos o w: " << w << " do u: " << u << endl;
                mst_cost += w;
                process(u); // take u, process all edges incident to u
            }
        }

        cout << mst_cost << endl;
        t--;

    }
        
    return 0;


}
