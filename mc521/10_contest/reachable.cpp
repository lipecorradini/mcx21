#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0); // Initialize parent to self
    }

    int find(int u) { // Find root of set containing u
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unite(int u, int v) { // Union by rank
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v])
                swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
        }
    }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        int m, r;
        cin >> m >> r;
        UnionFind uf(m);

        for(int j = 0; j < r; j++){
            int a, b;
            cin >> a >> b;
            uf.unite(a, b);
        }

        set<int> conj;
        for(int j = 0; j < m; j++){

            int pai = uf.find(j);
            if(conj.find(pai) == conj.end()){
                conj.insert(pai);
            }
            
        }

        cout << conj.size() - 1 << '\n';
    }    
}

