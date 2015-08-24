#include <bits/stdc++.h>
#define MAXN 212345

using namespace std;

typedef int arrayN[MAXN];

arrayN fir, e, nxt, lab, vis, visF, vispt;
const int powlim = 20;
int num;

struct edge
{
    int u, v;
} ed[MAXN];

void link(int u, int v, int x)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, lab[num] = x;
}

struct node
{
    int f[powlim];
    int lab, dep;
} g[MAXN];

struct ansNode
{
    int u, v;
} ans[MAXN];

void dfs(int x, int fa, int v, int dep)
{
    g[x].f[0] = fa;
    g[x].lab = v;
    vis[v] = 1;
    g[x].dep = dep;
    vispt[x] = 1;
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != fa && !vispt[e[p]])
        {
            dfs(e[p], x, lab[p], dep + 1);
        }
}

void init(int n, int m)
{
    num = 0;
    memset(fir, 0, sizeof(fir));
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < powlim; ++j)
            g[i].f[j] = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; ++i)
        ans[i].u = ans[i].v = -1;
}

int getLca(int u, int v)
{
    if (g[u].dep < g[v].dep) swap(u, v);
    int step = g[u].dep - g[v].dep;
    for (int i = powlim - 1; i >= 0; --i)
        if ((1 << i) <= step)
        {
            u = g[u].f[i];
            step -= (1 << i);
        }
    if (u == v) return u;
    for (int i = powlim - 1; i >= 0; --i)
        if (g[u].f[i] != g[v].f[i])
            u = g[u].f[i], v = g[v].f[i];
    return g[u].f[0];
}

int getfa(int x)
{
    if (x == visF[x]) return visF[x];
    return visF[x] = getfa(visF[x]);
}

void dye(int u, int v, int au, int av)
{
    if (u == v) return ;
    if (g[u].dep < g[v].dep) swap(u, v);
    if (au > av) swap(au, av);
    for (;; )
    {
        u = getfa(u);
        if (g[u].dep <= g[v].dep) break;
        int p = g[u].lab;
        visF[u] = g[u].f[0];
        if (ans[p].u == -1)
        {
            ans[p].u = au;
            ans[p].v = av;
        }
    }
}

int main()
{
    //freopen("d.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n, m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &ed[i].u, &ed[i].v);
            link(ed[i].u, ed[i].v, i);
            link(ed[i].v, ed[i].u, i);
        }
        memset(vispt, 0, sizeof(vispt));
        dfs(1, 0, 0, 1);
        for (int i = 1; i < powlim; ++i)
            for (int j = 1; j <= n; ++j)
                g[j].f[i] = g[g[j].f[i - 1]].f[i - 1];

        for (int i = 1; i <= n; ++i)
            visF[i] = i;
        for (int i = 1; i <= m; ++i)
            ans[i].u = ans[i].v = -1;
        for (int i = 1; i <= m; ++i)
            if (!vis[i])
            {
                int lca = getLca(ed[i].u, ed[i].v);
                dye(ed[i].u, lca, 0, 0);
                dye(ed[i].v, lca, 0, 0);
                ans[i].u = ans[i].v = 0;
            }

        int rt = n;
        for (int i = 1; i <= n; ++i)
            visF[i] = i;

        for (int i = n - 1; i >= 1; --i)
        {
            int lca = getLca(rt, i);
            dye(i, lca, i, i + 1);
            dye(rt, lca, i, i + 1);
            rt = lca;
        }
        for (int i = 1; i <= m; ++i)
            printf("%d %d\n", ans[i].u, ans[i].v);
    }
    return 0;
}
