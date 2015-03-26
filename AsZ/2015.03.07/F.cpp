#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 4123

using namespace std;

char st[MAXN];
int n, m, f, g[MAXN], a[MAXN], L, d[MAXN][MAXN];
int ansNum, vis[MAXN], have[MAXN];

void getArr(int uk)
{
	MST(have, 0);
    REP(i, f) have[1LL * uk * a[i] % m] = 1;
    REP(i, L)
    {
        int l = i * 4;
		int r = l + 3;
		if (r >= m) r = m - 1;
		g[i] = 0;
		for (int j = r; j >= l; --j)
            g[i] = (g[i] << 1) + have[j];
    }
}

int check(int x)
{
    REP(i, L)
        if ((g[i] & d[x][i]) != g[i])
			return 0;
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("filter.in", "r", stdin);
	freopen("filter.out", "w", stdout);
	scanf("%d%d", &m, &f);
	L = m / 4;
	if (m % 4) L++;
	REP(i, f) scanf("%d", a + i);
	scanf("%d", &n);
    REP(i, n)
    {
		scanf("%s", st);
        REP(j, L)
		{
			if (st[j] >= '0' && st[j] <= '9')
                d[i][j] = st[j] - '0';
			else d[i][j] = st[j] - 'a' + 10;
		}
    }
	int q;
    scanf("%d", &q);
    REP(i, q)
    {
        int uk;
		scanf("%d", &uk);
        getArr(uk);
        REP(j, n)
			if (!vis[j] && check(j))
			{
				vis[j] = 1;
				ansNum++;
			}
    }
    printf("%d", ansNum);
    REP(i, n)
		if (vis[i])
			printf(" %d", i);
	printf("\n");
	return 0;
}
