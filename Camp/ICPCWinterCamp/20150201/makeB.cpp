#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define mem(a) memset(a, 0, sizeof(a))

using namespace std;

int main()
{
	srand(time(0) % clock());
	freopen("B.in", "w", stdout);
	int n = 4;
	int m = 4;
	int lim = 5;
	printf("%d %d\n", n, m);
	REPP(i, 1, m)
	{
		int u = rand() % (n / 2) + 1;
		int v = rand() % (n / 2) + (n / 2) + 1;
		printf("%d %d", u, v);
		REP(i, 4)
			printf(" %d", abs(rand() * rand() * rand()) % lim);
		printf("\n");
	}
	return 0;
}
