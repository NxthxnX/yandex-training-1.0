#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t, D, n;
	int a = 0, b = 0, c = 0, d = 0, p, q, r, s;

	cin >> t >> D >> n;
	for (int i = 0, x, y; i < n; ++i) {
		a -= t;
		b += t;
		c -= t;
		d += t;

		cin >> x >> y;
		p = (x - y) - D;
		q = (x - y) + D;
		r = (x + y) - D;
		s = (x + y) + D;

		a = max(a, p);
		b = min(b, q);
		c = max(c, r);
		d = min(d, s);
	}

	cout << ((b - a + 1) * (d - c + 1) + 1) / 2 << endl;

	for (int i = a; i <= b; ++i)
		for (int j = c; j <= d; ++j)
			if (abs(i % 2) == abs(j % 2))
				cout << (j + i) / 2 << ' ' << (j - i) / 2 << endl;

	return 0;
}
