#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 2e5 + 5;
vector<pair<int, int>> p[N];
int n, m, C;
int a[N << 2], ans[N];
int qx, qd, ql, qr;

void build(int x, int l, int r) {
    if (l == r) a[x] = 0;
    else {
        build(LC), build(RC);
        a[x] = 0;
    }
}

void update(int x, int l, int r){
    if (l == r) {
        a[x] += qd;
    }
    else {
        if (qx <= MID) update(LC);
        if (qx > MID) update(RC);
        a[x] = a[L] + a[R];
    }
}

int query(int x, int l, int r, int num = C) {
    if (l == r) {
        return l;
    }
    else {
        if (a[L] < num) {
            return query(RC, num - a[L]);
        }
        else {
            return query(LC, num);
        }
    }
}

int querySum(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return a[x];
    }
    else {
        int a = 0, b= 0;
        if (ql <= MID) a = querySum(LC);
        if (qr > MID) b= querySum(RC);
        return a + b;
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d%d", &n, &m, &C) > 0) {
        REPP(i, 1, n) p[i].clear();
        REPP(i, 1, m) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            p[a].push_back({c, i});
            p[b + 1].push_back({-c, i});
        }
        build(1, 1, m);
        REPP(i, 1, n) {
            for (auto &now: p[i]) {
                int x, y;
                tie(x, y) = now;
                qx = y, qd = x;
                update(1, 1, m);
            }
            int pos = query(1, 1, m);
            ql = pos + 1, qr = m;
            ans[i] = a[1];
            if (ql <= qr) ans[i] += querySum(1, 1, m);
        }
        REPP(i, 1, n) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}
