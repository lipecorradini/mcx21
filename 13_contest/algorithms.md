# Prim

Inserir, na árvore, vértices do corte que já estão na árvore.

### Algoritmo de Prim


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
        int V; // number of vertices
        int mst_cost = 0;

        // Assuming graph is stored in AdjList and pq is empty
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

        printf("MST cost = %d (Prim's)\n", mst_cost);

        return 0;
    }



# Kruskal

Escolhe uma aresta leve do conjunto para compor a AGM

## Algoritmo de Kruskal



    typedef pair<int, int> ii;
    typedef pair<int, ii> iii;
    typedef vector<iii> viii;

    class UnionFind {
    private:
        vector<int> p, rank;
    public:
        UnionFind(int N) {
            p.assign(N, 0);
            rank.assign(N, 0);
            for (int i = 0; i < N; i++) p[i] = i;
        }
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
    };

    int main() {
        int V, E; // V: number of vertices, E: number of edges
        viii EdgeList; // edge list for Kruskal's algorithm

        // Assuming EdgeList is already filled with edges
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        // note: pair object has built-in comparison function

        int mst_cost = 0;
        UnionFind UF(V); // all V are disjoint sets initially

        for (int i = 0; i < E; i++) { // for each edge, O(E)
            iii front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                mst_cost += front.first; // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second); // link them
            }
        }

        // note: the number of disjoint sets must eventually be 1 for a valid MST
        printf("MST cost = %d (Kruskal's)\n", mst_cost);

        return 0;
    }

## Segunda menor árvore geradora

Ver nesse link: https://cp-algorithms.com/graph/second_best_mst.html


## Outros


Ainda tem o problema do minimax, definido no contest anterior


