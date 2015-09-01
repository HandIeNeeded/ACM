#include <bits/stdc++.h>
#define MAXM 1212345
#define MAXN 412345

using namespace std;

typedef int arrayN[MAXN], arrayM[MAXM];

struct edge
{
    int u, v, vis, ans;
}ed[MAXM];

arrayN fir, pre;
arrayM e, nxt;
long long d[MAXN];

int lab[MAXM], num;
const long long oo = 1e18;



void link(int u, int v, int labx)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, lab[num] = labx;
    ed[labx].ans = 0, ed[labx].vis = 0;
}

int main()
{
    //freopen("f.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        num = 1;
        for (int i = 1; i <= n; ++i)
            fir[i] = 0, d[i] = oo;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &ed[i].u, &ed[i].v);
            link(ed[i].u, ed[i].v, i);
          //  link(ed[i].v, ed[i].u, i);
        }
        d[1] = 0;
        int pl = 2;
        int pr = n;
        for (int p = fir[1]; p; p = nxt[p])
            if (d[1] < d[e[p]])
            {
                pre[e[p]] = p;
                d[e[p]] = d[1];
            }
        d[n + 1] = 0;
        for ( ;pl <= pr; )
        {
            if (d[pl] < oo && d[pl] + n > d[pl - 1])
            {
                int tp = pre[pl];
                int lb = lab[tp];
                long long tmp = max(d[pl - 1] + 1, d[pl] + 1);
                if (pl == pr)
                {
                    if (tmp == d[pr + 1])
                     tmp++;
                }
                if (tmp - d[pl] <= n)
                {
                    ed[lb].ans = tmp - d[pl];
                    ed[lb].vis = 1;
                    d[pl] = tmp;
                    for (int p = fir[pl]; p; p = nxt[p])
                        if (!ed[lab[p]].vis && d[e[p]] > d[pl] && e[p] >= pl && e[p] <= pr)
                        {
                            d[e[p]] = d[pl];
                            pre[e[p]] = p;
                        }
                    ++pl;
                    continue;
                }
            }

            if (d[pr] < oo && d[pr] + n > d[pr + 1])
            {
                int tp = pre[pr];
                int lb = lab[tp];

                long long tmp = max(d[pr + 1] + 1, d[pr] + 1);
                if (pl == pr)
                {
                    if (tmp == d[pl - 1])
                        tmp++;
                }
                if (tmp - d[pr] <= n)
                {
                    ed[lb].ans = tmp - d[pr];
                    ed[lb].vis = 1;
                    d[pr] = tmp;
                    for (int p = fir[pr]; p; p = nxt[p])
                        if (!ed[lab[p]].vis && d[e[p]] > d[pr] && e[p] >= pl && e[p] <= pr)
                        {
                            d[e[p]] = d[pr];
                            pre[e[p]] = p;
                        }
                    --pr;
                    continue;
                }
            }

        }

        for (int i = 1; i <= m; ++i)
            if (ed[i].vis)
            {
                printf("%d\n", ed[i].ans);
            } else printf("%d\n", n);
    }
    return 0;
}
