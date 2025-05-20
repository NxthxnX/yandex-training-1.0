#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, sum = 0;
	cin >> n;
	vector <int> sch(n);
	for (int i = 0; i < n; ++i)
		cin >> sch.at(i);

	cin >> m;
	vector <pair <int, int> > ac(m);
	for (int i = 0; i < m; ++i)
		cin >> ac.at(i).first >> ac.at(i).second;

	sort(sch.begin(), sch.end());
	sort(ac.begin(), ac.end(), [](auto& a, auto& b) { return a.second < b.second; });

	int i = 0, j = 0;

	while (i < n) {
		if (ac.at(j).first < sch.at(i))
			++j;
		else {
			sum += ac.at(j).second;
			++i;
		}
	}

	cout << sum << endl;

	return 0;
}
