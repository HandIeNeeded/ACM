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
#define LB(x) ((x) & (-(x)))
#define id(x) (((x) + BLK - 1) / BLK)

using namespace std;

const int N = 4e5 + 5;
int tot, BLK;
int s[N];

void add(int x, int d) {
	while (x <= tot) {
		s[x] += d;
		x += LB(x);
	}
}

int query(int x) {
	int ans = 0;
	while (x) {
		ans += s[x];
		x -= LB(x);
	}
	return ans;
}

int h[N], l[N], r[N], n, k;
vector<int> num;
LL ans[N];

struct Q{
	int l, r, id, blk;
}q[N];

bool cmp(const Q &a, const Q &b) {
	return a.blk < b.blk || (a.blk == b.blk && a.r < b.r);
}

int L, R;
LL res;

LL query(int l, int r) {
	if (id(l) != id(L)) {
		REPP(i, 1, tot) s[i] = 0;
		L = 1000000, R = -1, res = 0;
	}
	int bound = id(l) * BLK;
	for (int i = max(R + 1, bound + 1); i <= r; i++) {
		res += query(::r[i]) - query(::l[i] - 1);
		add(h[i], 1);
	}
	LL ans = res;
	for (int i = l; i <= min(r, bound); i++) {
		res += query(::r[i]) - query(::l[i] - 1);
		add(h[i], 1);
	}
	swap(ans, res);
	for (int i = l; i <= min(r, bound); i++) {
		add(h[i], -1);
	}
	return ans;
}

int in() {
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

void out(LL x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[20]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int main() {
	n = in(), k = in();
	REPP(i, 1, n) {
		h[i] = in();
		num.push_back(h[i]);
		num.push_back(h[i] - k);
		num.push_back(h[i] + k);
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	REPP(i, 1, n) {
		l[i] = lower_bound(num.begin(), num.end(), h[i] - k) - num.begin() + 1;
		r[i] = upper_bound(num.begin(), num.end(), h[i] + k) - num.begin();
		h[i] = lower_bound(num.begin(), num.end(), h[i]) - num.begin() + 1;
	}
	tot = num.size();
	BLK = int(sqrt(n + 0.5));
	int q = in();
	REP(i, q) {
		int l = in(), r = in();
		l++, r++;
		::q[i] = (Q) {l, r, i, id(l)};
	}
	sort(::q, ::q + q, cmp);
	L = 1000000, R = -1;
	REP(i, q) {
		ans[::q[i].id] = query(::q[i].l, ::q[i].r);
	}
	REP(i, q) {
		out(ans[i]);
	}
    return 0;
}


