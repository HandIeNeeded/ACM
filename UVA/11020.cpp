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

using namespace std;

const int N = 1e5 + 5;

struct point{
	int x, y;

	bool operator < (const point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

multiset<point> candidate;

int main() {
	int t, ca = 1, first = 0;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		candidate.clear();
		if (first++) puts("");
		printf("Case #%d:\n", ca++);
		REPP(i, 1, n) {
			int x, y;
			scanf("%d%d", &x, &y);
			point tmp = {x, y};
			auto it = candidate.lower_bound(tmp);
			if (it == candidate.begin() || (--it)->y >= tmp.y) {
				candidate.insert(tmp);
				it = candidate.upper_bound(tmp);
				while (it != candidate.end() && it->y >= tmp.y) candidate.erase(it++);
			}
			printf("%d\n", int(candidate.size()));
		}
	}

	return 0;
}

