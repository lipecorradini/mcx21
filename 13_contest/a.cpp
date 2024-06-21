#include <bits/stdc++.h>
#include <math.h>

using namespace std;

typedef pair<float, float> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi taken; // global boolean flag to avoid cycles
priority_queue<ii> pq; // priority queue to help choose shorter edges
vvii AdjList; // adjacency list

void process(int vtx) { // so, we use -ve sign to reverse the sort order
    // cout << "PROCESS" << endl;
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            // cout << "add " << v.first << " com " << vtx << endl;
            pq.push(ii(-v.second, -v.first));
        }
    }
}

float dist(float x1, float x2, float y1, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t > 0) {
        int m;
        cin >> m;
        vii positions(m);
        AdjList.assign(m, vii());

        for(int i = 0; i < m; i++) {
            cin >> positions[i].first >> positions[i].second;
        }

        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                float edge = dist(positions[i].first, positions[j].first, positions[i].second, positions[j].second);
                AdjList[i].push_back(ii(j, edge));
                AdjList[j].push_back(ii(i, edge));
            }
        }

        float mst_cost = 0;
        taken.assign(m, 0); // no vertex is taken at the beginning
        process(0); // take vertex 0 and process all edges incident to vertex 0

        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            // cout << "QUEUE" << endl;
            ii front = pq.top(); pq.pop();
            // cout << "o top eh " << front.second << endl;
            int u = -front.second;
            float w = -front.first; // negate the id and weight again
            if (!taken[u]) { // we have not connected this vertex yet
                // cout << u << " adicionado" << endl;
                mst_cost += w;
                process(u); // take u, process all edges incident to u
            }
        }

        cout << fixed << setprecision(3) << mst_cost << endl;
        t--;
    }
    return 0;
}
