#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> matrix;

vi taken; // global boolean flag to avoid cycles
priority_queue<ii> pq; // priority queue to help choose shorter edges
vvii AdjList; // adjacency list
matrix AdjMatrix;

void process(int vtx) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjMatrix[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ii(-v.second, -v.first));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E; // number of vertices
    int mst_cost = 0;

    int c, s, q;
    cin >> c >> s >> q;

    while(c != 0 || s != 0 || q != 0){
        
        V = c;
        E = s;
        AdjList.assign(V, vii());

        for(int i = 0; i < E; i++){
            int a, b, w;
            cin >> a >> b >> w;

            AdjList[a].push_back(ii(b, w));
            AdjList[b].push_back(ii(a, w));

        }
        
        taken.assign(V, 0); // no vertex is taken at the beginning
        process(0); // take vertex 0 and process all edges incident to vertex 0

        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            int u = -front.second, w = -front.first; // negate the id and weight again
            if (!taken[u]) { // we have not connected this vertex yet
                mst_cost += w;
                process(u); // take u, process all edges incident to u
            }
        }


    }

    
    return 0;

}
