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
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int MO = 1e9 + 7;
const int N = 2e5 + 5;

struct Unit{
	int sum, s, add, cnt;
}p[(N << 2) + 5];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int go(int x) {
	return 1LL * x * (x + 1) * (x + 2) / 6 % MO;
}

void calc(int left, int right, int now, int &sum, int &s, int &add, int &cnt) {
	cnt = 2;
	add = (now - left + 1) * 2 + 2;
	s = 1LL * (now - left + 1) * (now - left + 2) % MO;
	sum = go(right - left + 1);
   	::add(sum, MO - go(now - left));
	::add(sum, sum);
}

void push(int x, int l, int r) {
	add(p[L].cnt, p[x].cnt), add(p[L].add, p[x].add), add(p[L].s, p[x].s);
	add(p[L].sum, 1LL * p[x].s * (MID - l + 1) % MO);
	add(p[L].sum, 1LL * p[x].add * (1LL * (MID - l + 1) * (MID - l) / 2 % MO) % MO);
	add(p[L].sum, 1LL * p[x].cnt * (1LL * (MID - l + 1) * (MID - l) * (MID - l - 1) / 6 % MO) % MO);
	int tmp = p[x].add; 
	add(tmp, 1LL * (MID - l + 1) * p[x].cnt % MO);
	int tmps = p[x].s;
   	add(tmps, 1LL * p[x].add * (MID - l + 1) % MO), add(tmps, 1LL * p[x].cnt * (1LL * (MID - l + 1) * (MID - l) / 2 % MO) % MO);
	add(p[R].cnt, p[x].cnt), add(p[R].add, tmp), add(p[R].s, tmps);
	add(p[R].sum, 1LL * tmps * (r - MID) % MO);
	add(p[R].sum, 1LL * tmp * (1LL * (r - MID) * (r - MID - 1) / 2 % MO) % MO);
	add(p[R].sum, 1LL * p[x].cnt * (1LL * (r - MID) * (r - MID - 1) * (r - MID - 2) / 6 % MO) % MO);
	p[x].cnt = p[x].add = p[x].s = 0;
}

void update(int x, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		int a, b, c, d;
		calc(ql, r, l, d, a, b, c);
		add(p[x].s, a), add(p[x].add, b), add(p[x].cnt, c);
		add(p[x].sum, d);
	}
	else {
		if (p[x].cnt) push(x, l, r);
		if (ql <= MID) update(LC, ql, qr);
		if (qr > MID) update(RC, ql, qr);
		p[x].sum = p[L].sum, add(p[x].sum, p[R].sum);
	}
}

int query(int x, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return p[x].sum;
	}
	else {
		if (p[x].cnt) push(x, l, r);
		int ans = 0;
		if (ql <= MID) add(ans, query(LC, ql, qr));
		if (qr > MID) add(ans, query(RC, ql, qr));
		return ans;
	}
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

void out(int x) { //int
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
	//freopen("in", "r", stdin);
	int n = in(), q = in();
	while (q--) {
		int ty = in(), x = in(), y = in();
		if (ty == 1) {
			update(1, 1, n, x, y);
		}
		else {
			out(query(1, 1, n, x, y));
		}
	}
    return 0;
}

