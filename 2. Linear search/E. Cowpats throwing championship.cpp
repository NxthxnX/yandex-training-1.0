#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n, mx, mxn, ans = INT_MIN, num = 0;
	cin >> n;
	vector <int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v.at(i);

	mx = *max_element(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
		if (v.at(i) == mx) {
			mxn = i;
			break;
		}

	for (int i = mxn + 1; i < n - 1; ++i)
		if (v.at(i) % 10 == 5 && v.at(i) > v.at(i + 1))
			ans = max(ans, v.at(i));

	sort(v.begin(), v.end(), greater<>());

	for (int i = 1, pos = 0; i < n; ++i) {
		if (ans == v.at(i)) {
			num = (ans == v.at(0)) ? 1 : i + 1;
			break;
		}
	}

	cout << num << endl;

	return 0;
}
