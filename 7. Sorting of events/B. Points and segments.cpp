#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n, m;
	const int START = -1, FINISH = 1, DOT = 0;

	cin >> n >> m;
	vector <pair <pair <int, int>, int> > dots(2 * n + m);
	vector <int> ans(m);
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		dots.at(2 * i) = make_pair(make_pair(min(a, b), START), 0);
		dots.at(2 * i + 1) = make_pair(make_pair(max(a, b), FINISH), 0);
	}
	for (int i = 0, d; i < m; ++i) {
		cin >> d;
		dots.at(2 * n + i) = make_pair(make_pair(d, DOT), i);
	}
	sort(dots.begin(), dots.end());

	int num = 0;
	for (auto& [dot, i] : dots) {
		if (dot.second == START)
			++num;
		else if (dot.second == FINISH)
			--num;
		else if (dot.second == DOT)
			ans.at(i) = num;
	}

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
