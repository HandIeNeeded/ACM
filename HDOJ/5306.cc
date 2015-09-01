#include <bits/stdc++.h>

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

int ql, qr, qd;

struct Node{
    int l, r, mx, cover, tag;
    LL sum;
}p[N << 2];

int build(int x, int l, int r) {
    if (l == r) {

    }
    else {
        build(1, 1, n), build(1, 1, n);
        p[x] = p[L] + p[R];
    }
}

void push(int x, int l, int r) {

}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int t = in();
    while (t--) {
        int n = in(), m = in();
        REPP(i, 1, n) a[i] = in();
        build(1, 1, n);
        while (m--) {
            int type = in();
            ql = in(), qr = in();
            if (type == 0) {
                qd = in();
                update(1, 1, n);
            }
            else if (type == 1) {
                out(queryMax(1, 1, n));
            }
            else {
                out(querySum(1, 1, n));
            }
        }
    }

    return 0;
}
