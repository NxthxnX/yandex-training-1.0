#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, ans = 0;
	const int START = 1, FINISH = -1;
	cin >> n;
	vector <pair <pair <int, int>, int> > rgstrs;
	for (int i = 0, h1, m1, h2, m2; i < n; ++i) {
		cin >> h1 >> m1 >> h2 >> m2;
		if (h2 * 60 + m2 <= h1 * 60 + m1) {
			rgstrs.push_back(make_pair(make_pair(24, 0), FINISH));
			rgstrs.push_back(make_pair(make_pair(0, 0), START));
		}
		rgstrs.push_back(make_pair(make_pair(h1, m1), START));
		rgstrs.push_back(make_pair(make_pair(h2, m2), FINISH));
	}

	sort(rgstrs.begin(), rgstrs.end());

	int numwork = 0;
	for (int i = 0; i < rgstrs.size(); ++i) {
		if (rgstrs.at(i).second == START)
			++numwork;
		else if (rgstrs.at(i).second == FINISH) {
			if (numwork == n) {
				int time1 = rgstrs.at(i).first.first * 60 + rgstrs.at(i).first.second;
				int time2 = rgstrs.at(i - 1).first.first * 60 + rgstrs.at(i - 1).first.second;
				ans += time1 - time2;
			}
			--numwork;
		}
	}

	cout << ans << endl;

	return 0;
}
