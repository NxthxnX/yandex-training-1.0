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

	long long mn1 = 0, mn2 = 0, mx1 = 0, mx2 = 0, mx3 = 0, a;
	vector <long long> v;

	while (ss >> a) {
		v.push_back(a);
	}

	if (v.at(0) > v.at(1))
		swap(v.at(0), v.at(1));
	if (v.at(1) > v.at(2))
		swap(v.at(1), v.at(2));
	if (v.at(0) > v.at(1))
		swap(v.at(0), v.at(1));

	mn1 = v.at(0);
	mn2 = v.at(1);
	mx1 = v.at(2);
	mx2 = v.at(1);
	mx3 = v.at(0);

	for (int i = 3; i < v.size(); ++i) {
		if (v.at(i) > mx1) {
			mx3 = mx2;
			mx2 = mx1;
			mx1 = v.at(i);
		}
		else if (v.at(i) > mx2) {
			mx3 = mx2;
			mx2 = v.at(i);
		}
		else if (v.at(i) > mx3)
			mx3 = v.at(i);

		if (v.at(i) < mn1) {
			mn2 = mn1;
			mn1 = v.at(i);
		}
		else if (v.at(i) < mn2)
			mn2 = v.at(i);
	}
	if (mx1 * mx2 * mx3 > mx1 * mn1 * mn2)
		cout << mx3 << ' ' << mx2 << ' ' << mx1 << endl;
	else
		cout << mn1 << ' ' << mn2 << ' ' << mx1 << endl;

	return 0;
}
