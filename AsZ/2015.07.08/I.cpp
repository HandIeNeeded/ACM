#include <bits/stdc++.h>

using namespace std;

int f[15][10010];
int a[20];

int main()
{
	//freopen("immetric.in", "r", stdin);
	//freopen("immetric.out", "w", stdout);
	int n, ca = 1;
	while (scanf("%d", &n) && n)
	{
		memset(f, 0, sizeof(f));
		int m = 1 << n + 1;
		for (int i = 0; i < m; i++)
		{
			int tmp = 0;
			for (int j = 0; j <= n; j++)
				if (i & (1 << j))
				{
					if ((j < n) && (i & (1 << j + 1)))
					{
						tmp += 1 << j;
						j++;
					} else
					{
						tmp = -1;
						break;
					}
				}
			// cout << i << " " << tmp << endl;
			if (tmp > 0)
				f[n][tmp]++;
		}
		for (int k = n - 1; k >= 1; k--)
		{
			int m = 1 << k + 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					for (int g = 0; g <= k; g++)
					{
						a[g] = 0;
						if (i & (1 << g))
							a[g]++;
						if (j & (1 << g))
							a[g]++;
					}
					// cout << i << " " << j << endl;
					// for (int g = 0; g <= k; g++)
					// 	printf("%d%c", a[g], " \n"[g == k]);
					// cout << endl;
					int tmp = 0;
					for (int g = 0; g <= k; g++)
						if (a[g])
						{
							if (g < k && a[g + 1])
							{
								a[g]--, a[g + 1]--;
								tmp += 1 << g;
								if (!a[g])
									continue;
							}
							tmp = -1;
							break;
						}
					if (tmp > 0)
						f[k][tmp] += f[k + 1][i];
				}
		}
		printf("Case #%d: %d\n", ca++, f[1][1]);
	}
	return 0;
}
