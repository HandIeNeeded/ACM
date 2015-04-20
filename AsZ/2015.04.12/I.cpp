#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define uint unsigned int

using namespace std;

const int N = 30005;

struct Unit{
	uint a, b;
	Unit(uint a = 0, uint b = 0) :a(a), b(b) {}
};

vector<Unit> add, dow;

Unit operator + (const Unit &x, const Unit &y) {
	Unit res;
	if (y.a > x.b) add.push_back(x), res = y;
	else {
		res.a = x.a, res.b = y.b;
	}
	return res;
}

Unit operator - (const Unit &x, const Unit &y) {
	if (x.a > x.b) return x;
	Unit res;
	if (x.a < y.a) {
		dow.push_back({x.a, y.a - 1});
	}
	res = {y.b + 1, x.b};
	return res;
}

int main() {
	uint t, ca = 1;
	scanf("%u", &t);
	uint mask = -1;
	cout << mask << endl;
	while (t--) {
		uint n;
		scanf("%u", &n);
		REPP(i, 1, n) {
			uint a, b, c, d, e;
			scanf("%u.%u.%u.%u/%u", &a, &b, &c, &d, &e);
			uint mask;
			if (e == 0) {
				mask = -1;
			}
			else {
				mask = (1u << (32 - e)) - 1;
			}
			mask = ~mask;
			cout << mask << endl;
		}
	}

	return 0;
}

