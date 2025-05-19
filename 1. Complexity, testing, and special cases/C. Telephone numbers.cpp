#include <iostream>

std::string make_num(const std::string& a);

int main() {
	std::string num, testnum;
	std::cin >> num;
	num = make_num(num);
	for (int i = 0; i < 3; ++i) {
		std::cin >> testnum;
		std::cout << ((num == make_num(testnum)) ? "YES" : "NO") << std::endl;
	}
	return 0;
}

std::string make_num(const std::string& a) {
	std::string res{};
	for (char c : a) {
		if (std::isdigit(static_cast<unsigned char>(c)))
			res += c;
	}
	if (res.size() == 8 || res.size() == 11)
		res.erase(0, 1);
	if (res.size() == 7)
		res = "495" + res;
	if (res.size() == 10)
		res = "8" + res;
	if (res.size() != 11)
		res.resize(0);
	return res;
}
