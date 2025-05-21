#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, R, c;
	cin >> n >> R >> c;
	vector <int> heights(n);
	for (int i = 0; i < n; ++i)
		cin >> heights.at(i);

	sort(heights.begin(), heights.end());

	int l = -1, r = *max_element(heights.begin(), heights.end()), m;

	while (r - l > 1) {
		m = (l + r) / 2;
		
		int numofr = 0;
		for (int i = 0; i < n - c + 1; ++i) {
			if (heights.at(i + c - 1) - heights.at(i) <= m) {
				++numofr;
				i += c - 1;
			}
		}
		if (numofr >= R)
			r = m;
		else
			l = m;
	}

	cout << r << endl;

	return 0;
}
