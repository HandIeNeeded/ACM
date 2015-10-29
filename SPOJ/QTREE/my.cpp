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

const int N = 2e5 + 5;
int dep[N], son[N], size[N], top[N], pre[N], pos[N], val[N], inv[N];
int now, a[N << 2], sx[N], sy[N], n;
int ql, qr, qx, qd;

vector<pair<int, int> > edge[N];

void dfs(int x, int cost = 0, int p = 0) {
    pre[x] = p, size[x] = 1, son[x] = 0, dep[x] = dep[p] + 1, val[x] = cost;
    REP(i, edge[x].size()) {
        int y = edge[x][i].first, z = edge[x][i].second;
        if (y != p) {
            dfs(y, z, x);
            size[x] += size[y];
            if (size[y] > size[son[x]]) son[x] = y;
        }
    }
}

void divide(int x, int tp) {
    inv[now] = x, pos[x] = now++, top[x] = tp;
    if (son[x]) divide(son[x], tp);
    REP(i, edge[x].size()) {
        int y = edge[x][i].first;
        if (y != pre[x] && y != son[x]) {
            divide(y, y);
        }
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        a[x] = val[inv[l]];
    }
    else {
        build(LC), build(RC);
        a[x] = max(a[L], a[R]);
    }
}

void modify(int x, int l, int r) {
    if (l == r) {
        a[x] = qd;
    }
    else {
        if (qx <= MID) modify(LC);
        else modify(RC);
        a[x] = max(a[L], a[R]);
    }
}

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return a[x];
    }
    else {
        int ans = 0;
        if (ql <= MID) ans = max(ans, query(LC));
        if (qr > MID) ans = max(ans, query(RC));
        return ans;
    }
}

int query(int a, int b) {
    int ans = 0;
    while (top[a] - top[b]) {
        if (dep[top[a]] > dep[top[b]]) {
            swap(a, b);
        }
        ql = pos[top[b]], qr = pos[b];
        ans = max(ans, query(1, 1, n));
        b = pre[top[b]];
    }
    if (a == b) return ans;
    if (dep[a] > dep[b]) swap(a, b);
    ql = pos[son[a]], qr = pos[b];
    ans = max(ans, query(1, 1, n));
    return ans;
}

void init() {
    now = 1;
    dfs(1), divide(1, 1);
    build(1, 1, n);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REPP(i, 1, n) edge[i].clear();
        REPP(i, 1, n - 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edge[x].push_back(make_pair(y, z));
            edge[y].push_back(make_pair(x, z));
            sx[i] = x, sy[i] = y;
        }
        init();
        char s[10];
        while (scanf("%s", s)) {
            if (s[0] == 'D') break;
            if (s[0] == 'Q') {
                int a, b;
                scanf("%d%d", &a, &b);
                printf("%d\n", query(a, b));
            }
            else {
                int a, b;
                scanf("%d%d", &a, &b);
                int x = sx[a], y = sy[a];
                if (dep[x] > dep[y]) swap(x, y);
                qx = pos[y], qd = b;
                modify(1, 1, n);
            }
        }
    }
    return 0;
}

