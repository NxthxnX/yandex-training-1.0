#include <iostream>

using namespace std;

int main() {
	int a, b, n, m, min1, min2, max1, max2, mn, mx;
	cin >> a >> b >> n >> m;

	min1 = n + (n - 1) * a;
	max1 = n + (n + 1) * a;
	min2 = m + (m - 1) * b;
	max2 = m + (m + 1) * b;

	mn = max(min1, min2);
	mx = min(max1, max2);

	if (mn > mx)
		cout << -1 << endl;
	else
		cout << mn << ' ' << mx << endl;

	return 0;
}
