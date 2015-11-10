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
int top[N], pos[N], pre[N], son[N], key[N], size[N], dep[N], now;
int fi[N], ne[N << 1], en[N << 1], id[N << 1], edge;

LL a[N << 2], b[N], len[N], val[N << 1];

void add(int x, int y, LL z) {
    ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, val[edge] = z;
}

void dfs(int x, int p) {
    pre[x] = p, size[x] = 1, son[x] = key[x] = len[x] = 0;
    dep[x] = dep[p] + 1;
    for (int go = fi[x]; go; go = ne[go]) {
        int y = en[go];
        if (y != p) {
            dfs(y, x);
            size[x] += size[y];
            if (size[y] > size[son[x]]) {
                son[x] = y;
                key[x] = id[go];
                len[x] = val[go];
            }
        }
    }
}

void divide(int x, int tp, LL num, int idx) {
    b[now] = num, pos[x] = now++;
    top[x] = tp;
    if (son[x]) divide(son[x], tp, len[x], key[x]);
    for (int go = fi[x]; go; go = ne[go]) {
        int y = en[go];
        if (y != pre[x] && y != son[x]) {
            divide(y, y, val[go], id[go]);
        }
    }
}

int cmp(double x) {
    if (fabs(x) < 1e-8) return 0;
    if (x > 0) return 1;
    return -1;
}

void merge(int x, int l, int r) {
    if (a[L] == 0 || a[R] == 0) a[x] = 0;
    else {
        double tmp = 1.0 * a[L] * a[R];
        if (cmp(tmp - 1e18) > 0) {
            a[x] = 0;
        }
        else {
            a[x] = a[L] * a[R];
        }
    }
}

int qx, ql, qr;
LL qd;

void build(int x, int l, int r) {
    if (l == r) {
        a[x] = b[l];
    }
    else {
        build(LC), build(RC);
        merge(x, l, r);
    }
}

void update(int x, int l, int r) {
    if (l == r) {
        a[x] = qd;
    }
    else {
        if (qx <= MID) update(LC);
        if (qx > MID) update(RC);
        merge(x, l, r);
    }
}

LL merge(LL a, LL b) {
    if (!a || !b) return 0;
    if (cmp(1.0 * a * b - 1e18) > 0) return 0;
    return a * b;
}

LL query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return a[x];
    }
    else {
        if (ql > MID) return query(RC);
        if (qr <= MID) return query(LC);
        LL a = query(LC), b = query(RC);
        return merge(a, b);
    }
}

int n, m;

LL query(int a, int b) {
    LL ans = 1;
    while (top[a] - top[b]) {
        if (dep[top[a]] > dep[top[b]]) {
            swap(a, b);
        }
        ql = pos[top[b]], qr = pos[b];
        ans = merge(ans, query(1, 1, n));
        b = pre[top[b]];
    }
    if (a == b) return ans;
    if (dep[a] > dep[b]) {
        swap(a, b);
    }
    ql = pos[son[a]], qr = pos[b];
    ans = merge(ans, query(1, 1, n));
    return ans;
}

int A[N], B[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    edge = now = 1;
    REPP(i, 1, n - 1) {
        LL x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        A[i] = x, B[i] = y;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    b[1] = 1;
    divide(1, 1, 1, 0); //x tp, num id
    build(1, 1, n);
    while (m--) {
        LL type, x, y, z;
        scanf("%lld", &type);
        if (type == 1) {
            scanf("%lld%lld%lld", &x, &y, &z);
            LL ans = query(x, y);
            if (ans == 0) {
                puts("0");
            }
            else {
                printf("%lld\n", z / ans);
            }
        }
        else {
            scanf("%lld%lld", &x, &y);
            qx = max(pos[A[x]], pos[B[x]]), qd = y;
            update(1, 1, n);
        }
    }
    return 0;
}

