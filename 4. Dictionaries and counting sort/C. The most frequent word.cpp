#include <iostream>
#include <map>
#include <string>

int main() {
	std::string wrd, mxwrd;
	int mxval = 0;
	std::map <std::string, int> m;

	while (std::cin >> wrd) {
		if (m.find(wrd) == m.end())
			m.insert({ wrd, 0 });
		++m.at(wrd);
	}

	for (const auto& [key, value] : m) {
		if (value > mxval) {
			mxwrd = key;
			mxval = value;
		}
	}

	std::cout << mxwrd << std::endl;

	return 0;
}
