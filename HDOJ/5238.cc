#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 5e4 + 5;
const int M = 19;
const int MO = 29393;
const int prime[4] = {7, 13, 17, 19};

struct Segment{
    int f[4][M];
}p[N << 2];

void add(Segment &res, const Segment &a, const Segment &b) {
    REP(i, 4) {
        REP(j, prime[i]) {
            res.f[i][j] = b.f[i][a.f[i][j]];
        }
    }
}

int ty[N], a[N], n, m;
int qx, qt, qd;

int pow_mod(int x, int y, int MO) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * x * ans % MO;
        y >>= 1;
        x = 1LL * x * x % MO;
    }
    return ans;
}

void getf(Segment &p, int ty, int a) {
    REP(i, 4) {
        if (ty == 0) {
            REP(j, prime[i]) {
                p.f[i][j] = j * a % prime[i];
            }
        }
        else if (ty == 1) {
            REP(j, prime[i]) {
                p.f[i][j] = (j + a) % prime[i];
            }
        }
        else {
			REP(j, prime[i]) {
				p.f[i][j] = pow_mod(j, a, prime[i]);
			}
        }
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        getf(p[x], ty[l], a[l]);
    }
    else {
        build(LC), build(RC);
        add(p[x], p[L], p[R]);
    }
}

void modify(int x, int l, int r) {
    if (l == r) {
        getf(p[x], qt, qd);
    }
    else {
        if (qx <= MID) modify(LC);
        else modify(RC);
        add(p[x], p[L], p[R]);
    }
}

int mp[M][M][M][M];
char s[M];

void init() {
    build(1, 1, n);
    REP(i, MO) {
        int tmp[4];
        REP(j, 4) tmp[j] = i % prime[j];
        mp[tmp[0]][tmp[1]][tmp[2]][tmp[3]] = i;
    }
}

int get(char c) {
    if (c == '*') return 0;
    if (c == '+') return 1;
    if (c == '^') return 2;
    return -1;
}

int stoi(char *s) {
    int ans = 0, now = 0;
    while (s[now]) {
        ans = 10 * ans + s[now++] - '0';
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
    int t, ca = 1;
    t = in();
    while (t--) {
        printf("Case #%d:\n", ca++);
        n = in(), m = in();
        REPP(i, 1, n) {
            scanf("%s", s);
            ty[i] = get(s[0]);
            a[i] = stoi(s + 1);
        }
        init();
        while (m--) {
            int op, x;
            op = in();
            if (op == 1) {
                x = in();
                int tmp[4];
                REP(i, 4) tmp[i] = p[1].f[i][x % prime[i]];
                out(mp[tmp[0]][tmp[1]][tmp[2]][tmp[3]]);
            }
            else {
                scanf("%d%s", &qx, s);
                qt = get(s[0]);
                qd = stoi(s + 1);
                modify(1, 1, n);
            }
        }
    }
    return 0;
}
