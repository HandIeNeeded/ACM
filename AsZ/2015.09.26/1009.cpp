#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator + (Point a)
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator / (double k)
    {
        return Point(x / k, y / k);
    }
};

double sqr(double x)
{
    return x * x;
}

double dist(Point p1, Point p2)
{
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int main()
{
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        Point pa, pb, pc, pm;
        scanf("%lf %lf", &pa.x, &pa.y);
        scanf("%lf %lf", &pb.x, &pb.y);
        scanf("%lf %lf", &pc.x, &pc.y);
        pm = (pb + pc) / 2.0;
        double l, a, h;
        l = dist(pa, pb);
        a = dist(pb, pc);
        h = dist(pa, pm);
        double r = l * (a / 2.0 / h);
        double thi = asin(a / 2.0 / r) * 2.0;
        double ans = h + r * thi;
        printf("Case #%d: %.4f\n", tt, ans);
    }
    return 0;
}
