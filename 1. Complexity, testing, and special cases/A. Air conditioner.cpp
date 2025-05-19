#include <iostream>

int main() {
	int troom, tcond;
	std::string mode;
	std::cin >> troom >> tcond >> mode;
	if (mode == "freeze") {
		std::cout << std::min(troom, tcond) << std::endl;
	}
	else if (mode == "heat") {
		std::cout << std::max(troom, tcond) << std::endl;
	}
	else if (mode == "auto") {
		std::cout << tcond << std::endl;
	}
	else if (mode == "fan") {
		std::cout << troom << std::endl;
	}
	else {
		std::cout << "Unknown error" << std::endl;
	}
	return 0;
}
