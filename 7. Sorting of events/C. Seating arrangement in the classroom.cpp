#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	int n, d;
	const int START = -1, FINISH = 1;
	cin >> n >> d;
	vector <pair <pair <int, int>, int> > students(2 * n);
	vector <int> ans(n);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		students.at(2 * i) = make_pair(make_pair(x, START), i);
		students.at(2 * i + 1) = make_pair(make_pair(x + d, FINISH), i);
	}

	sort(students.begin(), students.end());

	int numoftests = 0;
	queue <int> freetests;
	for (auto& [stdnt, i] : students) {
		if (stdnt.second == START) {
			if (freetests.empty()) {
				++numoftests;
				freetests.push(numoftests);
			}
			ans.at(i) = freetests.front();
			freetests.pop();
		}
		else if (stdnt.second == FINISH)
			freetests.push(ans.at(i));
	}

	cout << numoftests << endl;
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
