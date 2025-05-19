#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < a)
		swap(a, b);
	if (d < c)
		swap(c, d);

	if (b < d) {
		swap(b, d);
		swap(a, c);
	}

	if (max(a, d) * (b + c) < b * (a + c))
		cout << max(a, d) << ' ' << b + c << endl;
	else
		cout << b << ' ' << a + c << endl;

	return 0;
}
