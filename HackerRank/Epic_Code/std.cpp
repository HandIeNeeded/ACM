#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
pair<int, int> p[N];
int n;

bool check(int x) {
	REP(i, n) if (x & (1 << i)) {
		REPP(j, i + 1, n - 1) if (x & (1 << j)) {
			if (p[i].first <= p[j].first && p[i].second >= p[j].second) return 0;
			if (p[j].first <= p[i].first && p[j].second >= p[i].second) return 0;
		}
	}
	return 1;
}

int main() {
    ios :: sync_with_stdio(0);
	cin >> n;
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
	}
	int ans = 0;
	REP(i, 1 << n) {
		if (check(i)) {
			ans = max(ans, __builtin_popcount(i));
		}
	}
	cout << ans << endl;

    return 0;
}
