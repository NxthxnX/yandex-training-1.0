#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	long long sum = 0;
	unordered_map<int, int> unm;

	cin >> n;

	for (int i = 0, w, h; i < n; ++i) {
		cin >> w >> h;
		if (unm.find(w) == unm.end())
			unm.insert({ w, h });
		unm[w] = max(unm[w], h);
	}

	for (const auto& [key, value] : unm)
		sum += static_cast<long long>(value);

	cout << sum << endl;
	
	return 0;
}
