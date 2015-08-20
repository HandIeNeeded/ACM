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

const int N = 1 << 13;

int mx[N], a[N], n, tot;

void dfs1(int x) {
	if (x > tot) return ;
	else {
		dfs1(2 * x), dfs1(2 * x + 1);
		mx[x] = max(mx[2 * x] + a[2 * x], mx[2 * x + 1] + a[2 * x + 1]);
	}
}

int ans;

void dfs2(int x, int now) {
	if (x > tot) return ;
	else {
		if (2 * x + 1 <= tot) {
			int add = now - mx[2 * x] - a[2 * x];
			ans += add;
			dfs2(2 * x, now - add - a[2 * x]);
			add = now - mx[2 * x + 1] - a[2 * x + 1];
			ans += add;
			dfs2(2 * x + 1, now - add - a[2 * x + 1]);
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	tot = (1 << (n + 1)) - 1;
	REPP(i, 2, tot) {
		cin >> a[i];
	}
	dfs1(1), dfs2(1, mx[1]);
	cout << ans << endl;

	return 0;
}

