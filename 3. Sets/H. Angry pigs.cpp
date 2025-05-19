#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	set <int> st;

	cin >> n;
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		st.insert(x);
	}

	cout << st.size() << endl;

	return 0;
}
