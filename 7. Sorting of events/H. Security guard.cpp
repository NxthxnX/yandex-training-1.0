#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int k;
	const int START = -1, FINISH = 1;
	cin >> k;
	vector <string> ans(k);

	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		vector <pair <pair <int, int>, int> > guard(2 * n);
		for (int j = 0, a, b; j < n; ++j) {
			cin >> a >> b;
			guard.at(2 * j) = make_pair(make_pair(a, START), j);
			guard.at(2 * j + 1) = make_pair(make_pair(b, FINISH), j);
		}

		sort(guard.begin(), guard.end());

		bool accept = true;
		if (guard.at(0).first.first == 0 && guard.at(2 * n - 1).first.first == 10000) {
			bool isfirst = true;
			int curtime, prevtime = 0;
			set <int> current;
			vector <bool> isonly(n, false);
			for (const auto& [grdian, num] : guard) {
				curtime = grdian.first;
				if (!isfirst && current.empty()) {
					accept = false;
					break;
				}
				isfirst = false;

				if (current.size() == 1 && curtime - prevtime > 0)
					isonly.at(*current.begin()) = true;

				if (grdian.second == START)
					current.insert(num);
				else if (grdian.second == FINISH)
					current.erase(num);

				prevtime = curtime;
			}
			for (bool only : isonly)
				if (!only)
					accept = false;
		}
		else
			accept = false;

		if (accept)
			ans.at(i) = "Accepted";
		else
			ans.at(i) = "Wrong Answer";
	}

	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}
