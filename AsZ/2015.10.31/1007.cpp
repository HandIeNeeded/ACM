#include <bits/stdc++.h>

#define FI first
#define SE second

#define INF 0x3f3f3f3f
#define EPS 1e-7

using namespace std;

int cmp(double x, double y)
{
    if (x < y - EPS)
        return -1;
    if (x > y + EPS)
        return 1;
    return 0;
}

double sqr(double x)
{
    return x * x;
}

double solve(double a, double b, double c, double l, double r)
{
    double d = sqr(b) - 4.0 * a * c;
    if (cmp(d, 0.0) < 0)
        return INF;
    double x1 = (-b - sqrt(d)) / (2.0 * a);
    double x2 = (-b + sqrt(d)) / (2.0 * a);
    if (cmp(x1, l) >= 0 && cmp(x1, r) <= 0)
        return x1;
    if (cmp(x2, l) >= 0 && cmp(x2, r) <= 0)
        return x2;
    return INF;
}

bool cmpp(pair<double , int> a, pair<double , int> b)
{
    if (cmp(a.FI, b.FI) < 0)
        return true;
    if (cmp(a.FI, b.FI) > 0)
        return false;
    return a.SE < b.SE;
}

int main() {
#ifdef HOME
    freopen("1007.in", "r", stdin);
#endif

    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        double T, v1, v2;
        scanf("%lf %lf %lf", &T, &v1, &v2);

        if (cmp(1200.0 / (v1 + v2), 300.0 / v1) < 0)
        {
            printf("Case #%d: No\n", tt);
            continue;
        }

        if (cmp(v1, v2) == 0)
        {
            printf("Case #%d: Yes\n", tt);
            continue;
        }

        bool vis[5];
        memset(vis, 0, sizeof(vis));
        int s1 = 0, s2 = 1;
        vis[1] = true;
        double t = solve(sqr(v2) - sqr(v1), -600.0 * v2, 2.0 * sqr(300.0), 300.0 / v2, 600.0 / v2);
        if (cmp(t, INF) == 0)
        {
            t = solve(sqr(v2) - sqr(v1), -1800.0 * v2, sqr(900.0) + sqr(300.0), 600.0 / v2, 900.0 / v2);
            s2++, vis[2] = true;
        }

        vector< pair<double , int> > inci;

        double waket = t + T;
        if (cmp(t, 600.0 / v2) <= 0)
            inci.push_back(make_pair(waket + 600.0 / v2 - t, 4 + 2));
        inci.push_back(make_pair(waket + 900.0 / v2 - t, 4 + 3));
        inci.push_back(make_pair(waket + 1200.0 / v2 - t, 4 + 4));

        double ori = t + (t - 300.0 / v2) * v2 / v1;
        if (cmp(t, 600.0 / v2) <= 0)
            inci.push_back(make_pair(ori + 300.0 / v1, 2));
        inci.push_back(make_pair(ori + 600.0 / v1, 3));
        inci.push_back(make_pair(ori + 900.0 / v1, 4));

        sort(inci.begin(), inci.end(), cmpp);
        for (int i = 0; i < inci.size(); i++)
        {
            int k = inci[i].SE > 4 ? (inci[i].SE - 4) : inci[i].SE;
            if (!vis[k])
            {
                vis[k] = true;
                if (inci[i].SE > 4)
                    s2++;
                else
                    s1++;
            }
        }
        if (s1 > s2)
            printf("Case #%d: Yes\n", tt);
        else
            printf("Case #%d: No\n", tt);
    }

}
