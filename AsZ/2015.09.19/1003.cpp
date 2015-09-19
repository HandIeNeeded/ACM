#include <bits/stdc++.h>
#define MAXN 41234
#define LIM 20

using namespace std;

typedef int arrayN[MAXN];

arrayN vis, fir, nxt, e, g, dep;
int f[MAXN][LIM];
int ans = 0, n, num;

void dfsLCA(int u, int fa, int depth)
{
    vis[u] = 1;
    f[u][0] = fa;
    dep[u] = depth;
    for (int p = fir[u]; p; p = nxt[p])
        if (!vis[e[p]])
        {
            dfsLCA(e[p], u, depth + 1);
        }
}

void initLCA()
{
    for (int i = 1; i < LIM; ++i)
        for (int j = 1; j <= n; ++j)
            f[j][i] = f[f[j][i - 1]][i - 1];
}

void dfsG(int x)
{
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != f[x][0])
        {
            dfsG(e[p]);
            g[x] += g[e[p]];
            ans = min(ans, g[e[p]] + 1);
        }
}

int getLCA(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    int tmp = dep[u] - dep[v];
    for (int w = LIM - 1; w >= 0; --w)
        if ((1 << w) <= tmp)
        {
            tmp -= (1 << w);
            u = f[u][w];
        }
    if (u == v) return u;

    for (int w = LIM - 1; w >= 0; --w)
        if (f[u][w] != f[v][w])
        {
            u = f[u][w];
            v = f[v][w];
        }
    return f[u][0];
}

void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}
int main()
{
    //freopen("3.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        int m;
        scanf("%d%d", &n, &m);
        num = 0;
        for (int i = 1; i <= n; ++i)
            fir[i] = g[i] = vis[i] = 0;
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            link(u, v);
            link(v, u);
        }
        dfsLCA(1, 0, 1);
        initLCA();
        for (int i = n; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            int lca = getLCA(u, v);
            g[lca] -= 2;
            g[u]++, g[v]++;
        }
        ans = m - (n - 1) + 1;
        dfsG(1);
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
