#include <bits/stdc++.h>
#define MAXN 31234
#define MAXM 212345

using namespace std;

typedef int arrayN[MAXN], arrayM[MAXM];

struct edge
{
    int u, v, vis;
} ed[MAXM];

struct query
{
    int k, lab, u, v;
} g[MAXM];

vector <int> id[MAXM];

map < pair <int, int>, int > mp;

int num, n, m, top, cnt;
arrayN fir, belong, dfn, low;
arrayM e, nxt, vis;

struct tarjanNode
{
    int fa;
} tj[MAXN];

void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
    vis[num] = 0;
}

vector < pair <int, int> > slack;

void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++top;
    tj[x].fa = fa;
    for (int p = fir[x]; p; p = nxt[p])
        if (!vis[p] && dfn[e[p]] <= dfn[x])
        {
            vis[p] = vis[p ^ 1] = 1;
            slack.push_back(make_pair(x, e[p]));
            if (!dfn[e[p]])
            {
                tarjan(e[p], x);
                low[x] = min(low[x], low[e[p]]);
                if (low[e[p]] >= dfn[x])
                {
                    for (;;)
                    {
                        int u = slack.back().first;
                        int v = slack.back().second;
                        belong[u] = belong[v] = cnt;
                        slack.pop_back();
                        if (u == x && v == e[p]) break;
                    }
                }
            } else low[x] = min(low[x], dfn[e[p]]);
        }
}

void getBridge()
{
    num = 1;
    for (int i = 1; i <= m; ++i)
        if (ed[i].vis)
        {
            link(ed[i].u, ed[i].v);
            link(ed[i].v, ed[i].u);
        }
    for (int i = 1; i <= n; ++i)
        low[i] = dfn[i] = 0;
    cnt = 0;
    tarjan(1, 0);

    for (int i = 1; i <= n; ++i)
        if (low[i] > dfn[tj[j].fa])
            link1(belong[i], belong[tj[j].fa]);

}

int main()
{
    freopen("1009.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        printf("Case #%d:\n", ca);
        int q;
        scanf("%d%d%d", &n, &m, &q);
        num = 0;
        int tot = 0;
        for (int i = 1; i <= n; ++i)
            fir[i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ed[i].u = u, ed[i].v = v;
            ed[i].vis = 1;
            if (!mp.count(make_pair(ed[i].u, ed[i].v)))
                mp[make_pair(ed[i].u, ed[i].v)] = ++tot;
            int p = mp[make_pair(ed[i].u, ed[i].v)];
            id[p].push_back(i);
        }

        for (int i = 1; i <= q; ++i)
        {
            int u, v;
            scanf("%d%d%d", &g[i].k, &g[i].u, &g[i].v);
            if (g[i].k == 1)
            {
                int p = mp[make_pair(u, v)];
                g[i].lab = id[p].back();
                id[p].pop_back();
                ed[g[i].lab].vis = 0;
            }
        }

        getBridge();

    }
    return 0;
}
