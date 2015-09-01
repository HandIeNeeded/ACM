#include <bits/stdc++.h>
#define MAXN 612345

using namespace std;


int num, fir[MAXN], deg[MAXN], ans[MAXN];

struct edge
{
    int v, lab, dir, vis;
    int r, l;
} ed[MAXN];


void link(int u, int v, int dir, int lab)
{
    ++num;
    ed[num].v = v;
    ed[num].lab = lab;
    ed[num].dir = dir;
    ed[num].vis = 0;
    ed[num].r = fir[u];
    if (ed[num].r)
        ed[ed[num].r].l = num;
    ed[num].l = 0;
    fir[u] = num;
}

void del(int x, int p)
{

    if (ed[p].r)
    {
        ed[ed[p].r].l = ed[p].l;
    }
    if (fir[x] == p)
    {
        fir[x] = ed[p].r;
        return ;
    }
    ed[ed[p].l].r = ed[p].r;
}

void dfs(int x, int sign)
{
    for (;;)
    {
        int flag = 1;
        for (int p = fir[x]; p; p = ed[p].r)
            if (!ed[p].vis)
            {
                deg[x]--;
                ans[ed[p].lab] = sign * ed[p].dir;
                ed[p].vis = ed[p ^ 1].vis = 1;
                del(x, p), del(x, p ^ 1);
                deg[ed[p].v]--;

                x = ed[p].v;

                flag = 0;
                break;
            }
            else del(x, p);
        if (flag) return;
    }
}

int random(int x)
{
    return abs(rand() * rand() * rand()) % x + 1;
}

int main()
{
    //freopen("f.in", "r", stdin);
    int ca;
    srand(clock() % time(0));

    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        scanf("%d%d", &n, &m);
       //n = 100000;
      // m = 300000;
        num = 1;
        for (int i = 1; i <= n; ++i)
            fir[i] = deg[i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
           // u = random(n);
          // v = random(n);
            link(u, v, 1, i);
            link(v, u, -1, i);
            deg[u]++, deg[v]++;
        }


        for (int i = 0; i < n; ++i)
            if (deg[i])
            {
                int sign = 1;
                for (int p = fir[i]; p; p = ed[p].r)
                    if (!ed[p].vis)
                    {

                        int tmpDeg = deg[i];

                        --deg[i];
                        ans[ed[p].lab] = sign * ed[p].dir;
                        ed[p].vis = ed[p ^ 1].vis = 1;
                        del(i, p), del(i, p ^ 1);
                        deg[ed[p].v]--;

                        dfs(ed[p].v, sign);
                        if ((tmpDeg - deg[i]) & 1)
                            sign *= -1;
                    } else del(i, p);
            }
        for (int i = 1; i <= m; ++i)
            printf("%d\n", ans[i] > 0 ? 1: 0);
    }
    return 0;
}
