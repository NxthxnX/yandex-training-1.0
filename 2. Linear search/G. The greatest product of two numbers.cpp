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

	long long mn1 = 0, mn2 = 0, mx1 = 0, mx2 = 0, a;
	vector <long long> v;

	while (ss >> a) {
		v.push_back(a);
	}

	if (v.size() == 2) {
		if (v.at(0) > v.at(1))
			swap(v.at(0), v.at(1));
		cout << v.at(0) << ' ' << v.at(1) << endl;
	}
	else {
		for (long long el : v) {
			if (el > mx1) {
				mx2 = mx1;
				mx1 = el;
			}
			else if (el > mx2)
				mx2 = el;

			if (el < mn1) {
				mn2 = mn1;
				mn1 = el;
			}
			else if (el < mn2)
				mn2 = el;
		}
		if (mx1 * mx2 > mn1 * mn2)
			cout << mx2 << ' ' << mx1 << endl;
		else
			cout << mn1 << ' ' << mn2 << endl;
	}

	return 0;
}
