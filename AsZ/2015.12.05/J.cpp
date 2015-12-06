#include <bits/stdc++.h>

#define LL long long
#define EPS 1e-7

using namespace std;

LL sqr(LL x)
{
    return x * x;
}

//int cmp(double x, double y)
//{
//    if (x < y - EPS)
//        return -1;
//    if (x > y + EPS)
//        return 1;
//    return 0;
//}

struct Point
{
    LL x, y;
    Point(LL x = 0, LL y = 0) : x(x), y(y) {}
    Point operator += (Point p)
    {
        x += p.x, y += p.y;
        return *this;
    }
    Point operator + (Point p)
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (Point p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (LL k)
    {
        return Point(x * k, y * k);
    }
//    Point operator / (double k)
//    {
//        return Point(x / k, y / k);
//    }
};

int main() {
    freopen("joy.in", "r", stdin);
#ifndef HOME
    freopen("joy.out", "w", stdout);
#endif // HOME

    Point sta, fin;
    scanf("%lld %lld", &sta.x, &sta.y);
    scanf("%lld %lld", &fin.x, &fin.y);

    int n, k;
    LL vm;
    scanf("%d %d %lld", &n, &k, &vm);

    vector<LL> t;
    vector<Point> v;
    for (int i = 0; i < n; i++)
    {
        LL x, y, z;
        scanf("%lld %lld %lld", &z, &x, &y);
        t.push_back(z);
        v.push_back(Point(x, y));
    }

    Point now = sta;
    for (int i = 0; i < n; i++)
    {
        int tt = (i < n - 1) ? t[i + 1] : k;
        tt -= t[i];
        now = now + v[i] * tt;
    }
//    printf("%f %f\n", now.x, now.y);
    Point s = fin - now;
//    cout << s.x << " " << s.y << endl;
//    Point vr = s / k;       //v real
//    printf("%f %f\n", s.x, s.y);
    if (sqr(s.x) + sqr(s.y) > sqr(k) * sqr(vm))
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    int it = 0;             //which wind
    now = sta;
    double dx = 1.0 * s.x / k;
    double dy = 1.0 * s.y / k;
    double nx = sta.x, ny = sta.y;
    for (int i = 1; i <= k; i++)
    {
        if (it < n - 1 && i > t[it + 1])
            it++;
//        now = now + v[it] + vr;
        nx += dx + v[it].x;
        ny += dy + v[it].y;
        printf("%.6f %.6f\n", nx, ny);
    }

    return 0;
}

