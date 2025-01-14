#include <bits/stdc++.h>

using i64 = long long;

const int N = 20010, M = N * 2;

int n, m;

int h[N], e[M], w[M], ne[M], idx;

int p[N], dist[N];

int res[N];

int st[N];

std::vector<std::pair<int, int>> query[N]; // first存查询的另一个点， second存查询编号


void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void dfs(int u, int fa) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
		if (v == fa) continue;
		dist[v] = dist[u] + w[i];	
		dfs(v, u);
	}		
}

void tarjan(int u) {
	st[u] = 1;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
		if (!st[v]) {
			tarjan(v);
			p[v] = u;
		}
	}

	for (auto item: query[u]) {
		int y = item.first, id = item.second;
		if (st[y] == 2) {
			int anc = find(y);
			res[id] = dist[u] + dist[y] - dist[anc] * 2;
		}
	}

	st[u] = 2;
}

int main() {
	std::cin >> n >> m;

	memset(h, -1, sizeof h);

	for (int i = 0; i < n - 1; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c), add(b, a, c);
	}

	for (int i = 0; i < m; i ++) {
		int a, b;
		std::cin >> a >> b;

		if (a != b) {
			query[a].push_back({b, i});
			query[b].push_back({a, i});	
		}	
	}

	for (int i = 1; i <= n; i ++) p[i] = i;

	dfs(1, -1);

	tarjan(1);

	for (int i = 0; i < m; i ++) {
		std::cout << res[i] << "\n";
	}
}
