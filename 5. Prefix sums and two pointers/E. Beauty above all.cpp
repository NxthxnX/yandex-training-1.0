#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, k, cur_colors = 0;
	unordered_map <int, int> trees;
	cin >> n >> k;
	vector <int> clrs(n);

	for (int i = 0; i < n; ++i) {
		cin >> clrs.at(i);
		--clrs.at(i);
	}
	for (int i = 0; i < k; ++i)
		trees.insert({ i, 0 });

	int i = 0, j = -1, imin = 0, jmin = n - 1;
	while (j < n) {
		if (cur_colors < k) {
			++j;
			if (j >= n)
				break;
			if (trees.at(clrs.at(j)) == 0)
				++cur_colors;
			++trees.at(clrs.at(j));
		}
		else {
			if (jmin - imin > j - i) {
				imin = i;
				jmin = j;
			}
			if (trees.at(clrs.at(i)) == 1)
				--cur_colors;
			--trees.at(clrs.at(i));
			++i;
		}
	}

	cout << imin + 1 << ' ' << jmin + 1 << endl;

	return 0;
}
