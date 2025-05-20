#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	int n, k, numofk = 0;
	unordered_map <char, int> lttrs;
	queue <char> substr;
	cin >> n >> k;
	for (char c = 'a'; c <= 'z'; ++c)
		lttrs.insert({ c, 0 });

	int l = 0, r = -1, lans = 0, rans = 0;
	char c;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (lttrs.at(c) == k)
			++numofk;
		++lttrs.at(c);
		++r;

		substr.push(c);

		while (numofk >= 1) {
			char frst = substr.front();
			if (lttrs.at(frst) == k + 1)
				--numofk;
			--lttrs.at(frst);
			substr.pop();
			++l;
		}

		if (r - l > rans - lans) {
			lans = l;
			rans = r;
		}
	}

	cout << rans - lans + 1 << ' ' << lans + 1 << endl;

	return 0;
}
