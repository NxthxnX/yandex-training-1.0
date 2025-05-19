#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map <string, long long> acc;
	string oper, name, name2;
	long long sum;
	
	while (cin >> oper) {
		if (oper == "DEPOSIT") {
			cin >> name >> sum;
			if (acc.find(name) == acc.end())
				acc.insert({ name, 0 });
			acc.at(name) += sum;
		}
		if (oper == "WITHDRAW") {
			cin >> name >> sum;
			if (acc.find(name) == acc.end())
				acc.insert({ name, 0 });
			acc.at(name) -= sum;
		}
		if (oper == "BALANCE") {
			cin >> name;
			if (acc.find(name) == acc.end())
				cout << "ERROR" << endl;
			else
				cout << acc.at(name) << endl;
		}
		if (oper == "TRANSFER") {
			cin >> name >> name2 >> sum;
			if (acc.find(name) == acc.end())
				acc.insert({ name, 0 });
			if (acc.find(name2) == acc.end())
				acc.insert({ name2, 0 });
			acc.at(name) -= sum;
			acc.at(name2) += sum;
		}
		if (oper == "INCOME") {
			cin >> sum;
			for (auto& [nme, sm] : acc)
				if (sm >= 0)
					sm = sm * (100 + sum) / 100;
		}
	}

	return 0;
}
