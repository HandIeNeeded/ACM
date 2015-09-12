#include <bits/stdc++.h>

#define EPS 1e-10

using namespace std;

const double pi = acos(-1.0);

double S(double x)
{
    return 2 * pi * (2 * x + sin(x));
}

double V(double x)
{
    return pi * (4.5 * x + 4 * sin(x) + 0.25 * sin(2 * x));
}

double sqr(double x)
{
    return x * x;
}

double F(double x)
{
    return (2 + cos(x)) * sqrt(1 + sqr(sin(x)));
}

double simpson(double l, double r)
{
    double mid = (l + r) / 2;
    return (r - l) * (F(l) + 4 * F(mid) + F(r)) / 6;
}

double auto_simpson(double l, double r, double prec, double s)
{
    double mid = (l + r) / 2;
    double s1 = simpson(l, mid);
    double s2 = simpson(mid, r);
    if (fabs(s1 + s2 - s) / 15.0 < prec)
        return s1 + s2 + (s1 + s2 - s) / 15;
    return auto_simpson(l, mid, prec / 2, s1) + auto_simpson(mid, r, prec / 2, s2);
}

double C(double x)
{
    x = 2 + cos(x);
    return pi * x * x;
}

int main()
{
    double por = 2 * pi * auto_simpson(0, 2 * pi, EPS, simpson(0, 2 * pi));

    int ttt;
    scanf("%d", &ttt);
    for (int tt = 0; tt < ttt; tt++)
    {
        double z1, z2;
        scanf("%lf %lf", &z1, &z2);
        int k = (z2 - z1) / pi / 2.0;
        double r = z1 + 1.0 * k * pi * 2.0;
        printf("%.6f %.6f\n", V(z2) - V(z1) + EPS, 1.0 * k * por + 2.0 * pi * auto_simpson(r, z2, EPS, simpson(r, z2)) + C(z1));
    }
    return 0;
}
