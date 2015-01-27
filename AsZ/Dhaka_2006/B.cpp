#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	freopen("B1.in", "r", stdin);
	int n;
	for (;scanf("%d", &n) != EOF;)
	{
		int ans = 0;
		int oh, om, ah, am;
        REPP(i, 1, n)
        {
			scanf("%d%d%d%d", &oh, &om, &ah, &am);
			int to = oh * 60 + om;
			int ta = ah * 60 + am;
			if (to <= ta) ans += ta - to;
		}
		printf("%d\n", (int) (ans / n));
	}

	return 0;
}

