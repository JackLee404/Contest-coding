#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
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


void solve() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int n, n1 = 0, n2 = 0;
	cin >> n;
	rep (i, 1, n) {
		int t;
		cin >> t;
		if (i == 1) n1 = n2 = t;
		else {
			n1 &= t;

			n2 |= t;
		}
	}
	// cout << n1 << " " << n2 << endl;
	cout << n2 - n1 << endl;
}


int main() {
	IOS
	int _;
	cin >> _;
	while (_ --) {
		solve();	
	}
}