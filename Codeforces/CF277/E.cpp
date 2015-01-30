#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], ans[N], dep[N];
vector<int> f[N], v[N];

int get() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void output(int x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[10]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("E.in", "r", stdin);
	int n;
	n = get();
	REPP(i, 1, n) {
		a[i] = get();
	};
	int tot = 0;
	REPP(i, 1, n) {
		int pos = lower_bound(b, b + tot, a[i]) - b;
		b[pos] = a[i];
		dep[i] = pos + 1;
		if (pos == tot) tot++;
		v[pos + 1].push_back(i);
	}
	int mx = 0;
	REPP(i, 1, n) {
		mx = max(mx, dep[i]);
	}
	f[mx] = v[mx];
	for (int i = mx; i >= 1; i --) {
		for (auto it: f[i]) ans[it] = 1;
		if (v[i - 1].size()) {
			int n = f[i].size();
			vector<int> val(n);
			REP(j, n) val[j] = a[f[i][j]];
			for (int j = n - 2; j >= 0; j --) {
				val[j] = max(val[j + 1], val[j]);
			}
			for (auto it: v[i - 1]) {
				int tmp = lower_bound(f[i].begin(), f[i].end(), it) - f[i].begin();
				if (tmp < n && val[tmp] > a[it]) {
					f[i - 1].push_back(it);
				}
			}
		}
	}
	REPP(i, 1, mx) {
		if (f[i].size() == 1) {
			ans[f[i][0]] = 2;
		}
	}
	REPP(i, 1, n) putchar((char) (ans[i] + '1'));

	return 0;
}
