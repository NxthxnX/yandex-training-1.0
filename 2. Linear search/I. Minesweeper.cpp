#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector <vector <int> > v(n + 2, vector <int>(m + 2, 0));
	vector <int> dx = { 1, 1, 1, 0, 0, -1, -1, -1 }, dy = { 1, 0, -1, 1, -1, 1, 0, -1 };

	for (int i = 0, x, y; i < k; ++i) {
		cin >> x >> y;
		for (int j = 0; j < 8; ++j)
			++v.at(x + dx.at(j)).at(y + dy.at(j));
		v.at(x).at(y) = -9;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if (v.at(i).at(j) < 0)
				cout << '*' << ' ';
			else
				cout << v.at(i).at(j) << ' ';
		cout << endl;
	}

	return 0;
}
