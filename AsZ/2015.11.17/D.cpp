#include <bits/stdc++.h>

#define N 20
#define EPS 1e-7

using namespace std;

int p[N], h[N];
int n, b;
double d, vx, vy;

int cmp(double x, double y)
{
    if (x < y - EPS)
        return -1;
    if (x > y + EPS)
        return 1;
    return 0;
}

inline double sqr(double x)
{
    return x * x;
}

double f(double x)
{
    return -sqr(x) / (2.0 * sqr(vx)) + x * vy / vx;
}

bool check(double v)
{
    bool shoot = false;
    for (int k = 0; !shoot && k <= b; k++)
    {
        double l = d / (k + 1);

        double A = 1.0;
        double B = -sqr(v);
        double C = sqr(l) / 4.0;
        double delta = sqr(B) - 4.0 * A * C;
        if (cmp(delta, 0.0) < 0)
            continue;
        delta = fabs(delta);
        vy = (-B + sqrt(delta)) / (2.0 * A);
        vy = sqrt(vy);
        vx = l / vy / 2.0;

        bool flag = true;
        double now = 0.0;
        for (int i = 0; i < n; i++)
        {
            while (cmp(p[i], now + l) > 0)
                now += l;
            double y = f(p[i] - now);
            if (cmp(y, h[i]) <= 0)
            {
                flag = false;
                break;
            }
        }
        shoot = flag;
    }
    return shoot;
}

int main()
{
    freopen("D.in", "r", stdin);
    scanf("%lf %d %d", &d, &n, &b);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i], &h[i]);
    double l = 0.0, r = 1e10;
    for (int i = 0; i < 100; i++)
    {
        double m = (l + r) / 2.0;
        if (check(m))
            r = m;
        else
            l = m;
    }
    printf("%.5f\n", l);
    return 0;
}
