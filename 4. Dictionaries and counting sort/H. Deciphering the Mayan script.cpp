#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	int g, S, num = 0, N = 0, ans = 0;
	char c, ch;
	cin >> g >> S;

	unordered_map <char, int> W, mp;
	queue <char> q;

	for (int i = 0; i < g; ++i) {
		cin >> c;
		if (W.find(c) == W.end()) {
			W.insert({ c, 0 });
			++num;
		}
		++W.at(c);
	}

	for (int i = 0; i < g; ++i) {
		cin >> c;
		if (mp.find(c) == mp.end())
			mp.insert({ c, 0 });
		++mp.at(c);
		q.push(c);
	}
	for (const auto& [sym, no] : W) {
		if (mp.find(sym) == mp.end())
			continue;
		if (mp.at(sym) == W.at(sym))
			++N;
	}
	if (N == num)
		++ans;

	for (int i = g; i < S; ++i) {
		cin >> c;
		if (mp.find(c) == mp.end())
			mp.insert({ c, 0 });

		ch = q.front();
		q.pop();
		q.push(c);

		if (W.find(ch) != W.end() && mp.at(ch) == W.at(ch))
			--N;
		--mp.at(ch);
		if (W.find(ch) != W.end() && mp.at(ch) == W.at(ch))
			++N;

		if (W.find(c) != W.end() && mp.at(c) == W.at(c))
			--N;
		++mp.at(c);
		if (W.find(c) != W.end() && mp.at(c) == W.at(c))
			++N;

		if (N == num)
			++ans;
	}

	cout << ans << endl;

	return 0;
}
