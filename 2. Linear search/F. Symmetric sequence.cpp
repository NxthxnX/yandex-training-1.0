#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n), ans;
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];


	for (int st = 0; st < n; ++st) {
		int i = st, j = n - 1;
		while (i <= j && v[i] == v[j]) {
			++i;
			--j;
		}
		if (j < i) {
			for (int k = 0; k < st; ++k)
				ans.push_back(v[k]);
			break;
		}
	}
	std::cout << ans.size() << std::endl;

	for (std::vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	return 0;
}
