#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

struct Point
{
	int x, y, h;
	Point() {}
	Point(int x, int y, int h) : x(x), y(y), h(h) {}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y, h);
	}
	void print()
	{
		printf("(%d, %d)\n", x, y);
	}
};

struct Line
{
	Point p1, p2;
	Line() {}
	Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

bool d[330][330];
bool vis[330];
int res[330];

int det(Point v1, Point v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

int onRight(Point p, Line l)
{
	return det(l.p2 - l.p1, p - l.p1) > 0;
//	int tmp = det(l.p2 - l.p1, p - l.p1);
//	if (tmp > 0)
//		return 1;
//	if (tmp < 0)
//		return -1;
//	return 0;
}

int sqr(int x)
{
	return x * x;
}

int dist(Point p1, Point p2)
{
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

bool dfs(int u, int n)
{
	REP(v, n)
		if (d[u][v] && !vis[v])
		{
			vis[v] = true;
			if (res[v] == -1 || dfs(res[v], n))
			{
				res[v] = u;
				return true;
			}
		}
	return 0;
}

int main()
{
	freopen("E.in", "r", stdin);

	int n, ca = 1;
	while (scanf("%d", &n) && n)
	{
		vector<Point> p;
		REP(i, n)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			p.push_back(Point(x, y, z));
		}

		int p1, p2, r;
		scanf("%d %d %d", &p1, &p2, &r);
		p1--, p2--;
		Line bound = Line(p[p1], p[p2]);

		vector<Point> a, b;
		REP(i, n)
			if (i != p1 && i != p2 && p[i].h != 0)
			{
				if (onRight(p[i], bound))
					a.push_back(p[i]);
				else
					b.push_back(p[i]);
			}
		if (a.size() > b.size())
			swap(a, b);

//		REP(i, a.size())
//			a[i].print();
//		printf("\n");
//		REP(i, b.size())
//			b[i].print();
//		printf("\n");

		MST(d, 0);
		int rr = r * r;
		REP(i, a.size())
			REP(j, b.size())
				if (dist(a[i], b[j]) <= rr && a[i].h > b[j].h)
					d[i][j] = true;
//		REP(i, a.size())
//			REP(j, b.size())
//				printf("%d%c", d[i][j], " \n"[j == b.size() - 1]);

		int ans = 0;
		MST(res, -1);
		for (int i = 0; i < a.size(); i++)
		{
			MST(vis, 0);
			ans += dfs(i, b.size()) ? 1 : 0;
		}
		printf("Case %d: %d\n", ca++, ans);
	}
	return 0;
}
