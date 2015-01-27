#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
//	ios :: sync_with_stdio(0);
	int task;
	scanf("%d", &task);
	REPP(t, 1, task)
	{
		int n;
		int sum1 = 0, sum2 = 0;
		scanf("%d", &n);
		REPP(i, 1, n)
		{
			int x;
			scanf("%d", &x);
			sum1 += ((x / 30) + 1) * 10;
			sum2 += ((x / 60) + 1) * 15;
		}
		printf("Case %d: ", t);
		if (sum1 < sum2)
			printf("Mile %d\n", sum1);
		else if (sum1 > sum2)
			printf("Juice %d\n", sum2);
		else printf("Mile Juice %d\n", sum1);
	}
	return 0;
}
