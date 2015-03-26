#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	freopen("alter.in", "r", stdin);
	freopen("alter.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", n / 2 + m / 2);
	for (int i = 1; i <= n / 2; ++i)
	{
		int x = i * 2;
		printf("%d %d %d %d\n", x, 1, x, m);
	}
	for (int i = 1; i <= m / 2; ++i)
	{
		int x = i * 2;
		printf("%d %d %d %d\n", 1, x, n, x);
	}
	return 0;
}

