#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

int main() {
	std::string wrd;
	std::unordered_map <std::string, int> unm;

	while (std::cin >> wrd) {
		if (unm.find(wrd) == unm.end()) {
			unm.insert({ wrd, 0 });
		}
		std::cout << unm.at(wrd) << ' ';
		++unm.at(wrd);
	}
	std::cout << std::endl;

	return 0;
}
