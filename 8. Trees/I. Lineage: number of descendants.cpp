#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

void countchildren(string root, const auto& descendants, auto& numofchildren);

int main() {
    int n;

    unordered_map <string, set <string> > descendants;
    map <string, int> numofchildren;

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        string child, parent;
        cin >> child >> parent;
        if (descendants.find(parent) == descendants.end())
            descendants.insert({ parent, set<string>{} });
        descendants.at(parent).insert(child);
        descendants.insert({ child, set<string>{} });
    }

    for (const auto& [parent, children] : descendants)
        countchildren(parent, descendants, numofchildren);

    for (const auto& [name, count] : numofchildren)
        cout << name << ' ' << count << endl;

    return 0;
}

void countchildren(string root, const auto& descendants, auto& numofchildren) {
    set <string> children = descendants.at(root);

    if (children.empty()) {
        numofchildren.insert({ root, 0 });
    }
    else {
        if (numofchildren.find(root) == numofchildren.end()) {
            for (string child : children) {
                countchildren(child, descendants, numofchildren);
            }
            numofchildren.insert({ root, 0 });
            for (string child : children) {
                numofchildren.at(root) += numofchildren.at(child) + 1;
            }
        }
    }
}
