#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("E.in", "r", stdin);
	int n;
	scanf("%d", &n);

	vector<int> a, b;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a.push_back(x);
		b.push_back(y);
	}

	int win = 0;
	vector<bool> link;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[i])
			win++;
		if (i == n - 1)
			break;
		int d1 = a[i] - b[i];
		int d2 = a[i + 1] - b[i + 1];
		if (d1 > 0 && d2 > 0)
		{
			link.push_back(false);
			continue;
		}
		if (d1 > 0 && d2 < 0 && d1 + d2 <= 0)
		{
			link.push_back(false);
			continue;
		}
		if (d1 < 0 && d2 > 0 && d1 + d2 <= 0)
		{
			link.push_back(false);
			continue;
		}
		link.push_back(true);
	}

//	for (int i = 0; i < n - 1; i++)
//		cout << link[i] << endl;

	int least = n - win * 2 + 1;
	if (least <= 0)
	{
		printf("0\n");
		return 0;
	}

	int i = 0;
	vector<bool> vis;
	while (least && i < n - 1)
	{
		if (link[i])
		{
			vis.push_back(true);
			vis.push_back(true);
			least--;
			i += 2;
		} else
		{
			vis.push_back(false);
			i += 1;
		}
	}
	if (least)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", n - win * 2 + 1);
	for (int i = 0; i < vis.size();)
		if (vis[i])
		{
			printf("%d %d\n", i + 1, i + 2);
			i += 2;
		} else
			i += 1;
	return 0;
}
