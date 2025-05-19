#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
	int ans = 0;
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	std::set<std::string> s;
	
	for (int i = 0; i < s2.length() - 1; ++i) {
		s.insert(s2.substr(i, 2));
	}

	for (int i = 0; i < s1.length() - 1; ++i)
		if (s.find(s1.substr(i, 2)) != s.end())
			++ans;

	std::cout << ans << std::endl;

	return 0;
}
