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

const int N = 2e5 + 5;
int a[N], n;

int cnt[N << 2];
int qx, qd, ql, qr;

void update(int x, int l, int r) {
	if (l == r) {
		cnt[x] += qd;
	}
	else {
		if (ql <= MID) update(LC);
		else update(RC);
		cnt[x] = cnt[L] + cnt[R];
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return cnt[x];
	}
	else {
		int ans = 0;
		if (ql <= MID) ans += query(LC);
		if (qr > MID) ans += query(RC);
		return ans;
	}
}

void go(int &dir, int &now, int &left, int &right, vector<int> &a) {
	while (ZZ
}	

int main() {
	ios :: sync_with_stdio(0);
	freopen("improvements.in", "r", stdin);
	freopen("improvements.out", "w", stdout);
	int ans = 0;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	int dir = 1;
	int left = 0, right = n;
	REPP(i, 0, n) {
		int now = i;
		vector<int> a, b;
		go(dir, now, left, right, a);
		if (now > n) break;
		i = now;
		go(dir, now, left, right, b);
		ans += calc(a, b);
		i = now;
	}
	cout << n - ans << endl;

	return 0;
}

