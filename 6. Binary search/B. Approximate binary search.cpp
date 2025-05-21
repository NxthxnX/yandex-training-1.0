#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> elem(n), qstn(k);
	for (int i = 0; i < n; ++i)
		cin >> elem.at(i);
	for (int i = 0; i < k; ++i)
		cin >> qstn.at(i);

	for (int num : qstn) {
		int l = 0, r = n, m;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (elem.at(m) > num)
				r = m;
			else
				l = m;
		}
		if (l == n - 1 || num - elem.at(l) <= elem.at(l + 1) - num)
			cout << elem.at(l) << endl;
		else
			cout << elem.at(l + 1) << endl;
	}

	return 0;
}
