#include <bits/stdc++.h>

#define N 1010

using namespace std;

int h[N], d[N], num[N];
int f[N], p[N];
bool vis[N];

bool cmp(int i, int j)
{
    if (h[i] > h[j])
        return true;
    if (h[i] < h[j])
        return false;
    return d[i] > d[j];
}

int main()
{
    freopen("A.in", "r", stdin);
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; num[i] = i, i++)
            scanf("%d %d", &h[i], &d[i]);
        sort(num, num + n, cmp);
        for (int i = 0; i < n; i++)
            f[i] = 1, p[i] = -1;
        int maxi = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (d[num[i]] >= d[num[j]])
                    if (f[j] + 1 > f[i])
                    {
                        f[i] = f[j] + 1;
                        p[i] = j;
                    }
            maxi = max(maxi, f[i]);
        }
        int ans = maxi;
        for (int i = 0; i < n; i++)
            vis[i] = true;
        for (int i = 0; i < n; i++)
            if (f[i] == maxi)
            {
                int j = i;
                while (j > -1)
                {
                    vis[j] = false;
                    j = p[j];
                }
            }
        maxi = 0;
        for (int i = 0; i < n; i++)
            f[i] = 1, p[i] = -1;
        for (int i = 0; i < n; i++)
            if (vis[i])
            {
                for (int j = 0; j < i; j++)
                    if (vis[j])
                        if (d[num[i]] >= d[num[j]])
                            if (f[j] + 1 > f[i])
                                f[i] = f[j] + 1;
                if (vis[i])
                    maxi = max(maxi, f[i]);
            }
        printf("%d\n", ans + maxi);
    }
    return 0;
}
