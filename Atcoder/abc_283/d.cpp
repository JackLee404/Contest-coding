#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
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

using namespace std;

int b[30];

int main() {
	int l = -1, s = 0, cnt = 0;
	string t; cin >> t;
	for (int i = 0; i < t.size(); i ++) {
		if (t[i] == ')') {
			memset(b, 0, sizeof b);
			s = 0;
		} else if (t[i] != '(') {
			if (b[t[i] - 'a']) {
				break;	
			} else {
				b[t[i] - 'a'] ++;
				s ++;
			}
		}
	}
	cout << (!s?"Yes":"No") << endl;
}