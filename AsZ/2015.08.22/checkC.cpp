#include <bits/stdc++.h>
#define MAXN 212345

using namespace std;

typedef int arrayN[MAXN];

int num, ans, now, ptCnt;
arrayN fir, e, nxt, c, vis, flag;
int seg[MAXN * 4], base;

set <int> sss;

struct node
{
    int l, r, f[20], dep, sum;
} g[MAXN];

void link(int u, int v, int w)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, c[num] = w;
}

int getAns(int n)
{
    vector <int> vec;
    for (int i = 1; i <= n; ++i)
        if (vis[i]) vec.push_back(i);
    memset(flag, 0, sizeof(flag));
    int tmp = 0;
    for (int i = 0; i < vec.size(); ++i)
        for (int j = 0; j < i; ++j)
        {
            int u = vec[i], v = vec[j];
            for (; u != v;)
            {
                if (g[u].dep < g[v].dep) swap(u, v);
                if (!flag[u])
                {
                    flag[u] = 1;
                    tmp += g[u].sum - g[g[u].f[0]].sum;
                }
                u = g[u].f[0];
            }
        }
    return tmp;
}

void dfs(int x, int fa, int sum, int dep)
{
    ++now;
    g[x].l = g[x].r = now;
    g[x].f[0] = fa;
    g[x].sum = sum;
    g[x].dep = dep;
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != fa)
        {
            dfs(e[p], x, sum + c[p], dep + 1);
            ++now;
            g[x].r = now;
        }
   // g[x].r = max(now, g[x].r);
}

void getDfsSeqInit(int n)
{
    now = 0;
    dfs(1, 0, 0, 1);
    for (base = 1; base <= now + 2; base <<= 1);
    memset(seg, 0, sizeof(seg));
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j <= n; ++j)
            g[j].f[i] = g[g[j].f[i - 1]].f[i - 1];
}

int main()
{
  freopen("i.in", "r", stdin);

   freopen("istd.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        printf("Case #%d:\n", ca);
        int n, m;
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        memset(fir, 0, sizeof(fir));
        for (int i = 1; i < n; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            //if (u > v) swap(u, v);
            //f[v] = u;
            link(u, v, w);
            link(v, u, w);
        }

        getDfsSeqInit(n);


        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == 1) vis[y] = 1;
            else vis[y] = 0;
            printf("%d\n", getAns(n));
        }
    }
    return 0;
}
