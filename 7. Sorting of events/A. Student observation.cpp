#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n, m, ans = 0;
	const int START = -1, FINISH = 1;

	cin >> n >> m;
	vector <pair <int, int> > desks(2 * m);
	for (int i = 0, b, e; i < m; ++i) {
		cin >> b >> e;
		desks.at(2 * i) = make_pair(b, START);
		desks.at(2 * i + 1) = make_pair(e, FINISH);
	}
	sort(desks.begin(), desks.end());

	int num = 0;
	for (int i = 0; i < 2 * m; ++i) {
		if (desks.at(i).second == START) {
			if (num == 0)
				ans += desks.at(i).first - (i == 0 ? 0 : desks.at(i - 1).first + 1);
			++num;
		}
		else if (desks.at(i).second == FINISH)
			--num;
	}
	ans += n - 1 - desks.at(2 * m - 1).first;

	cout << ans << endl;

	return 0;
}
