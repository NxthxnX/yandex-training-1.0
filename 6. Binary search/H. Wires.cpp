#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> wires(n);
	for (int i = 0; i < n; ++i)
		cin >> wires.at(i);

	int l = 0, r = 10000001, m;
	while (r - l > 1) {
		m = (r + l) / 2;
		int sumofk = 0;
		for (int lngth : wires)
			sumofk += lngth / m;

		if (sumofk < k)
			r = m;
		else
			l = m;
	}

	cout << l << endl;

	return 0;
}
