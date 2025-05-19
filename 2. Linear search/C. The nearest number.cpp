#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int n, x, diff = INT_MAX, ans;

	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v.at(i);
	cin >> x;

	for (int a : v)
		if (abs(a - x) < diff) {
			diff = abs(a - x);
			ans = a;
		}

	cout << ans;

	return 0;
}
