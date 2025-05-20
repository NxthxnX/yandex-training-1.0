#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long r, ans = 0;
	cin >> n >> r;
	vector <long long> d(n);
	for (int i = 0; i < n; ++i)
		cin >> d.at(i);

	int i = 0, j = 1;
	while (j < n) {
		if (d.at(j) - d.at(i) > r) {
			ans += static_cast<long long>(n - j);
			++i;
		}
		else
			++j;
	}

	cout << ans << endl;

	return 0;
}
