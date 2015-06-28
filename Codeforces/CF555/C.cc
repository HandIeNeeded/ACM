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
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 8e5 + 5;

struct Segment{
	int mx[N << 2], flag[N << 2];

	void push(int x, int l, int r) {
		flag[L] = max(flag[L], flag[x]), flag[R] = max(flag[R], flag[x]);
		mx[L] = max(mx[L], flag[x]), mx[R] = max(mx[R], flag[x]);
		flag[x] = 0;
	}

	int query(int x, int l, int r, int qx) {
		if (l == r) {
			return mx[x];
		}
		else {
			if (flag[x]) push(x, l, r);
			if (qx <= MID) return query(LC, qx);
			else return query(RC, qx);
		}
	}

	void update(int x, int l, int r, int ql, int qr, int qd) {
		if (qr < ql) return;
		if (ql <= l && qr >= r) {
			mx[x] = max(mx[x], qd);
			flag[x] = max(flag[x], qd);
		}
		else {
			if (flag[x]) push(x, l, r);
			if (ql <= MID) update(LC, ql, qr, qd);
			if (qr > MID) update(RC, ql, qr, qd);
			mx[x] = max(mx[L], mx[R]);
		}
	}
}A, B;

int a[N], b[N], c[N];

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
    ios :: sync_with_stdio(0);
	vector<int> num;
	int tot;
	int n, m;
	cin >> n >> m;
	REPP(i, 1, m) {
		int x, y;
		char s[2];
		cin >> x >> y >> s;
		a[i] = x, b[i] = y, c[i] = s[0] == 'U';
		num.push_back(x), num.push_back(y);
		num.push_back(x + 1), num.push_back(y + 1);
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	tot = num.size();
	REPP(i, 1, m) {
		int row = b[i], col = a[i];
		col = lower_bound(num.begin(), num.end(), col) - num.begin() + 1;
		row = lower_bound(num.begin(), num.end(), row) - num.begin() + 1;
		if (c[i] == 1) {
			int tmp = A.query(1, 1, tot, col);
			out(b[i] - tmp);
			int ql = tmp + 1, qr = row, qd = a[i];
			ql = lower_bound(num.begin(), num.end(), ql) - num.begin() + 1;
			B.update(1, 1, tot, ql, qr, qd);
			A.update(1, 1, tot, col, col, b[i]);
		}
		else {
			int tmp = B.query(1, 1, tot, row);
			out(a[i] - tmp);
			int ql = tmp + 1, qr = col, qd = b[i];
			ql = lower_bound(num.begin(), num.end(), ql) - num.begin() + 1;
			A.update(1, 1, tot, ql, qr, qd);
			B.update(1, 1, tot, row, row, a[i]);
		}
	}

    return 0;
}
