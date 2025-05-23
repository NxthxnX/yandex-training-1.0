#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

struct Block {
	int height;
	int S;
	int type;
	int i;
};

bool block_sorter(Block const& l, Block const& r);

int main() {
	int n, w, l;
	const int BOTTOM = 1, TOP = -1;
	cin >> n >> w >> l;
	vector <Block> blocks(2 * n);

	Block down, up;
	for (int i = 0, x1, y1, z1, x2, y2, z2; i < n; ++i) {
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		down.height = z1;
		down.S = (x2 - x1) * (y2 - y1);
		down.type = BOTTOM;
		down.i = i + 1;
		blocks.at(2 * i) = down;

		up.height = z2;
		up.S = (x2 - x1) * (y2 - y1);
		up.type = TOP;
		up.i = i + 1;
		blocks.at(2 * i + 1) = up;
	}

	sort(blocks.begin(), blocks.end(), &block_sorter);

	int area = 0, numofblocks = 0, nummin = numeric_limits<int>::max();

	for (const Block& layer : blocks) {
		if (layer.type == BOTTOM) {
			++numofblocks;
			area += layer.S;
			if (area == w * l && numofblocks < nummin)
				nummin = numofblocks;
		}
		else if (layer.type == TOP) {
			--numofblocks;
			area -= layer.S;
		}
	}

	set <int> curblocks, ans;
	for (const Block& layer : blocks) {
		if (layer.type == BOTTOM) {
			++numofblocks;
			curblocks.insert(layer.i);
			area += layer.S;
			if (area == w * l && numofblocks == nummin) {
				ans = curblocks;
			}
		}
		else if (layer.type == TOP) {
			--numofblocks;
			curblocks.erase(layer.i);
			area -= layer.S;
		}
	}
	
	if (ans.empty())
		cout << "NO" << endl;
	else {
		cout << "YES" << endl << nummin << endl;
		copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	return 0;
}

bool block_sorter(Block const& l, Block const& r) {
	if (l.height != r.height)
		return l.height < r.height;
	if (l.type != r.type)
		return l.type < r.type;
	return l.i < r.i;
}
