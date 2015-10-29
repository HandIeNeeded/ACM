#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MO 1000000007

using namespace std;
#define MAXM 1000

int n, m;

struct node
{
	int u, v, w[2][2];
}ed[MAXM];

int main() {
	ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
	scanf("%d%d", &n, &m);
	REP(i, m)
	{
		scanf("%d%d", &ed[i].u, &ed[i].v);
		REP(i1, 2)
			REP(j1, 2)
			scanf("%d", &ed[i].w[i1][j1]);
	}
	long long ans = 0;
	REP(i, (1 << n))
	{
		long long tmp = 1;
		REP(j, m)
		{
			int cu = 0, cv = 0;
			if ((1 << (ed[j].u - 1)) & i) cu = 1;
			if ((1 << (ed[j].v - 1)) & i) cv = 1;
			tmp = tmp * ed[j].w[cu][cv] % MO;
		}
		if (m == 0) tmp = 0;
		ans = (ans + tmp) % MO;
	}
	printf("%lld\n", ans);
	return 0;
}
