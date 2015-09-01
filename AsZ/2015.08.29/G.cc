#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e6 + 5;

LL mx[N * 4 + 5], flag[N * 4 + 5], a[N];
LL sum[N * 4 + 5];

void maintain(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    mx[x] = max(mx[L], mx[R]);
    flag[x] = flag[L] == flag[R] ? flag[L] : 0;
    sum[x] = sum[L] + sum[R];
}

void build(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    if (l == r) {
        mx[x] = a[l], flag[x] = 0, sum[x] = a[l];
    }
    else {
        int MID = ((l + r) >> 1);
        build(LC), build(RC);
        maintain(x, l, r);
    }
}

int ql, qr, qx, qd;

void push(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    int MID = ((l + r) >> 1);
    flag[L] = flag[R] = flag[x];
    mx[L] = mx[R] = flag[x];
    sum[L] = 1LL * (MID - l + 1) * flag[x];
    sum[R] = 1LL * (r - MID) * flag[x];
    flag[x] = 0;
}

void update(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    if (l == r) {
        if (mx[x] > qd) {
            flag[x] = sum[x] = mx[x] = qd;
        }
        return ;
    }
    int MID = ((l + r) >> 1);
    if (ql <= l && qr >= r) {
        if (mx[x] <= qd) {
            return ;
        }
        else {
            update(LC), update(RC);
            maintain(x, l, r);
        }
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        maintain(x, l, r);
    }
}

LL s, ans;

void getMax(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    if (ql <= l && qr >= r) {
        ans = max(ans, mx[x]);
    }
    else {
        int MID = ((l + r) >> 1);
        if (flag[x]) push(x, l, r);
        if (ql <= MID) getMax(LC);
        if (qr > MID) getMax(RC);
    }
}

void querySum(int x, int l, int r) {
    int L = x << 1, R = x << 1 | 1;
    if (ql <= l && qr >= r) {
        s += sum[x];
    }
    else {
        int MID = ((l + r) >> 1);
        if (flag[x]) push(x, l, r);
        if (ql <= MID) querySum(LC);
        if (qr > MID) querySum(RC);
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
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int t;
    t = in();
    while (t--) {
        int n, m;
        n = in(), m = in();
        REPP(i, 1, n) a[i] = in();
        build(1, 1, n);
        int type, x, y;
        while (m--) {
            type = in(), x = in(), y = in();
            if (type == 0) {
                qd = in();
                ql = x, qr = y;
                update(1, 1, n);
            }
            else if (type == 1) {
                ql = x, qr = y;
                ans = 0, getMax(1, 1, n);
                out(ans);
            }
            else {
                ql = x, qr = y;
                s = 0, querySum(1, 1, n);
                out(s);
            }
        }
    }

    return 0;
}

