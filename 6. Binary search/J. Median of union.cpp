#include <iostream>
#include <vector>

using namespace std;

int l_median(const vector <int> &v1, const vector <int> &v2);

int main() {
	int n, l;
	cin >> n >> l;
	vector <vector <int> > nums(n, vector <int>(l));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < l; ++j)
			cin >> nums.at(i).at(j);

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			cout << l_median(nums.at(i), nums.at(j)) << endl;

	return 0;
}

int l_median(const vector <int>& v1, const vector <int>& v2) {
	int size1 = v1.size(), size2 = v2.size();
	vector <int> uni(size1 + size2);
	for (int i = 0, j = 0; i != size1 || j != size2;) {
		if (j == size2 || i != size1 && v1.at(i) < v2.at(j)) {
			uni.at(i + j) = v1.at(i);
			++i;
		}
		else {
			uni.at(i + j) = v2.at(j);
			++j;
		}
	}

	return uni.at((size1 + size2) / 2 - 1);
}
