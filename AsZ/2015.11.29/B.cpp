#include <bits/stdc++.h>
#define MAXN 512345

#define ll long long

using namespace std;

int N, base;

const int lim = 20;
ll seg[MAXN * 4];
int vis[MAXN], dfsl[MAXN], dfsr[MAXN], e[MAXN];
int now, dep[MAXN], f[MAXN][21], fir[MAXN], nxt[MAXN];
const int MO = 1e9 + 7;

ll askSeg(int x) {
    x = dfsl[x];
    x += base;
    ll tmp = 0;
    for (; x; x >>= 1)
        tmp += seg[x];
    return tmp;
}

int getlca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int w = lim - 1; w >= 0; --w)
        if (dep[u] - dep[v] >= (1 << w)) {
            u = f[u][w];
        }
    if (u == v) return u;
    for (int w = lim - 1; w >= 0; --w)
        if (f[u][w] != f[v][w])
            u = f[u][w], v = f[v][w];
    return f[u][0];
}

ll ask(int u, int v) {
    int lca = getlca(u, v);
    return askSeg(u) + askSeg(v) - askSeg(lca);
}

void modify(int u, int v) {
    int l = dfsl[u];
    int r = dfsr[u];
    l += base - 1;
    r += base + 1;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1) {
        if (!(l & 1)) seg[l + 1] += v;
        if (r & 1) seg[r - 1] += v;
    }
}

void dfs(int x) {
    dfsl[x] = ++now;
    vis[x] = 1;
    for (int p = fir[x]; p; p = nxt[p])
        if (!vis[e[p]]) {
            dfs(e[p]);
        }
    dfsr[x] = now;
}
//deque <int> deq;
void getdfslr() {
    now = 0;
    dfs(1);
}

int num;

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif // HOME
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        u++, v++;
        link(u, v);
        f[v][0] = u;
    }
    for (base = 1; base <= N + 1; base <<= 1);
    getdfslr();
    dep[1] = 1;
    for (int i = 2; i <= N; ++i)
        dep[i] = dep[f[i][0]] + 1;
    for (int w = 1; w < lim; ++w)
        for (int i = 1; i <= N; ++i)
            f[i][w] = f[f[i][w - 1]][w - 1];


    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        modify(i, x);
    }

    int Q;
    scanf("%d", &Q);
    for (; Q; --Q) {
        int K, x1, y1, A, B, C, D, u, v;
        scanf("%d%d%d%d%d%d%d%d%d", &K, &x1, &y1, &A, &B, &C, &D, &u, &v);
        modify(x1 + 1, y1);
        for (int i = 2; i <= K; ++i) {
            x1 = (1LL * A * x1 + B) % N;
            y1 = (1LL * C * y1 + D) % MO;
            modify(x1 + 1, y1);
        }
        printf("%lld\n", ask(u + 1, v + 1));
    }
    return 0;
}

