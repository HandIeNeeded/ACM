#include <bits/stdc++.h>
#define MAXN 9
#define MAXM 30

using namespace std;

struct node
{
    int u, v;
} ed[MAXM];

int deg[MAXN], nxt[100000][MAXN], dp[100000],f[100000];

void dpa(int n, int m)
{

    if (n == 1 || n == 2)
    {
        printf("1\n");
        return ;
    }
    int jz = (n - 1) / 2 + 1;
    int lim = 1;
    for (int i = 1; i <= n; ++i)
        lim = lim * jz;
    for (int i = 0; i < lim; ++i)
    {
        int tmp = i, pw = 1;
        for (int j = 1; j <= n; ++j)
        {
            int p = tmp % jz;
            if (p + 1 > deg[j] / 2)
                nxt[i][j] = -1;
            else nxt[i][j] = i + pw;
            pw *= jz;
            tmp /= jz;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < lim; ++j)
            f[j] = dp[j]; // white
        for (int j = 0; j < lim; ++j)
            if (dp[j])
            {
                int tmp = nxt[j][ed[i].u];
                if (tmp < 0) continue;
                tmp = nxt[tmp][ed[i].v];
                if (tmp < 0) continue;
                f[tmp] += dp[j];
            }
        for (int j = 0; j < lim; ++j)
            dp[j] = f[j];
    }
    int tmp = 0;
    for (int i = n; i >= 1; --i)
    {
        tmp = tmp * jz + deg[i] / 2;
    }
    printf("%d\n", dp[tmp]);
}

int main()
{
   // freopen("f.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &ed[i].u, &ed[i].v);
            deg[ed[i].u]++, deg[ed[i].v]++;
        }
        int ok = 1;
        for (int i = 1; i <= n; ++i)
            if (deg[i] & 1)
            {
                printf("0\n");
                ok = 0;
                break;
            }
        if (ok) dpa(n, m);
    }
    return 0;
}
