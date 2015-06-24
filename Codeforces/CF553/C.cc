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

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;

int f[N];
vector<int> edge[N], e[N];
int a[N], b[N], c[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

int n, m;

bool check() {
	REPP(i, 1, n) f[i] = i;
	REPP(i, 1, m) {
		if (c[i] == 1) {
			int tx = find(a[i]), ty = find(b[i]);
			if (tx != ty) {
				f[tx] = ty;
			}
		}
	}
	REPP(i, 1, n) {
		int x = find(i);
		if (edge[i].size()) {
			REP(j, edge[i].size()) {
				int y = find(edge[i][j]);
				e[x].push_back(y);
			}
		}
	}
	REPP(i, 1, n) {
		if (e[i].size()) {
			int x = e[i][0];
			REP(j, e[i].size()) {
				int y = e[i][j];
				int tx = find(x), ty = find(y);
				if (tx != ty) {
					f[tx] = ty;
				}
			}
		}
	}
	REPP(i, 1, m) {
		if (c[i] == 0) {
			int x = a[i], y = b[i];
			int tx = find(x), ty = find(y);
			if (tx == ty) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
    ios :: sync_with_stdio(0);
	cin >> n >> m;
	REPP(i, 1, n) f[i] = i;
	int cnt = n;
	REPP(i, 1, m) {
		int x, y, z;
		cin >> x >> y >> z;
		a[i] = x, b[i] = y, c[i] = z;
		if (!z) {
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int tx = find(x), ty = find(y);
		if (tx != ty) {
			cnt--;
			f[tx] = ty;
		}
	}
	int ans = pow_mod(2, cnt - 1);
	if (check()) {
		cout << 0 << endl;
	}
	else {
		cout << ans << endl;
	}

    return 0;
}


