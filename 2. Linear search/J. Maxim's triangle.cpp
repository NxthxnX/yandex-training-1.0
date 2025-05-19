#include <iostream>
#include <iomanip>

int main() {
	const double Lmin = 30, Rmax = 4000;
	double l = Lmin, r = Rmax, pr, cr;
	int n;
	std::string ps;
	std::cin >> n >> pr;
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> cr >> ps;
		if (ps == "closer") {
			if (cr > pr) {
				l = std::max(l, (cr + pr) / 2);
			}
			else if (cr < pr) {
				r = std::min(r, (cr + pr) / 2);
			}
		} 
		else if (ps == "further") {
			if (cr > pr) {
				r = std::min(r, (cr + pr) / 2);
			}
			else if (cr < pr) {
				l = std::max(l, (cr + pr) / 2);				
			}
		}
		else {
			std::cerr << "An error" << std::endl;
		}
		pr = cr;
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	std::cout << l << ' ' << r << std::endl;

	return 0;
}
