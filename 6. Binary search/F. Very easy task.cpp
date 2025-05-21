#include <iostream>

using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	if (x > y)
		swap(x, y);

	int l = -1, r = (n - 1) * x, m;
	while (r - l > 1) {
		m = (r - l) / 2 + l;

		if (m / x + m / y >= n - 1)
			r = m;
		else
			l = m;
	}

	cout << r + x << endl;

	return 0;
}
