#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;
} p[110];

int n, m;

double sqr(double x)
{
    return x * x;
}

double dist(int g, int h)
{
    return sqrt(sqr(p[g].x - p[h].x) + sqr(p[g].y - p[h].y));
}

int check(int k, int r)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (dist(i, k) < 1.0 * r - 1e-7)
            res++;
    return res;
}

int main()
{
    freopen("A.in", "r", stdin);
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        int ans = 4001;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = 4000;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (check(i, mid) < m)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            bool flag = true;
            for (int j = 0; j < n; j++)
                if (fabs(dist(j, i) - l) < 1e-7)
                    flag = false;
            if (!flag)
                continue;
            if (check(i, l) == m)
                ans = min(ans, l);
        }
        if (ans == 4001)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
