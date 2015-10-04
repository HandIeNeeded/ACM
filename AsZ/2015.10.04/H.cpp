#include <bits/stdc++.h>

#define N 4040
#define INF 1e10

using namespace std;

double f[N], p[N];
int num[N], vis[N];
int a[N], b[N];

int main()
{
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        memset(vis, 0, sizeof(vis));
        int n, c, tot = 1;
        scanf("%d %d", &n, &c);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i])
                vis[a[i]] = true;
        }
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                b[tot++] = a[i];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                int now = i;
                while (now && !vis[now])
                {
                    vis[i] = true;
                    now = a[now];
                }
                if (now == i)
                    cnt++;
            }
        if (tot < 3)
        {
            printf("%.6f\n", double(c * cnt));
            continue;
        }
        if (b[1])
        {
            f[1] = 1;
            num[1] = 1;
            if (b[2])
            {
                f[2] = 1.5;
                num[2] = 2;
                p[2] = 2;
            } else
            {
                f[2] = 1;
                num[2] = 1;
                p[2] = 1;
            }
        } else
        {
            f[1] = 0;
            num[1] = 0;
            if (b[2])
            {
                f[2] = 1;
                num[2] = 1;
                p[2] = INF;
            } else
            {
                f[2] = 1;
                num[2] = 1;
                p[2] = INF;
            }
        }
        for (int i = 3; i < tot; i++)
            if (b[i])
            {
                p[i] = (i - 1) * (1 + 1.0 / p[i - 1]) + 1;
//                num[i] = (i - 1) * (num[i - 1] + num[i - 2]) + num[i - 1];
//                f[i] = ((num[i - 1] * f[i - 1] + num[i - 2] * (f[i - 2] + 1)) * (i - 1) + num[i - 1] * (f[i - 1] + 1)) / num[i];
                f[i] = (((1.0 / p[i]) * f[i - 1] + (1.0 / p[i] / p[i - 1]) * (f[i - 2] + 1)) * (i - 1) + (1.0 / p[i]) * (f[i - 1] + 1));
            } else
            {
                p[i] = (i - 1) * (1 + 1.0 / p[i - 1]);
//                num[i] = (i - 1) * (num[i - 1] + num[i - 2]);
//                f[i] = (num[i - 1] * f[i - 1] + num[i - 2] * (f[i - 2] + 1)) * (i - 1) / num[i];
                f[i] = ((1.0 / p[i]) * f[i - 1] + (1.0 / p[i] / p[i - 1]) * (f[i - 2] + 1)) * (i - 1);
            }
        printf("%.6f\n", c * (f[tot - 1] + cnt));
    }
    return 0;
}
