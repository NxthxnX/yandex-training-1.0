#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
	int n;
	char c;
	std::stringstream ss;
	std::set<char> in, s, res;

	for (int i = 0; i < 3; ++i) {
		std::cin >> c;
		in.insert(c);
	}

	std::cin >> n;
	ss << n;

	while (ss >> c)
		s.insert(c);

	std::set_difference(s.begin(), s.end(), in.begin(), in.end(), std::inserter(res, res.end()));

	std::cout << res.size() << std::endl;

	return 0;
}
