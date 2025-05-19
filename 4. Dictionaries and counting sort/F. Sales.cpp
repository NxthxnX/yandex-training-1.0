#include <iostream>
#include <map>

using namespace std;

int main() {
	string name, prdct;
	long long num;
	map <string, map <string, long long> > data;

	while (cin >> name >> prdct >> num) {
		map <string, long long> inner;
		if (data.find(name) == data.end()) {
			inner.insert({ prdct, num });
			data.insert({ name, inner });
			inner.clear();
		}
		else if (data.at(name).find(prdct) == data.at(name).end())
			data.at(name).insert({ prdct, num });
		else
			data.at(name).at(prdct) += num;
	}

	for (const auto& [key, value] : data) {
		cout << key << ':' << endl;
		for (const auto& [k, v] : value)
			cout << k << ' ' << v << endl;
	}

	return 0;
}
