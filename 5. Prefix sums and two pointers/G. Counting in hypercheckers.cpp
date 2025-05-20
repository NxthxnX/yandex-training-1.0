#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	long long k, ans = 0;
	map <long long, int> cards;
	cin >> n >> k;

	for (int i = 0, a; i < n; ++i) {
		cin >> a;
		if (cards.find(a) == cards.end())
			cards.insert({ a , 0 });
		++cards.at(a);
	}

	int l = 0, r = 0;
	long long diff, dubl = 0;
	for (auto it1 = cards.begin(), it2 = cards.begin(); it1 != cards.end(); it1 = next(it1)) {
		while (it2 != cards.end() && it1->first * k >= it2->first) {
			if (it2->second >= 2)
				++dubl;
			it2 = next(it2);
			++r;
		}
		if (it1->second >= 2)
			--dubl;

		diff = static_cast<long long>(r - l);

		ans += (diff - 1) * (diff - 2) * 3;
		ans += dubl * 3;
		if (it1->second >= 2)
			ans += (diff - 1) * 3;
		if (it1->second >= 3)
			++ans;

		++l;
	}

	cout << ans << endl;

	return 0;
}
