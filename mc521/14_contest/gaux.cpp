#include <bits/stdc++.h>

using namespace std;

#define MAX_V 40 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 1000000000
#define ll long long

using namespace std;

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};

#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef vector<pair<double, double>> vp;

typedef pair<float, float> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii AdjList; // adjacency list

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, m, s, v;
   while (cin >> n >> m >> s >> v){

        
        vp locs(n);
        vp holes(n + m + 1);

        for(int i = 0; i < n; i++){
            double x, y;
            locs[i].first = x;
            locs[i].second = y;
        }

        for(int i = n; i < n + m; i++){
            double x, y;
            holes[i].first = x;
            holes[i].second = y;
        }

        for(int i = 0; i < n; i++){
            for(int j = n; j < n + m; j++){
                double dist = sqrt( pow(locs[i].first - holes[j].first, 2) + pow(locs[i].second - holes[j].second, 2));
                dini.add(i, j, dist);
            }
        }

        vp max_pairs;
        int cont = 0;
        
        for(int i = 0; i < n; i++){
            max_pairs[i].first = 0; max_pairs[i].second = 0;
            for(int j = n; j < n + m; j ++){
                // Para todos os pares, calcular o max flow até ele
                long long minflow = dini.max_flow(i, j);
                if(minflow < max_pairs[i].second){
                    max_pairs[i].first = j;
                    max_pairs[i].second = minflow;
                }
            }
        }
        // set<int> visitedhole;
        // for(int i = 0; i < n; i++){
        //     int disti = max_pairs[i].second;
        //     if(visitedhole.find(disti) == visitedhole.end() && disti >= s * v){
        //         visitedhole.emplace(max_pairs[i].first);
        //     }else{
        //         cont ++;
        //     }
        // }

        // cout << cont << endl;

   }

}




#include <bits/stdc++.h>

using namespace std;

#define MAX_V 40 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 1000000000

using namespace std;

#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef vector<pair<double, double>> vp;

typedef pair<float, float> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii AdjList; // adjacency list

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, m, s, v;
   while (cin >> n >> m >> s >> v){

        AdjList.assign(n + m + 1, vii());
        vp locs(n);
        vp holes(n + m + 1);
        cout << "maxdist: " << s * v << endl;

        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            locs[i].first = x;
            locs[i].second = y;
        }

        for(int i = n; i < n + m; i++){
            double x, y;
            cin >> x >> y;
            holes[i].first = x;
            holes[i].second = y;
        }

        for(int i = 0; i < n; i++){
            for(int j = n; j < n + m; j++){
                cout << "xi e x2: " << locs[i].first << locs[i].second << endl;
                double dist = sqrt(pow(locs[i].first - holes[j].first, 2) + pow(locs[i].second - holes[j].second, 2));
                cout << "i: " << i << " j: " << j << " dist= " << dist << endl;
                AdjList[i].push_back(ii(j, dist));
            }
        }
        cout << "SECOND" << endl;

        vp max_pairs(n + m + 1);
        int cont = 0;
        
        for(int i = 0; i < n; i++){
            max_pairs[i].first = 0; max_pairs[i].second = 0;
            for(int j =0; j < m; j ++){
                // Para todos os pares, calcular o max flow até ele
                int minflow = AdjList[i][j].second;
                if(minflow < max_pairs[i].second){
                    max_pairs[i].first = j;
                    max_pairs[i].second = minflow;
                }
            }
        }

        set<int> visitedhole;
        for(int i = 0; i < n; i++){
            int disti = max_pairs[i].second;
            cout << "i: " << i << " dist: " << disti << endl;
            if(visitedhole.find(disti) == visitedhole.end() && disti <= s * v){
                visitedhole.emplace(max_pairs[i].first);
            }else{
                cont ++;
            }
        }

        cout << cont << endl;
        // cout
   }

}

