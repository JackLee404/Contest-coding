#include <iostream>

using i64 = long long;

int main() {
	int n, pos = 1;

	std::cin >> n;

	for (int i = 0; i < (1<<n); i ++) {
		for (int j = n - 1; j >= 0; j --) {
			std::cout << (i >> j & 1);
		}
		std::cout << " 211.81.216." << "[" << pos << "-" << pos + (1<<8-n) - 3 << "]\n";
		pos += (1<<8-n);
	}

	int ans = 0, t = 7;

	for (int i = 1; i <= n; i ++) {
		ans += 1 << t;
		t --;
	}

	std::cout << "ziwangyanma:" << "211.81.216." << ans;
	
	system("pause");
}