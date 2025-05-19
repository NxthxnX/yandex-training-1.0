#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	bool exist = true;
	cin >> a >> b >> c;

	if (a + b <= c)
		exist = false;
	if (b + c <= a)
		exist = false;
	if (c + a <= b)
		exist = false;

	cout << (exist ? "YES" : "NO") << endl;
	
	return 0;
}
