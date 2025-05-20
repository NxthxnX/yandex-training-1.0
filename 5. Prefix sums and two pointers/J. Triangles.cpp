#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector <pair <long long, long long> > dots(n);
	unordered_map <long long, int> lngth;
	set <pair <long long, long long> > vect;

	for (int i = 0; i < n; ++i)
		cin >> dots.at(i).first >> dots.at(i).second;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long long diff1 = dots.at(i).first - dots.at(j).first;
			long long diff2 = dots.at(i).second - dots.at(j).second;
			long long len = diff1 * diff1 + diff2 * diff2;

			if (lngth.find(len) == lngth.end())
				lngth.insert({ len, 0 });
			++lngth.at(len);

			if (vect.find(make_pair(-diff1, -diff2)) != vect.end())
				--ans;
			vect.insert(make_pair(diff1, diff2));
		}

		for (const auto& [key, value] : lngth)
			ans += value * (value - 1) / 2;

		lngth.clear();
		vect.clear();
	}

	cout << ans << endl;

	return 0;
}
