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

vector<pair<int, int>> get_cut(dinitz& g, int s, int t) {
	g.max_flow(s, t);
	vector<pair<int, int>> cut;
	vector<int> vis(g.g.size(), 0), st = {s};
	vis[s] = 1;
	while (st.size()) {
		int u = st.back(); st.pop_back();
		for (auto e : g.g[u]) if (!vis[e.to] and e.flow < e.cap)
			vis[e.to] = 1, st.push_back(e.to);
	}
	for (int i = 0; i < g.g.size(); i++) for (auto e : g.g[i])
		if (vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
	return cut;
}

#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef vector<pair<double, double>> vp;
typedef vector<pair<int, int>> vpi;



int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n, m, s, v;
   while (cin >> n >> m >> s >> v){

        dinitz dini(2 * (n + m) + 4);
        
        vp locs(n);
        vp holes(n + m + 1);

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
                double dist = sqrt(pow(locs[i].first - holes[j].first, 2) + pow(locs[i].second - holes[j].second, 2));
                if(dist <= s*v) dini.add(i, j, dist);
            }
        }

		int source = n + m;
		int final = n + m + 1;

		for(int i = 0; i < n; i++){
			dini.add(source, i, 1);
		}

		for(int i = 0; i < m; i++){
			dini.add(i, final, 1);
		}
        
		vpi finalcut;
		finalcut = get_cut(dini, source, final);
		set<int> vistos;
		int cont = 0;
		for(int i = 0; i < finalcut.size(); i++){
			cout << finalcut[i].first << " " << finalcut[i].second << endl;
			cont ++;
			if(vistos.find(finalcut[i].first) != vistos.end()){
				cont --;
			}else{
				vistos.emplace(finalcut[i].first);
			}

		}



        cout << cont << endl;

   }

}


