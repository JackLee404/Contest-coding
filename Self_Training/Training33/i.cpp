#include <bits/stdc++.h>
#define x first
#define y second

using i64 = long long;

const int N = 110;

typedef std::pair<int, int> PII;

int n, m, k;

PII match[N][N];

bool g[N][N], st[N][N];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


bool find(int x, int y) {
	for (int i = 0; i < 8; i ++) {
		int a = x + dx[i], b = y + dy[i];

		if (a < 1 || a > n || b < 1 || b > m) continue;

		if (g[a][b]) continue;
		
		if (st[a][b]) continue;
		
		st[a][b] = true;

		PII t = match[a][b];

		if (t.x == 0 || find(t.x, t.y)) {
			match[a][b] = {x, y};
			return true;
		}
	}
	return false;
}

int main() {
	std::cin >> n >> m >> k;

	for (int i = 0; i < k; i ++) {
		int x, y;
		
		std::cin >> x >> y;	

		g[x][y] = true;
	}	

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if ((i + j) % 2 || g[i][j]) continue;
			memset(st, 0, sizeof st);
			if (find(i, j)) res ++;
		}
	}

	std::cout << n * m - k - res;
}