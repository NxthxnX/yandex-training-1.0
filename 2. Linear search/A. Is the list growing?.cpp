#include <iostream>
#include <string>
#include <sstream>

int main() {
	std::string str;
	std::stringstream ss;

	getline(std::cin, str);
	ss << str;
	
	int a, b;
	bool fl = true;
	ss >> a;
	while (ss >> b) {
		if (b <= a) {
			fl = false;
			break;
		}
		a = b;
	}
	std::cout << (fl ? "YES" : "NO") << std::endl;

	return 0;
}
