#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

void findheight(string root, const auto& ancestors, auto& height);

int main() {
    int n;

    unordered_map <string, string> ancestors;
    map <string, int> height;

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        string child, parent;
        cin >> child >> parent;
        ancestors.insert({ child, parent });
    }

    for (const auto& [parent, children] : ancestors)
        findheight(parent, ancestors, height);

    for (const auto& [name, count] : height)
        cout << name << ' ' << count << endl;

    return 0;
}

void findheight(string root, const auto& ancestors, auto& height) {
    if (ancestors.find(root) == ancestors.end()) {
        height.insert({ root, 0 });
    }
    else {
        if (height.find(root) == height.end()) {
            findheight(ancestors.at(root), ancestors, height);
            height.insert({ root, height.at(ancestors.at(root)) + 1 });
        }
    }
}
