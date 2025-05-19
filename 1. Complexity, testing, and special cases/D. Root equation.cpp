#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	bool exist = true;
	cin >> a >> b >> c;

	if (c < 0 || a == 0 && b != c * c)
		cout << "NO SOLUTION" << endl;
	else if (a == 0 && b == c * c)
		cout << "MANY SOLUTIONS" << endl;
	else if ((c * c - b) % a)
		cout << "NO SOLUTION" << endl;
	else
		cout << (c * c - b) / a << endl;
	
	return 0;
}
