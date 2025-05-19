#include <iostream>

using namespace std;

int main() {
	int n, k, m, all, ans = 0, numk;
	cin >> n >> k >> m;
	all = n;

	while (all >= k && k >= m) {
		numk = all / k;
		all %= k;

		ans += k / m * numk;
		all += k % m * numk;
	}
	
	cout << ans;

	return 0;
}
