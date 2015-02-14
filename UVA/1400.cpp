#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<long long, int>

using namespace std;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

const int N = 5e5 + 5;

long long mx[N << 2], sum[N << 2];
PII prefix[N << 2], suffix[N << 2];
pair<int, int> ans[N << 2];
int a[N];

void maintain(int x, int l, int r) {
	if (mx[L] >= mx[R]) {
		ans[x] = ans[L];
		mx[x] = mx[L];
		if (suffix[L].first + prefix[R].first > mx[x]) {
			mx[x] = suffix[L].first + prefix[R].first;
			ans[x] = {suffix[L].second, prefix[R].second};
		}
	}
	else {
		ans[x] = ans[R];
		mx[x] = mx[R];
		if (suffix[L].first + prefix[R].first >= mx[x]) {
			mx[x] = suffix[L].first + prefix[R].first;
			ans[x] = {suffix[L].second, prefix[R].second};
		}
	}
	sum[x] = sum[L] + sum[R];
	prefix[x] = prefix[L].first < prefix[R].first + sum[L] ? (PII) {prefix[R].first + sum[L], prefix[R].second} : prefix[L];
	suffix[x] = suffix[L].first + sum[R] >= suffix[R].first ? (PII) {suffix[L].first + sum[R], suffix[L].second} : suffix[R];
}

void build(int x, int l, int r) {
	if (l == r) {
		mx[x] = sum[x] = a[l];
		ans[x] = {l, r};
		prefix[x] = suffix[x] = {a[l], r}; 
	}
	else {
		build(LC), build(RC);
		maintain(x, l, r);
	}
}

int ql, qr;

struct point{
	long long mx, sum;
	PII suffix, prefix;
	pair<int, int> ans;
};

point merge(point a, point b) {
	if (a.suffix.second < 0) return b;
	if (b.suffix.second < 0) return a;
	point tmp;
	tmp.sum = a.sum + b.sum;
	if (a.mx >= b.mx) {
		tmp = a;
		if (a.suffix.first + b.prefix.first > tmp.mx) {
			tmp.mx = a.suffix.first + b.prefix.first;
			tmp.ans.first = a.suffix.second;
			tmp.ans.second = b.prefix.second;
		}	
	}
	else {
		tmp = b;
		if (a.suffix.first + b.prefix.first >= tmp.mx) {
			tmp.mx = a.suffix.first + b.prefix.first;
			tmp.ans.first = a.suffix.second;
			tmp.ans.second = b.prefix.second;
		}	
	}
	tmp.suffix = a.suffix.first + b.sum >= b.suffix.first ? (PII) {a.suffix.first + b.sum, a.suffix.second} : b.suffix;
	tmp.prefix = b.prefix.first + a.sum > a.prefix.first ? (PII) {b.prefix.first + a.sum, b.prefix.second} : a.prefix;
	return tmp;
}

point query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return {mx[x], sum[x], prefix[x], suffix[x], ans[x]};
	}
	else {
		point ta = {-1, -1, {-1, -1}, {-1, -1}, {-1, -1}}, tb = ta;
		if (ql <= MID) ta = query(LC);
		if (qr > MID) tb = query(RC);
		return merge(ta, tb);
	}
}

int main() {
	freopen("1400.in", "r", stdin);
	int n, m, ca = 1;
	while (scanf("%d%d", &n, &m) > 0) {
		REPP(i, 1, n) scanf("%d", a + i);
		build(1, 1, n);
		printf("Case %d:\n", ca++);
		while (m--) {
			scanf("%d %d", &ql, &qr);
			point ans = query(1, 1, n);
			printf("%d %d\n", ans.ans.first, ans.ans.second);
		}
	}
	return 0;
}
