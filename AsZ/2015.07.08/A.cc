#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("avangard.in", "r", stdin);
	freopen("avangard.out", "w", stdout);
	int n;
	scanf("%d", &n);

	int p = 3;
	bool flag = true;
	for (; p < 2000 && !flag; p++)
	{
		flag = true;
		for (int i = 2; i < p; i++)
			if (p % i == 0)
			{
				flag = false;
				break;
			}
		if (flag && n % p == 0)
			flag = false;
	}


	if (n % 2 == 0)
	{
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	for (int i = 0; i < n; i++)
	{
		int k = i * p;
		for (int j = 0; j < n; j++)
			printf("%2d%c", (j + k) % n + 1, " \n"[j == n - 1]);
	}

	return 0;
}
