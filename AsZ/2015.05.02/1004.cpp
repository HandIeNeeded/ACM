#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 2e5 + 5;
char s[N];
int n, m;

struct Node{
	int l, r;
	Node(int a = 0, int b = 0) :l(a), r(b) {}
	Node operator + (const Node &b) {
		Node res;
		if (r >= b.l) {
			res.l = l;
			res.r = r - b.l + b.r;
		}
		else {
			res.l = l + b.l - r;
			res.r = b.r;
		}
		return res;
	}
}p[N << 2];


int qx, ql, qr, qk;

void build(int x, int l, int r) {
	if (l == r) {
		p[x].l = s[l] == ')';
		p[x].r = 1 - p[x].l;
	}
	else {
		int L = x << 1, R = x << 1 | 1;
		int MID = (l + r) >> 1;
		build(LC), build(RC);
		p[x] = p[L] + p[R];
	}
}

void modify(int x, int l, int r) {
	if (l == r) {
		swap(p[x].l, p[x].r);
	}
	else {
		int L = x << 1, R = x << 1 | 1;
		int MID = (l + r) >> 1;
		if (qx <= MID) modify(LC);
		else modify(RC);
		p[x] = p[L] + p[R];
	}
}

Node query(int x, int l, int r) {
	if (ql > qr) return Node(0, 0);
	if (ql <= l && qr >= r) {
		return p[x];
	}
	else {
		int L = x << 1, R = x << 1 | 1;
		int MID = (l + r) >> 1;
		if (qr <= MID) return query(LC);
		if (ql > MID) return query(RC);
		return query(LC) + query(RC);
	}
}

int l, r;

int work(int mid) {
	ql = l, qr = mid - 1;
	Node ans1 = query(1, 1, n);
	ql = mid + 1, qr = r;
	Node ans2 = query(1, 1, n);
	if (s[mid] == '(') {
		if (ans2.l == 0) return ans1.l + ans1.r + 1;
		if (ans1.r + 1 >= ans2.l) {
			return ans1.l + ans1.r + 1 - ans2.l;
		}
		else {
			return ans1.l;
		}
	}
	else {
		if (ans1.r == 0) return ans1.l + 1;
		if (ans1.r >= ans2.l + 1) {
			return ans1.l + ans1.r - (ans2.l + 1);
		}
		else {
			return ans1.l;
		}
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
	int t;
	//clock_t st = clock();
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	t = get();
	while (t--) {
		n = get();
		m = get();
		scanf("%s", s + 1);
		build(1, 1, n);
		while (m--) {
			int ty;
			ty = get();
			if (ty == 1) {
				qx = get();
				modify(1, 1, n);
				if (s[qx] == '(') s[qx] = ')';
				else s[qx] = '(';
			}
			else {
				l = get(), r = get(), qk = get();
				ql = l, qr = r;
				Node tot = query(1, 1, n);
				if (tot.l + tot.r < qk) {
					putchar('-');
					putchar('1');
					putchar('\n');
					continue;
				}
				int lo = l - 1, hi = r;
				while (lo + 1 < hi) {
					int mid = (lo + hi) >> 1;
					if (work(mid) < qk) lo = mid;
					else hi = mid;
				}
				output(hi);
			}
		}
	}
	//clock_t ed = clock();
	//cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;

	return 0;
}

