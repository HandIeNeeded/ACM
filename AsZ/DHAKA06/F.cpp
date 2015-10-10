#include <bits/stdc++.h>

using namespace std;

double f[111][111][111];

int main()
{
	freopen("E.in", "r", stdin);
	int n, tt = 1;
	while (scanf("%d", &n) && n)
	{
		int n1, n2;
		vector<int> a, b;
		scanf("%d", &n1);
		for (int i = 0; i < n1; i++)
		{
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		scanf("%d", &n2);
		for (int i = 0; i < n2; i++)
		{
			int x;
			scanf("%d", &x);
			b.push_back(x);
		}
		sort(b.begin(), b.end());

		int day;
		scanf("%d", &day);

		int com = 0;
		int g = 0, h = 0;
		while (g < a.size() && h < b.size())
		{
			if (a[g] == b[h])
				com++, g++, h++;
			if (a[g] < b[h])
				g++;
			if (a[g] > b[h])
				h++;
		}

//		printf("%d\n", com);
//		printf("%d %d\n", n1, n2);

		double p0, p1, p2, p3;
		p0 = 1.0 * com / n;
		p1 = 1.0 * (n1 - com) / n;
		p2 = 1.0 * (n2 - com) / n;
		p3 = 1.0 - 1.0 * (n1 + n2 - com) / n;

//		printf("%f %f %f %f\n", p0, p1, p2, p3);

		memset(f, 0, sizeof(f));
		f[0][0][0] = 1.0;
		for (int k = 1; k <= day; k++)
			for (int i = 0; i <= k; i++)
				for (int j = 0; j <= k; j++)
				{
					f[k][i][j] = f[k - 1][i][j] * p3;
					f[k][i][j] += i ? f[k - 1][i - 1][j] * p1 : 0.0;
					f[k][i][j] += j ? f[k - 1][i][j - 1] * p2 : 0.0;
					f[k][i][j] += i && j ? f[k - 1][i - 1][j - 1] * p0 : 0.0;
				}

		double ans = 0.0;
		for (int i = 0; i * 2 <= day; i++)
			ans += f[day][i][i * 2];
		printf("Case %d: %.5f\n", tt++, fabs(ans));
//		exit(-1);
	}
	return 0;
}
