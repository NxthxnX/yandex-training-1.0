#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>

using namespace std;

int numofballons(int T, vector <array <int, 3> >& assist);

int main() {
	int M, N, ans;

	cin >> M >> N;
	vector <array <int, 3> > assist(N);
	vector <int> ansvect(N);

	for (int i = 0, t, z, y; i < N; ++i) {
		cin >> t >> z >> y;
		assist.at(i).at(0) = t;
		assist.at(i).at(1) = z;
		assist.at(i).at(2) = y;
	}

	int l = -1, r = numeric_limits<int>::max(), m;
	for (const auto& arr : assist) {
		int t, z, y;
		t = arr.at(0);
		z = arr.at(1);
		y = arr.at(2);
		r = min(r, (M / z + 1) * (t * z + y));
	}

	while (r - l > 1) {
		m = (l + r) / 2;

		if (numofballons(m, assist) >= M)
			r = m;
		else
			l = m;
	}

	ans = r;

	int i = 0;
	for (const auto& arr : assist) {
		int t, z, y, sect, num, tleft;
		t = arr.at(0);
		z = arr.at(1);
		y = arr.at(2);

		sect = ans / (t * z + y);
		num = sect * z;

		tleft = ans % (t * z + y);
		num += min(z, tleft / t);

		ansvect.at(i++) = num;
	}

	int sum = reduce(ansvect.begin(), ansvect.end()), diff = sum - M;
	for (int& a : ansvect) {
		int temp = min(a, diff);
		a -= temp;
		diff -= temp;
	}
		
	cout << ans << endl;
	copy(ansvect.begin(), ansvect.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}

int numofballons(int T, vector <array <int, 3> >& assist) {
	int ans = 0, i = 0;
	for (const auto& arr : assist) {
		int t, z, y, sect, num, tleft;
		t = arr.at(0);
		z = arr.at(1);
		y = arr.at(2);

		sect = T / (t * z + y);
		num = sect * z;

		tleft = T % (t * z + y);
		num += min(z, tleft / t);

		ans += num;
	}

	return ans;
}
