#include <bits/stdc++.h>

using namespace std;

double f[2][100100];
int vis[2][100100];
int now;

int main()
{
	freopen("betting.in", "r", stdin);
	freopen("betting.out", "w", stdout);
	int n, s, t;
	double p;
	while (scanf("%d %d %lf %d", &n, &s, &p, &t) && n)
	{
		now++;
		p /= 100;
		double q = 1.0 - p;

		for (int i = 0; i <= n; i++)
			f[0][i] = f[1][i] = 0.0;
		f[0][s] = 1;

		double ans = 0.0;
		int now = 0, pre = 1;
		for (int k = 0; k < t; k++)
		{
			for (int i = 0; i <= n; i++)
				f[pre][i] = 0.0;
			for (int i = 1; i < n; i++)
			{
				int tmp = min(i, n - i);
				f[pre][i - tmp] += f[now][i] * q;
				f[pre][i + tmp] += f[now][i] * p;
			}
			now = pre, pre ^= 1;
			ans += f[now][n];
		}
		printf("%.10f\n", ans);
	}
}
