#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int n, m, nighttrip = 0, freebuses;
	const int START = 1, FINISH = -1;
	cin >> n >> m;
	vector <int> cities(n, 0), in(n, 0), out(n, 0);
	vector <pair <pair <int, int>, int> > trips(2 * m);
	
	stringstream ss;
	char colon;
	for (int i = 0, f, g; i < m; ++i) {
		string x, y;
		int h, m, time1, time2;
		cin >> f >> x >> g >> y;

		ss << x;
		ss >> h >> colon >> m;
		ss.str(string{});
		ss.clear();
		time1 = h * 60 + m;
		trips.at(2 * i) = make_pair(make_pair(time1, f - 1), START);
		++in.at(f - 1);

		ss << y;
		ss >> h >> colon >> m;
		ss.str(string{});
		ss.clear();
		time2 = h * 60 + m;
		trips.at(2 * i + 1) = make_pair(make_pair(time2, g - 1), FINISH);
		++out.at(g - 1);

		if (time2 < time1)
			++nighttrip;
	}

	bool available = true;
	for (int i = 0; i < n; ++i) {
		if (in.at(i) != out.at(i))
			available = false;
	}

	if (available) {
		sort(trips.begin(), trips.end());

		for (const auto& [bustrip, type] : trips) {
			if (type == START) {
				if (cities.at(bustrip.second) > 0)
					--cities.at(bustrip.second);
			}
			else if (type == FINISH)
				++cities.at(bustrip.second);
		}

		freebuses = reduce(cities.begin(), cities.end());

		cout << freebuses + nighttrip << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}
