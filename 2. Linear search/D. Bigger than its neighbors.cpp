#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
	stringstream ss;
	string s;
	getline(cin, s);
	ss << s;

	int a, ans = 0;
	vector <int> v;

	while (ss >> a) {
		v.push_back(a);
	}

	for (int i = 1; i < v.size() - 1; ++i)
		if (v.at(i) > v.at(i - 1) && v.at(i) > v.at(i + 1))
			++ans;

	cout << ans << endl;

	return 0;
}
