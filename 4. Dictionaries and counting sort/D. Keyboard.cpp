#include <iostream>
#include <vector>

int main() {
	int n, k;

	std::cin >> n;
	std::vector <int> mx(n), cur(n, 0);

	for (int i = 0; i < n; ++i) {
		std::cin >> mx.at(i);
	}

	std::cin >> k;

	for (int i = 0, num; i < k; ++i) {
		std::cin >> num;
		++cur.at(num - 1);
	}

	for (int i = 0; i < n; ++i) {
		std::cout << (mx.at(i) < cur.at(i) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
