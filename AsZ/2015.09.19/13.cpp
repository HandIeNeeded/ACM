#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LL long long
#define FI first
#define SE second
#define MP make_pair
#define VI vector<int>
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define ALL(a) a.begin(), a.end()
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))

#define SL(a) strlen(a)
#define RS(s) scanf("%s", (s))
#define PI(r) printf("%d\n", (r))
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)

#define L (x << 1)
#define R ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#define B(x) __builtin_popcount(x)

#define N 110
#define EPS 1e-7
#define INF 100000
#define LIM (1ll << 60)

using namespace std;

struct Point
{
    double x, y;
    Point() {}
    Point(double X, double Y) : x(X), y(Y) {}
    Point operator - ()
    {
        return Point(-x, -y);
    }
    Point operator + (Point a)
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (Point a)
    {
        return Point(x - a.x, y - a.y);
    }
    Point operator * (double z)
    {
        return Point(x * z, y * z);
    }
    Point operator / (double z)
    {
        if (fabs(z) < EPS)
            return Point(INF, INF);
        return Point(x / z, y / z);
    }
    Point operator += (Point a)
    {
        x += a.x;
        y += a.y;
        return *this;
    }
    Point operator -= (Point a)
    {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    bool operator == (Point a)
    {
        double dist;
        dist = (x - a.x) * (x - a.x);
        dist += (y - a.y) * (y - a.y);
        return dist < EPS;
    }
    bool operator != (Point a)
    {
        return !(*this == a);
    }
    void print()
    {
        printf("(%f, %f)\n", x, y);
    }
};

const Point O = Point(0, 0);
const Point OO = Point(INF, INF);
const Point ex = Point(1, 0);
const Point TL = Point(0, 4095);
const Point BL = Point(0, 0);
const Point BR = Point(4095, 0);
const Point TR = Point(4095, 4095);

double sqr(double x)
{
    return x * x;
}

double dist(Point p1, Point p2)
{
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

struct Line
{
    Point p1, p2;
    Point dir;
    Line() {}
    Line(Point P1, Point P2) : p1(P1), p2(P2)
    {
        dir = (p2 - p1) / dist(p1, p2);
    }
    void reverse()
    {
        *this = Line(p2, p1);
    }
    void print(int i)
    {
        printf("line %d:\n", i);
        p1.print();
        p2.print();
        printf("dir:");
        dir.print();
    }
    bool operator == (Line l)
    {
        return p1 == l.p1 && p2 == l.p2;
    }
};

const Line Boundary[4] =
{
    Line(BL, BR),
    Line(BR, TR),
    Line(TR, TL),
    Line(TL, BL)
};

double dot(Point v1, Point v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double det(Point v1, Point v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

Point cross(Line l1, Line l2)
{
    Point v1 = l1.p1 - l2.p1;
    Point v2 = l2.p2 - l2.p1;
    Point v3 = l1.p2 - l2.p1;
    Point dv = l1.p2 - l1.p1;
    double s1 = det(v1, v2);
    double s2 = det(v2, v3);
    double s = s1 + s2;
    if (fabs(s) < EPS)
        return OO;
    return l1.p1 + dv * (s1 / s);
}

bool cmp(Line l1, Line l2)
{
    double s1 = det(ex, l1.dir);
    double s2 = det(ex, l2.dir);
    if (s1 > -EPS && s2 < -EPS)
        return 1;
    if (s1 < -EPS && s2 > -EPS)
        return 0;
    double t1 = dot(ex, l1.dir);
    double t2 = dot(ex, l2.dir);
    if (s1 > -EPS)
        return t1 > t2;
    else
        return t1 < t2;
}

bool onRight(Line l, Point p)
{
    return det(l.dir, p - l.p1) < EPS;
}

vector<Point> Half_Plane(vector<Line> &line)
{
    deque<Line> ql;
    deque<Point> qd;
    vector<Point> Core;

    REP(i, 4)
        line.push_back(Boundary[i]);
    sort(line.begin(), line.end(), cmp);
//    REP(i, line.size())
//        line[i].print(i);
//    cout<<"----------------------------------------"<<endl;

    REP(i, line.size())
    {
//        line[i].print(i);
        while (qd.size() && onRight(line[i], qd.back()))
            qd.pop_back(), ql.pop_back();

        while (qd.size() && onRight(line[i], qd.front()))
            qd.pop_front(), ql.pop_front();

        if (ql.size() && ql.back().dir == line[i].dir)
        {
            if (onRight(line[i], ql.back().p1))
            {
                ql.pop_back();
                if (qd.size())
                    qd.pop_back();
            } else
                continue;
        }

        if (ql.size() && ql.front().dir == -line[i].dir)
            if (onRight(line[i], ql.front().p1))
                return Core;

        if (ql.size())
            qd.push_back(cross(ql.back(), line[i]));
        ql.push_back(line[i]);

        if (qd.size() > 1 && onRight(ql.front(), qd.back()))
            ql.pop_back(), qd.pop_back();

//        printf(">>================\n");
//        REP(j, ql.size())
//            ql[j].print(j);
//        printf(">>================\n");
    }
    qd.push_back(cross(ql[0], ql.back()));
    while (qd.size())
    {
        Core.push_back(qd.front());
        qd.pop_front();
    }
    return Core;
}

double calc(vector<Point> &Core)
{
    if (Core.size() < 3)
        return 0.0;
    Core.push_back(Core[0]);
    double s = 0.0;
    REP(i, Core.size() - 1)
        s += det(Core[i], Core[i + 1]);
    return fabs(s) / 2;
}

double x[N], y[N], w[N], area[N];

int main()
{
    freopen("13.in", "r", stdin);
    //freopen("13.out", "w", stdout);
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            w[i] = x[i] = y[i] = 0.0;
            for (int j = 0; j < m; j++)
            {
                int xx, yy;
                scanf("%d %d", &xx, &yy);
                x[i] += xx, y[i] += yy;
                w[i] += sqr(xx) + sqr(yy);
            }
            x[i] /= 1.0 * m;
            y[i] /= 1.0 * m;
            w[i] /= 1.0 * m;
        }
        // for (int i = 0; i < n; i++)
        //     printf("%f %f %f\n", x[i], y[i], w[i]);
        for (int i = 0; i < n; i++)
        {
            vector<Line> l;
            for (int j = 0; j < n; j++)
                if (i != j)
                {
                    Point p1, p2;

                    if (fabs(y[i] - y[j]) > EPS)
                        p1 = Point(0.5, (w[i] - w[j] - x[i] + x[j]) / (y[i] - y[j]) / 2.0);
                    else
                        p1 = Point((w[i] - w[j]) / (x[i] - x[j]) / 2.0, 4095.0);

                    if (fabs(x[i] - x[j]) > EPS)
                        p2 = Point((w[i] - w[j]) / (x[i] - x[j]) / 2.0, 0.0);
                    else
                        p2 = Point(4095.0, (w[i] - w[j]) / (y[i] - y[j]) / 2.0);


                    Line ll = Line(p1, p2);
                    if (onRight(ll, Point(x[i], y[i])))
                        ll = Line(p2, p1);
                    l.push_back(ll);
                }
            // for (int j = 0; j < l.size(); j++)
            //     l[j].print(j);
            vector<Point> Core = Half_Plane(l);
            // cout << endl;
            // for (int j = 0; j < Core.size(); j++)
            //     Core[j].print();
            // cout << endl;
            area[i] = calc(Core);
        }
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++)
            printf("%.0f%c", area[i] + EPS, " \n"[i == n - 1]);
    }
}
