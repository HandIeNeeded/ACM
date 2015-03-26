#include<bits/stdc++.h>

#define EPS 1e-10

using namespace std;

vector<int> num;
vector<double> g, a, b, c;
double kk[100100];

int cmp(double x, double y)
{
	if (x < y - EPS)
		return -1;
	if (x > y + EPS)
		return 1;
	return 0;
}

bool cmpp(int i, int j)
{
	return c[i] > c[j];
}

int main()
{
//	freopen("burrito.in", "r", stdin);
//	freopen("burrito.out", "w", stdout);
	int n;
	double A, B;
	scanf("%d %lf %lf", &n, &A, &B);
	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		scanf("%lf %lf %lf", &z, &x, &y);
		g.push_back(z);
		a.push_back(x);
		b.push_back(y);
		if (cmp(b[i], 0) == 0)
			c.push_back(101);
		else
			c.push_back(a[i] / b[i]);
		num.push_back(i);
	}
	int m = n;
	for (int i = m - 1; i >= 0; i--)
	{
		if (cmp(a[i] + b[i], 0) == 0)
		{
			swap(num[i], num[m - 1]);
			m--;
		}
	}
	sort(num.begin(), num.begin() + m, cmpp);
	double an = 0.0, bn = 0.0;
	for (int j = 0; j < n; j++)
	{
		int i = num[j];
		if (cmp(a[i], 0) == 0)
			break;
		if (cmp(bn + b[i] * g[i], B) < 1)
		{
			an += a[i] * g[i];
			bn += b[i] * g[i];
			kk[i] = g[i];
			if (cmp(bn, B) == 0)
				break;
		} else
		{
			double k = (B - bn) / b[i];
			an += a[i] * k;
			bn += b[i] * k;
			kk[i] = k;
			break;
		}
	}
	if (cmp(an, A) == -1)
	{
		printf("-1 -1\n");
		return 0;
	} else
	{
		printf("%.10f %.10f\n", an, bn);
		for (int i = 0; i < n; i++)
			printf("%.10f%c", kk[i], " \n"[i == n - 1]);
	}
	return 0;
}
