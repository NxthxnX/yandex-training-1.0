#include <iostream>

using namespace std;

int main() {
	long long n, m, t;
	cin >> n >> m >> t;

	long long l = 0, r = (min(n, m) + 1) / 2, md;
	while (r - l > 1) {
		md = (r - l) / 2 + l;

		if ((m - 2 * md) * 2 * md + (n - 2 * md) * 2 * md + 4 * md * md <= t)
			l = md;
		else
			r = md;
	}

	cout << l << endl;

	return 0;
}
