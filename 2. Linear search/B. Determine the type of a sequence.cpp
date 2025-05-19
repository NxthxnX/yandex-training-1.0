#include <iostream>

using namespace std;

int main() {
	bool cns = true, asc = true, was = true, dsc = true, wds = true;
	int a, b;
	cin >> a;
	while (cin >> b && b != -2000000000) {
		if (a < b) {
			cns = false;
			dsc = false;
			wds = false;
		}
		else if (a > b) {
			cns = false;
			asc = false;
			was = false;
		} 
		else {
			dsc = false;
			asc = false;
		}
		a = b;
	}

	if (cns)
		cout << "CONSTANT" << endl;
	else if (asc)
		cout << "ASCENDING" << endl;
	else if (was)
		cout << "WEAKLY ASCENDING" << endl;
	else if (dsc)
		cout << "DESCENDING" << endl;
	else if (wds)
		cout << "WEAKLY DESCENDING" << endl;
	else
		cout << "RANDOM" << endl;

	return 0;
}
