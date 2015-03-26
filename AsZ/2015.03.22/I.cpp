#include <bits/stdc++.h>

using namespace std;
int n, a[3000];
long long sum = 0;

int main()
{
	//freopen("")
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 1;

	for (int i = 0; i <= n - 2; ++i)
	{
		sum += a[i];
		if (sum <= a[n - 1]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
