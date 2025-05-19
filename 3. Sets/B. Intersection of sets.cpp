#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
	int a;
	std::set<int> s1, s2, res;
	std::string str;
	std::stringstream ss;
	std::getline(std::cin, str);
	ss << str;
	while (ss >> a) {
		s1.insert(a);
	}

	std::getline(std::cin, str);
	ss.str(std::string{});
	ss.clear();
	ss << str;
	while (ss >> a) {
		s2.insert(a);
	}
	
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(res, res.end()));

	for (std::set<int>::iterator it = res.begin(); it != res.end(); it = std::next(it)) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	return 0;
}
