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

double d_mul(Point v1, Point v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double v_mul(Point v1, Point v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

double sqr(double x)
{
    return x * x;
}

double dist(Point p1, Point p2)
{
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

Point cross(Line l1, Line l2)
{
    Point v1 = l1.p1 - l2.p1;
    Point v2 = l2.p2 - l2.p1;
    Point v3 = l1.p2 - l2.p1;
    Point dv = l1.p2 - l1.p1;
    double s1 = v_mul(v1, v2);
    double s2 = v_mul(v2, v3);
    double s = s1 + s2;
    if (fabs(s) < EPS)
        return OO;
    return l1.p1 + dv * (s1 / s);
}
