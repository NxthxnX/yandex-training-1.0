#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n;
	set <string> uni, inter, temp, st;
	string s;

	cin >> n;

	for (int i = 0, m; i < n; ++i) {
		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> s;
			st.insert(s);
		}

		copy(st.begin(), st.end(), inserter(uni, uni.end()));
		if (i == 0)
			copy(st.begin(), st.end(), inserter(temp, temp.end()));
		else
			set_intersection(inter.begin(), inter.end(), st.begin(), st.end(), inserter(temp, temp.end()));

		inter = temp;
		temp.clear();

		st.clear();
	}

	cout << inter.size() << endl;
	for (string lang : inter)
		cout << lang << endl;
	cout << uni.size() << endl;
	for (string lang : uni)
		cout << lang << endl;

	return 0;
}
