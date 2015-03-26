#include <bits/stdc++.h>

using namespace std;

int x[10], y[10];
bool vis[500];

bool cmp(int g, int h)
{
	return (x[g] <= x[h]) && (y[g] <= y[h]);
}

int main()
{
	for (int i = 1; i < 10; i++)
	{
		x[i] = (i - 1) % 3;
		y[i] = (i - 1) / 3;
	}
	x[0] = 1, y[0] = 3;
	for (int i = 0; i <= 400; i++)
	{
		int a1 = i / 100;
		int a2 = (i % 100) / 10;
		int a3 = i % 10;
		if (!a1)
		{
			if (!a2)
				vis[i] = true;
			else
				vis[i] = cmp(a2, a3);
		} else
			vis[i] = cmp(a1, a2) && cmp(a2, a3);
	}
	int ttt;
	scanf("%d", &ttt);
	while (ttt--)
	{
		int z;
		scanf("%d", &z);
		for (int k = 0; k <= z; k++)
		{
			if (vis[z - k])
			{
				printf("%d\n", z - k);
				break;
			}
			if (vis[z + k])
			{
				printf("%d\n", z + k);
				break;
			}
		}
	}
	return 0;
}
