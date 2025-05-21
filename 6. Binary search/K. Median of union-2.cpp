#include <iostream>
#include <vector>

using namespace std;

int b_search(const vector <int> &v, const int num);

int main() {
	int n, l;
	cin >> n >> l;
	vector <vector <int> > nums(n, vector <int>(l));

	for (int i = 0; i < n; ++i) {
		int x, d, a, c, m;
		cin >> x >> d >> a >> c >> m;
		nums.at(i).at(0) = x;

		for (int j = 1; j < l; ++j) {
			x += d;
			d = (a * d + c) % m;
			nums.at(i).at(j) = x;
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int lft = -1000000001, rt = 1000000000, md;
			while (rt - lft > 1) {
				md = (lft + rt) / 2;
				int sumofl = b_search(nums.at(i), md) + b_search(nums.at(j), md);
				if (sumofl >= l)
					rt = md;
				else
					lft = md;
			}
			cout << rt << endl;
		}

	return 0;
}

int b_search(const vector <int>& v, const int num) {
	int l = -1, r = v.size(), m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (v.at(m) > num)
			r = m;
		else
			l = m;
	}

	return l + 1;
}
