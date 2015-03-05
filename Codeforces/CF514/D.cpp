#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;

int mx[5][N << 2];
int a[5][N];
int n, m, k;

void build(int ty, int x, int l, int r) {
	if (l == r) {
		mx[ty][x] = a[ty][l];
	}
	else {
		build(ty, LC), build(ty, RC);
		mx[ty][x] = max(mx[ty][L], mx[ty][R]);
	}
}

int ql, qr;

int query(int ty, int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[ty][x];
	}
	else {
		int a = 0, b = 0;
		if (ql <= MID) a = query(ty, LC);
		if (qr > MID) b = query(ty, RC);
		return max(a, b);
	}
}

int ans[5];

bool check(int mid) {
	assert(mid > 0);
	REPP(i, 1, n) if (i + mid - 1 <= n) {
		int sum = 0;
		ql = i, qr = i + mid - 1;
		REP(j, m) {
			ans[j] = query(j, 1, 1, n);
			sum += ans[j];
		}
		if (sum <= k) return 1;
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> m >> k;
	REPP(i, 1, n) {
		REP(j, m) {
			cin >> a[j][i];
		}
	}
	REP(i, m) build(i, 1, 1, n);
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	if (l) check(l);
	else {
		REP(i, m) ans[i] = 0;
	}
	REP(i, m) cout << ans[i] << ' ';
	cout << endl;

	return 0;
}


