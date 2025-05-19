#include <iostream>
#include <set>
#include <string>
#include <sstream>

int main() {
	int a;
	std::set<int> s;
	std::string str;
	std::stringstream ss;
	std::getline(std::cin, str);
	ss << str;
	while (ss >> a) {
		s.insert(a);
	}
	
	std::cout << s.size() << std::endl;

	return 0;
}
