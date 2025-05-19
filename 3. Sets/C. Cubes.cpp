#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
	int n, m;
	int a;

	std::cin >> n >> m;

	std::set<int> s1, s2, res, res1, res2;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		s1.insert(a);
	}

	for (int i = 0; i < m; ++i) {
		std::cin >> a;
		s2.insert(a);
	}

	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(res, res.end()));

	std::cout << res.size() << std::endl;
	for (int a : res)
		std::cout << a << ' ';
	std::cout << std::endl;

	std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(res1, res1.end()));

	std::cout << res1.size() << std::endl;
	for (int a : res1)
		std::cout << a << ' ';
	std::cout << std::endl;

	std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), std::inserter(res2, res2.end()));

	std::cout << res2.size() << std::endl;
	for (int a : res2)
		std::cout << a << ' ';
	std::cout << std::endl;

	return 0;
}
