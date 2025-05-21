#include <iostream>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	long long l = -1, r = a + b, m;
	while (r - l > 1) {
		m = (l + r) / 2;

		if (2 * (a * 2 + b * 3 + c * 4 + m * 5) / (a + b + c + m) >= 7)
			r = m;
		else
			l = m;
	}

	cout << r << endl;

	return 0;
}
