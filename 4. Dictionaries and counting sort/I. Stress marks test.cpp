#include <iostream>
#include <unordered_map>
#include <set>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string str_tolower(string s);

int main() {
    int n, wrng = 0;
    string wrd, lowwrd, task;
    set <string> s{};
    unordered_map <string, set <string> > dict;
    stringstream ss;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> wrd;
        lowwrd = str_tolower(wrd);
        if (dict.find(lowwrd) == dict.end())
            dict.insert({ lowwrd, s });
        dict.at(lowwrd).insert(wrd);
    }

    getline(cin, task);
    getline(cin, task);
    
    ss << task;
    while (ss >> wrd) {
        lowwrd = str_tolower(wrd);
        if (dict.find(lowwrd) != dict.end()) {
            if (dict.at(lowwrd).find(wrd) == dict.at(lowwrd).end())
                ++wrng;
        }
        else {
            int cap = 0;
            for (char c : wrd)
                if (isupper(c))
                    ++cap;
            if (cap != 1)
                ++wrng;
        }
    }

    cout << wrng << endl;

	return 0;
}

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}
