#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int mi[N << 2], mx[N << 2], a[N];
int ql, qr, qx, qd;

void build(int x, int l, int r) {
	if (l == r) {
		mi[x] = mx[x] = a[l];
	}
	else {
		build(LC), build(RC);
		mi[x] = min(mi[L], mi[R]);
		mx[x] = max(mx[L], mx[R]);
	}
}

void update(int x, int l, int r) {
	if (l == r) {
		mi[x] = mx[x] = qd;
	}
	else {
		if (qx <= MID) update(LC);
		else update(RC);
		mi[x] = min(mi[L], mi[R]);
		mx[x] = max(mx[L], mx[R]);
	}
}

pair<int, int> ans;

void query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		ans.first = min(ans.first, mi[x]);
		ans.second = max(ans.second, mx[x]);
	}
	else {
		if (ql <= MID) query(LC);
		if (qr > MID) query(RC);
	}
}

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
	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	REPP(i, 1, n) {
		//cin >> a[i];
		scanf("%d", a + i);
	}
	build(1, 1, n);
	int l, r, ll, rr;
	char str[10];
	while (m--) {
		//cin >> str >> l >> r;
		scanf("%s", str);
		scanf("%d%d", &l, &r);
		if (str[0] == 'Q') {
			if (r < 0) {
				//cout << "-1 -1" << endl;
				printf("-1 -1\n");
				continue;
			}
			ql = l;
			ll = l, rr = n + 1;
			while (ll + 1 < rr) {
				qr = (ll + rr) >> 1;
				ans = make_pair(INF, -INF);
				query(1, 1, n);
				if (a[l] - ans.first <= r && ans.second - a[l] <= r) {
					ll = qr;
				}
				else {
					rr = qr;
				}
			}
			qr = ll;
			ans = make_pair(INF, -INF);
			query(1, 1, n);
			//cout << qr - ql + 1 << ' ' << max(a[l] - ans.first, ans.second - a[l]) << endl;
			printf("%d %d\n", qr - ql + 1, max(a[l] - ans.first, ans.second - a[l]));
		}
		else {
			qx = l, qd = r;
			a[l] = r;
			update(1, 1, n);
		}
	}

	return 0;
}
