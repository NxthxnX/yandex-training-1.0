#include <iostream>
#include <unordered_map>
#include <set>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string str_tolower(string s);
string str_to_wrds(string s);

int main() {
    int n;
    set <string> keywrds;
    unordered_map <string, int>  wrds, wrdnum;
    string ident, C, D;
    stringstream ss;
    bool cs, numsym;

    cin >> n >> C >> D;
    if (C == "yes")
        cs = true;
    else if (C == "no")
        cs = false;
    if (D == "yes")
        numsym = true;
    else if (D == "no")
        numsym = false;

    for (int i = 0; i < n; ++i) {
        cin >> ident;
        if (!cs)
            ident = str_tolower(ident);
        keywrds.insert(ident);
    }

    cin.ignore();

    while (getline(cin, ident))
        ss << str_to_wrds(ident) << " ";

    int i = 0;
    while (ss >> ident) {
        if (!cs)
            ident = str_tolower(ident);
        if (keywrds.find(ident) != keywrds.end())
            continue;

        if (!numsym && isdigit(ident.at(0)))
            continue;

        bool alldigits = true;
        for (char c : ident)
            if (!isdigit(c))
                alldigits = false;

        if (alldigits)
            continue;

        if (wrds.find(ident) == wrds.end()) {
            wrds.insert({ ident, 0 });
            wrdnum.insert({ ident, i });
        }

        ++wrds.at(ident);

        ++i;
    }

    int mx = 0, mxpos = 0;
    string mxwrd = "";

    for (const auto& [key, value] : wrds)
        if (value > mx || value == mx && mxpos > wrdnum.at(key)) {
            mx = value;
            mxpos = wrdnum.at(key);
            mxwrd = key;
        }

    cout << mxwrd << endl;

	return 0;
}

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}

string str_to_wrds(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return !isalnum(c) && c != '_' ? ' ' : c; });
    return s;
}
