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

const int N = 1e4 + 5;
int dep[N], dis[N], pre[N][15], L;

struct Edge{
	int ed, next, val;
}e[N << 1];

int start[N], edge;

void add(int x, int y, int z) {
	e[++edge].next = start[x], e[edge].ed = y, e[edge].val = z;
	start[x] = edge;
}

void dfs(int x, int p = 0, int now = 0) {
	dep[x] = dep[p] + 1, dis[x] = now;
	pre[x][0] = p;
	REPP(i, 1, L - 1) pre[x][i] = pre[pre[x][i - 1]][i - 1];
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].ed, z = e[go].val;
		if (y != p) dfs(y, x, now + z);
	}
}

int go(int x, int step) {
	REP(i, L) {
		if (step & (1 << i)) {
			x = pre[x][i];
		}
	}
	return x;
}

int getLCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	x = go(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = L - 1; i >= 0; i--) {
		if (pre[x][i] != pre[y][i]) {
			x = pre[x][i], y = pre[y][i];
		}
	}
	return pre[x][0];
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("II.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) start[i] = 0;
		edge = 0;
		L = 32 - __builtin_clz(n);
		//cout << L << endl;
		REPP(i, 1, n - 1) {
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z), add(y, x, z);
		}
		dfs(1);
		//REPP(i, 1, n) {
		//	cout << i << ' ' << dis[i] << ' ' << dep[i] << endl;
		//}
		char tmp[5];
		while (cin >> tmp) {
			if (tmp[1] == 'O') break;
			else if (tmp[1] == 'I') {
				int x, y, z;
				cin >> x >> y;
				z = getLCA(x, y);
				cout << dis[x] - dis[z] + dis[y] - dis[z] << endl;
			}
			else {
				int x, y, z, k;
				cin >> x >> y >> k;
				z = getLCA(x, y);
				//cout << x << ' ' << y << ' ' << z << "LCA" << endl;
				//cout << k << endl;
				if (dep[x] - dep[z] + 1 >= k) {
					cout << go(x, k - 1) << endl;
				}
				else {
					int length = dep[y] - dep[z];
					k -= dep[x] - dep[z] + 1;
					length -= k;
					//cout << "length" << ' ' << length << endl;
					cout << go(y, length) << endl;
				}
			}
		}
		cout << endl;
	}

    return 0;
}

