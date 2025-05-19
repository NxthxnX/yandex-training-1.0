#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

float deter(float a11, float a12, float a21, float a22);
bool eq(float a, float b);

int main() {
	float a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	float det = deter(a, b, c, d), det1 = deter(e, b, f, d), det2 = deter(a, e, c, f);

	if (eq(det, 0)) {
		if (eq(det1, 0) && eq(det2, 0)) {
			if (eq(a, 0) && eq(b, 0) && eq(c, 0) && eq(d, 0)) {
				if (eq(e, 0) && eq(f, 0))
					cout << 5 << endl;
				else
					cout << 0 << endl;
			}
			else if (!eq(a, 0) && !eq(b, 0))
				cout << 1 << ' ' << -a / b << ' ' << e / b << endl;
			else if (!eq(c, 0) && !eq(d, 0))
				cout << 1 << ' ' << -c / d << ' ' << f / d << endl;
			else if (!eq(a, 0) && eq(b, 0))
				cout << 3 << ' ' << e / a << endl;
			else if (eq(a, 0) && !eq(b, 0))
				cout << 4 << ' ' << e / b << endl;
			else if (!eq(c, 0) && eq(d, 0))
				cout << 3 << ' ' << f / c << endl;
			else if (eq(c, 0) && !eq(d, 0))
				cout << 4 << ' ' << f / d << endl;
		}
		else
			cout << 0 << endl;
	}
	else {
		cout << 2 << ' ' << det1 / det << ' ' << det2 / det << endl;
	}

	return 0;
}


float deter(float a11, float a12, float a21, float a22) {
	return a11 * a22 - a12 * a21;
}
bool eq(float a, float b) {
	return fabs(a - b) <= numeric_limits<float>::epsilon() * max(fabs(a), fabs(b));
}
