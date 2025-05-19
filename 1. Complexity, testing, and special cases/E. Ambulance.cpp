#include <iostream>

using namespace std;

int main() {
	long long k1, p1 = -1, n1 = -1, k2, p2, n2, m;
	bool pdiff = false, ndiff = false;
	bool pwrng = false, nwrng = false;
	cin >> k1 >> m >> k2 >> p2 >> n2;

	//the check for consistency
	if (n2 > m || k2 <= (p2 - 1) * m + (n2 - 1)) {
		pwrng = true;
		nwrng = true;
	}

	for (long long r = 0; r < max(k1, k2) + 1; ++r) {
		long long n2transf = n2 + (p2 - 1) * m;
		if (!(r * (n2transf - 1) < k2 && k2 <= r * n2transf))
			continue;

		long long n1transf = (k1 - 1) / r + 1;
		if (n1 == -1)
			n1 = (n1transf - 1) % m + 1;
		if (p1 == -1)
			p1 = (n1transf - 1) / m + 1;

		if (n1 != (n1transf - 1) % m + 1)
			ndiff = true;
		if (p1 != (n1transf - 1) / m + 1)
			pdiff = true;
	}

	//answer p
	if (pwrng || p1 == -1)
		cout << -1 << ' ';
	else if (pdiff)
		cout << 0 << ' ';
	else
		cout << p1 << ' ';
	//answer n
	if (nwrng || n1 == -1)
		cout << -1 << endl;
	else if (ndiff)
		cout << 0 << endl;
	else
		cout << n1 << endl;

	return 0;
}
