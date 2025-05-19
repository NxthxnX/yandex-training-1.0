#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	int n;
	std::string a, b, test;
	std::unordered_map <std::string, std::string> unm;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		unm.insert({ a, b });
		unm.insert({ b, a });
	}

	std::cin >> test;

	auto it = unm.find(test);

	std::cout << it->second << std::endl;

	return 0;
}
