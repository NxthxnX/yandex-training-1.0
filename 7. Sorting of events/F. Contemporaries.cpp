#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n;
	const int START = 1, FINISH = -1;
	vector <set <int> > ans;
	vector <pair <pair <int, int>, int> > dates;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int d1, m1, y1, d2, m2, y2;
		cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
		int brth, ag18, ag80, deth;
		brth = y1 * 10000 + m1 * 100 + d1;
		ag18 = brth + 18 * 10000;
		ag80 = brth + 80 * 10000;
		deth = y2 * 10000 + m2 * 100 + d2;
		if (ag18 >= deth)
			continue;

		dates.push_back(make_pair(make_pair(ag18, START), i + 1));
		dates.push_back(make_pair(make_pair(min(ag80, deth), FINISH), i + 1));
	}

	sort(dates.begin(), dates.end());

	bool isfinish;
	set <int> curppl;
	for (int i = 0; i < dates.size(); ++i) {
		if (dates.at(i).first.second == START) {
			curppl.insert(dates.at(i).second);
			isfinish = false;
		}
		else if (dates.at(i).first.second == FINISH) {
			if (!isfinish)
				ans.push_back(curppl);

			curppl.erase(dates.at(i).second);
			isfinish = true;
		}
	}

	for (const auto& st : ans) {
		copy(st.begin(), st.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	if (ans.empty())
		cout << 0 << endl;

	return 0;
}
