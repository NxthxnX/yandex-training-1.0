#include <set>
#include <string>
#include <fstream>

int main() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	std::set<std::string> s;
	std::string a;

	while (fin >> a)
		s.insert(a);

	fout << s.size() << std::endl;

	fin.close();
	fout.close();

	return 0;
}
