#include <bits/stdc++.h>

#define EPS 1e-7
#define MAXD 1e5

using namespace std;

const double PI = acos(-1.0);

int cmp(double x, double y)
{
    if (x < y - EPS)
        return -1;
    if (x > y + EPS)
        return 1;
    return 0;
}

struct Point
{
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator + (Point p)
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (Point p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (double k)
    {
        return Point(x * k, y * k);
    }
    Point operator / (double k)
    {
        return Point(x / k, y / k);
    }
    bool operator == (Point p)
    {
        return !cmp(x, p.x) && !cmp(y, p.y);
    }
};

struct Line
{
    Point p1, p2;
    Line() {}
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

struct Cir
{
    Point o;
    double r;
    Cir() {}
    Cir(Point o, double r) : o(o), r(r) {}
    Point point(double a)
    {
        return Point(o.x + cos(a), o.y + sin(a));
    }
};

inline double sqr(double x)
{
    return x * x;
}

double dist(Point p1, Point p2)
{
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

double getLineCirIts(Line l, Cir c)
{
    double len = dist(l.p1, l.p2);
    int c1 = cmp(dist(l.p1, c.o), c.r);
    int c2 = cmp(dist(l.p2, c.o), c.r);
    if (c1 <= 0 && c2 <= 0)
        return len;

    double a = l.p2.x - l.p1.x, b = l.p1.x - c.o.x, C = l.p2.y - l.p1.y, d = l.p1.y - c.o.y;
    double e = sqr(a) + sqr(C), f = 2.0 * (a * b + C * d), g = sqr(b) + sqr(d) - sqr(c.r);
    double delta = sqr(f) - 4 * e * g;
    if (cmp(delta, 0) <= 0)
        return 0.0;

    double t1 = (-f - sqrt(delta)) / (2.0 * e);
    double t2 = (-f + sqrt(delta)) / (2.0 * e);

    t1 = max(t1, 0.0);
    t1 = min(t1, 1.0);
    t2 = max(t2, 0.0);
    t2 = min(t2, 1.0);

    return (t2 - t1) * len;
}

double getCirCirIts(Cir c1, Cir c2)
{
    double c = 2.0 * PI * c1.r;
    double d = dist(c1.o, c2.o);
    if (cmp(d + c1.r, c2.r) <= 0)
        return c;
    if (cmp(d, 0) == 0)
    {
        if (cmp(c1.r, c2.r) == 0)
            return c;
        return 0.0;
    }
    if (cmp(c1.r + c2.r, d) <= 0)
        return 0.0;
    if (cmp(c1.r - c2.r, d) >= 0)
        return 0.0;

    double da = acos((sqr(c1.r) + sqr(d) - sqr(c2.r)) / (2.0 * c1.r * d));
    return 2.0 * da * c1.r;
}

int main()
{
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        vector<Cir> cir;
        vector<Line> line;
        double tot = 0.0;
        int wall;
        double length;
        scanf("%d %lf", &wall, &length);
        while (wall--)
        {
            string ty;
            cin >> ty;
            if (ty[0] == 'C')
            {
                double x, y, r;
                scanf("%lf %lf %lf", &x, &y, &r);
                cir.push_back(Cir(Point(x, y), r));
                tot += 2.0 * PI * r;
            } else
            {
                int m;
                double x, y;
                scanf("%d", &m);
                if (!m)
                    continue;
                scanf("%lf %lf", &x, &y);
                Point pre = Point(x, y);
                Point ori = pre;
                for (int i = 1; i < m; i++)
                {
                    scanf("%lf %lf", &x, &y);
                    Point now = Point(x, y);
                    tot += dist(pre, now);
                    line.push_back(Line(pre, now));
                    pre = now;
                }
                if (!(pre == ori))
                {
                    tot += dist(pre, ori);
                    line.push_back(Line(pre, ori));
                }
            }
        }
        Cir rocket;
        scanf("%lf %lf", &rocket.o.x, &rocket.o.y);
        printf("Case #%d: ", tt);
        if (cmp(tot, length) < 0)
        {
            printf("impossible\n");
            continue;
        }
        if (cmp(tot, length) == 0)
        {
            printf("inestimable\n");
            continue;
        }
        double l = 0.0, r = MAXD, res, mid;
        for (int di = 0; di < 100; di++)
        {
            mid = (l + r) / 2.0;
            rocket.r = mid;
//            cout << mid << endl;
            res = 0.0;
            for (int i = 0; i < cir.size(); i++)
                res += getCirCirIts(cir[i], rocket);
            for (int i = 0; i < line.size(); i++)
                res += getLineCirIts(line[i], rocket);
            if (res < length + 1e-9)
                l = mid;
            else
                r = mid;
//            cout << res << endl;
        }
        if (fabs(res - length) < 1e-7)
            printf("%.2f\n", mid);
        else
            printf("impossible\n");
    }
    return 0;
}
