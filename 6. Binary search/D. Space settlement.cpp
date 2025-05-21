#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, a, b, w, h, d1, d2;
	cin >> n >> a >> b >> w >> h;

	long long l = 0, r = max(w, h), m;
	while (r - l > 1) {
		m = (l + r) / 2;

		if ((w / (a + 2 * m)) * (h / (b + 2 * m)) >= n)
			l = m;
		else
			r = m;
	}
	d1 = l;

	l = 0, r = max(w, h);
	while (r - l > 1) {
		m = (l + r) / 2;

		if ((w / (b + 2 * m)) * (h / (a + 2 * m)) >= n)
			l = m;
		else
			r = m;
	}
	d2 = l;

	cout << max(d1, d2) << endl;

	return 0;
}
