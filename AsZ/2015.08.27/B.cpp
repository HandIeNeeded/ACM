#include <bits/stdc++.h>
#define MAXN 212345

using namespace std;
typedef int arrayN[MAXN];

arrayN fir, nxt, e, lab, slk;
int num, last, now, ti = 0, base, high;

struct node
{
    int vis, bigSon, sz;
    int co, fa, dep, rk;
    int top;
} g[MAXN];

struct edge
{
    int u, v, vis;
} ed[MAXN];

int seg[MAXN * 2];

void init(int n, int m)
{
    num = 0;
    for (int i = 1; i <= n; ++i)
        g[i].vis = fir[i] = g[i].bigSon = 0;
    for (int i = 1; i <= m; ++i)
        ed[i].vis = 0;
    g[0].sz = 0;
}

void link(int u, int v, int x)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, lab[num] = x;
    now = last = 0;
}

void dfsBigSonAndColor(int x, int fa, int co, int dep)
{
    g[x].vis = ti;
    g[x].co = co;
    g[x].sz = 1;
    g[x].fa = fa;
    g[x].dep = dep;
    g[x].bigSon = 0;
    for (int p = fir[x]; p; p = nxt[p])
        if (g[e[p]].vis != ti)
        {
            dfsBigSonAndColor(e[p], x, 1 - co, dep + 1);
            g[x].sz += g[e[p]].sz;
            ed[lab[p]].vis = 1;
            if (g[e[p]].sz > g[g[x].bigSon].sz)
                g[x].bigSon = e[p];
        }
}

void dfsHeavyEdge(int x, int fa)
{
    g[x].rk = ++now;
    slk[now] = x;
    g[x].vis = ti;
    if (!g[x].bigSon)
    {
        for (int i = last + 1; i <= now; ++i)
            g[slk[i]].top = slk[last + 1];
        last = now;
        return ;
    }
    dfsHeavyEdge(g[x].bigSon, x);
    for (int p = fir[x]; p; p = nxt[p])
        if (g[e[p]].vis != ti)
            dfsHeavyEdge(e[p], x);
}

/*void makeLazy(int x, int val)
{
    seg[x] += val;
}

/*void pushdown(int x)
{
    for (int i = high - 1; i >= 1; --i)
    {
        int p = x >> i;
        if (seg[p])
            makeLazy(e[])
    }
} */

void add(int l, int r, int val)
{
    if (l > r) return ;
    l += base - 1, r += base + 1;
  //  pushdown(l), pushdown(r);
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
        if (!(l & 1)) seg[l + 1] += val;
        if (r & 1) seg[r - 1] += val;
    }
}

int ask(int x)
{
    x += base;
    int tmp = 0;
    for (; x; x >>= 1)
        tmp += seg[x];
    return tmp;
}

void addPath(int u, int v, int value)
{
    for (; g[u].top != g[v].top; v = g[g[v].top].fa)
    {
        if (g[g[u].top].dep > g[g[v].top].dep) swap(u, v);
        add(g[g[v].top].rk, g[v].rk, value);
    }
    if (g[u].dep > g[v].dep) swap(u, v);
    add(g[u].rk, g[v].rk, value);
}

int main()
{
    freopen("b.in", "r", stdin);
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
        for (int i = 1; i <= n; ++i)
            if (!g[i].vis)
            {
                ++ti;
                dfsBigSonAndColor(i, 0, 0, 1);
                ++ti;
                dfsHeavyEdge(i, 0);
            }
        int cnt = 0;
        for (base = 1, high = 1; base <= n + 2; base <<= 1, high++);
       // memset(seg, 0, sizeof(seg));
        for (int i = base * 2 - 1; i >= 0; --i)
            seg[i] = 0;
        for (int i = 1; i <= m; ++i)
            if (!ed[i].vis && g[ed[i].u].co == g[ed[i].v].co)
            {
                addPath(ed[i].u, ed[i].v, 1);
                ++cnt;
            }
        for (int i = 1; i <= n; ++i)
            if (ask(g[i].rk) == cnt)
                printf("1");
            else printf("0");
        printf("\n");
    }
    return 0;
}
