#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n;
  
	vector <int> mount(n), up(n), down(n);
	up.at(0) = 0;
	down.at(0) = 0;
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
    
		mount.at(i) = y;
		if (i != 0) {
			if (mount.at(i) > mount.at(i - 1)) {
				up.at(i) = up.at(i - 1) + abs(mount.at(i) - mount.at(i - 1));
				down.at(i) = down.at(i - 1);
			}
			else {
				up.at(i) = up.at(i - 1);
				down.at(i) = down.at(i - 1) + abs(mount.at(i) - mount.at(i - 1));
			}
		}
	}

	cin >> m;

	for (int i = 0, s, f; i < m; ++i) {
		cin >> s >> f;
		if (f > s)
			cout << up.at(f - 1) - up.at(s - 1) << endl;
		else
			cout << down.at(s - 1) - down.at(f - 1) << endl;
	}

	return 0;
}
