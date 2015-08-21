#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define EPS 1e-7

using namespace std;

inline int cmp(double x, double y)
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

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	double length()
	{
		return sqrt(sqr(x) + sqr(y));
	}
	Point rot(double thi)
	{
		return Point(x * cos(thi) + y * sin(thi), y * cos(thi) - x * sin(thi));
	}
	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator / (double k)
	{
		return Point(x / k, y / k);
	}
	void print()
	{
		printf("(%f, %f)\n", x, y);
	}
};

vector<Point> p;
int n, ans;
double d;
clock_t st, ed;
double det(Point &p1, Point &p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}

int calc(Point p1, Point p2, double ty)
{
	double A = p1.y - p2.y;
	double B = p2.x - p1.x;
	double k = sqrt(sqr(A) + sqr(B));
	double C = det(p1, p2) + ty * d * k;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (res + n - i < ans)
			return res;
		double tmp = (A * p[i].x + B * p[i].y + C) / k;
		if (cmp(fabs(tmp), d) < 1)
			res++;
	}
	return res;
}

int main()
{
	freopen("I.in", "r", stdin);
//	freopen("I.out", "w", stdout);
	scanf("%d %lf", &n, &d);
	for (int i = 0; i < n; i++)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		p.push_back(Point(x, y));
	}
	double dd = 2 * d;
	ans = 1;
	st = clock();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (i != j)
			{
			ed = clock();
				if (1.0 * (ed - st) / CLOCKS_PER_SEC > 6.5) {
					printf("%d\n", ans);
					return 0;

				}
				ans = max(ans, calc(p[i], p[j], -1));
				ans = max(ans, calc(p[i], p[j], 1));
				Point v = p[j] - p[i];
				double l = v.length();
				if (cmp(l, dd) == -1)
					continue;
				Point mid = (p[i] + p[j]) / 2;
				double k = dd / l;
				if (k > 1)
					k = 1;
				k = asin(k);
				ans = max(ans, calc(mid, mid + v.rot(k), 0));
				ans = max(ans, calc(mid, mid + v.rot(-k), 0));
			}
	printf("%d", ans);
	return 0;
}
