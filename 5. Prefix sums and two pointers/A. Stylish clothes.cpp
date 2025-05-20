#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int n, m;
	cin >> n;
	vector <int> shirts (n);
	for (int i = 0; i < n; ++i)
		cin >> shirts.at(i);
	cin >> m;
	vector <int> pants(m);
	for (int i = 0; i < m; ++i)
		cin >> pants.at(i);

	int i = 0, j = 0, mindiff = numeric_limits<int>::max(), minsh, minpn;

	while (i < n && j < m) {
		if (abs(shirts.at(i) - pants.at(j)) < mindiff) {
			mindiff = abs(shirts.at(i) - pants.at(j));
			minsh = shirts.at(i);
			minpn = pants.at(j);
		}
		shirts.at(i) < pants.at(j) ? ++i : ++j;
	}

	cout << minsh << ' ' << minpn << endl;

	return 0;
}
