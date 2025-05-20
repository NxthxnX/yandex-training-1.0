#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	vector <int> cars(n + 1), sum(n + 1);
	cars.at(0) = 0;
	sum.at(0) = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> cars.at(i);
		sum.at(i) = cars.at(i) + sum.at(i - 1);
	}

	int i = 0, j = 1;
	while (j <= n) {
		if (sum.at(j) - sum.at(i) == k)
			++ans;
		sum.at(j) - sum.at(i) > k ? ++i : ++j;
	}
	
	cout << ans << endl;

	return 0;
}
