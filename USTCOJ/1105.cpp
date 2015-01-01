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

struct rectangle{
	int a, b, c, d;
};

struct line{
	int x, up, down, ty;
};

const int N = 65;
int sum[N << 2], cnt[N << 2];
int ql, qr, qd, tot;
vector<int> fac, num;
line l[2 * N];
rectangle p[N];

void maintain(int x, int l, int r) {
	if (cnt[x]) {
		sum[x] = num[r] - num[l - 1];
	}
	else {
		if (l == r) sum[x] = 0;
		else {
			sum[x] = sum[L] + sum[R];
		}
	}
}

void build(int x, int l, int r) {
	if (l == r) {
		sum[x] = cnt[x] = 0;
	}
	else {
		build(LC), build(RC);
		sum[x] = cnt[x] = 0;
	}
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		cnt[x] += qd;
		maintain(x, l, r);
	}
	else {
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		maintain(x, l, r);	
	}
}


bool cmp(const line &a, const line &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.ty > b.ty;
}

int solve() {
	tot = 0;
	REP(i, fac.size()) {
		l[tot++] = (line) { p[fac[i]].a, p[fac[i]].b + 1, p[fac[i]].d, 1 };
		l[tot++] = (line) { p[fac[i]].c, p[fac[i]].b + 1, p[fac[i]].d, -1 };
		num.push_back(p[fac[i]].b + 1);
		num.push_back(p[fac[i]].d);
		num.push_back(p[fac[i]].d + 1);
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	sort(l, l + tot, cmp);
	REP(i, tot) {
		l[i].up = lower_bound(num.begin(), num.end(), l[i].up) - num.begin() + 1;
		l[i].down = lower_bound(num.begin(), num.end(), l[i].down) - num.begin() + 1;
	}
	int n = num.size() - 1;
	build(1, 1, n);
	int ans = 0;
	REP(i, tot) {
		if (i) {
			ans += sum[1] * (l[i].x - l[i - 1].x);
		}
		ql = l[i].up, qr = l[i].down, qd = l[i].ty;
		update(1, 1, n);
	}
	fac.clear(), num.clear();
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	int n, m;
	int ca = 1;
	while (cin >> n >> m, n | m) {
		cout << "Case " << ca++ << ":" << endl;
		REPP(i, 1, n) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			p[i] = (rectangle) {a, b, c, d};
		}
		int t, x;
		REPP(i, 1, m) {
			cin >> t;
			REPP(j, 1, t) {
				cin >> x;
				fac.push_back(x);
			}
			cout << "Query " << i << ": ";
			cout << solve() << endl;
		}
		cout << endl;
	}
	return 0;
}
