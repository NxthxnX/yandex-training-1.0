#include <iostream>

using namespace std;

int main() {
	int k, prefix = 0;
	long long ans = 0;
	string s;
	cin >> k >> s;
	
	for (int i = k; i < s.length(); ++i) {
		if (s.at(i) == s.at(i - k))
			++prefix;
		else
			prefix = 0;

		ans += static_cast<long long>(prefix);
	}

	cout << ans << endl;

	return 0;
}
