#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
	if (d > e)
		swap(d, e);

	if (b <= e && a <= d)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
