#include <iostream>
#include <set>

int main() {
	int n, a, b;
	std::set<int> s;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		if (a + b != n - 1 || a < 0 || b < 0)
			continue;
		s.insert(a);
	}

	std::cout << s.size() << std::endl;

	return 0;
}
