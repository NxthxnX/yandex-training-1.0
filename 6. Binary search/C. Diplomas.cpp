#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long w, h, n;
	cin >> w >> h >> n;

	long long l = 0, r = n * max(w, h), m;
	while (r - l > 1) {
		m = (l + r) / 2;
		
		if ((m / w) * (m / h) >= n)
			r = m;
		else
			l = m;
	}

	cout << r << endl;

	return 0;
}
