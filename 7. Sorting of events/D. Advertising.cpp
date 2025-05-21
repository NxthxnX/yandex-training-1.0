#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, n;
	const int START = -1, FINISH = 1;
	vector <pair <pair <int, int>, int> > cstmrs;

	cin >> N;
	for (int i = 0, x, y; i < N; ++i) {
		cin >> x >> y;
		if (y - x < 5)
			continue;
		y -= 5;
		cstmrs.push_back(make_pair(make_pair(x, START), i));
		cstmrs.push_back(make_pair(make_pair(y, FINISH), i));
	}
	n = cstmrs.size() / 2;

	sort(cstmrs.begin(), cstmrs.end());

	int num1 = 0, nummax = 0, curtime1;
	pair <int, int> ans = make_pair(1, 6);
	set <int> curcstm;
	for (int i = 0; i < 2 * n; ++i) {
		if (cstmrs.at(i).first.second == START) {
			++num1;
			curcstm.insert(cstmrs.at(i).second);

			curtime1 = cstmrs.at(i).first.first;

			int num2 = 0, num2max = 0, time2max = curtime1 + 5, curtime2;
			for (int j = i + 1; j < 2 * n; ++j) {
				if (cstmrs.at(j).first.second == START) 
					++num2;

				curtime2 = cstmrs.at(j).first.first;

				if (num2 > num2max && curtime2 - curtime1 >= 5) {
					num2max = num2;
					time2max = curtime2;
				}

				if (cstmrs.at(j).first.second == FINISH) {
					if (curcstm.find(cstmrs.at(j).second) != curcstm.end())
						continue;
					--num2;
				}
			}

			if (num1 + num2max > nummax) {
				nummax = num1 + num2max;
				ans = make_pair(curtime1, time2max);
			}
		}

		if (cstmrs.at(i).first.second == FINISH) {
			--num1;
			curcstm.erase(cstmrs.at(i).second);
		}
	}

	cout << nummax << ' ' << ans.first << ' ' << ans.second << endl;

	return 0;
}
