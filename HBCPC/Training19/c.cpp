#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define siz(x) (int)x.size()
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

string b = "chi1 huo3 guo1";

int main() {
	int ans = 0, line = 0, st;
	string t;
	while (true) {
		getline(cin, t);
		if (t == ".") break;
		line ++;
		for (int i = 0; i < t.size(); i ++) {
			int cnt = 0;
			for (int j = 0, ti = i; j < b.size() && ti < t.size(); j ++, ti ++) {
				if (b[j] != t[ti]) break;
				cnt ++;
			}
			if (cnt == b.size()) {
				if (!ans) st = line;
				ans ++;
				break;
			}
		}
	}
	cout << endl;
	cout << line << "\n";
	if (!ans) {
		cout << "-_-#";
	} else { 
		cout << ans << " " << st;
	}
}