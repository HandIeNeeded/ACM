#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 200

using namespace std;


char st[MAXN];

int n, vis[MAXN], have[MAXN], len, fir[MAXN];
int nxt[MAXN * 100], e[MAXN * 100], num;

int findN(int len)
{
	if (len < 10) return len;
	for (int i = 10; i <= len; ++i)
	{
		if (9 + 2 * (i - 9) == len) return i;
	}
	return 0;
}

void link(int u, int v)
{
	e[++num] = v, nxt[num] = fir[u];
	fir[u] = num;
}

int dfs(int dep)
{
    if (dep == 0)
    {
		REP(i, len)
		{
			if (i && (have[i])) printf(" ");
			printf("%c", st[i]);
		}
		printf("\n");
		return 1;
    }
    for (int p = fir[dep]; p; p = nxt[p])
    {
		int ok = 1;
        if (vis[e[p]]) ok = 0;
		if (dep > 9 && vis[e[p] + 1]) ok = 0;
        if (ok)
        {
			vis[e[p]] = 1;
			if (dep > 9) vis[e[p] + 1] = 1;
            have[e[p]] = 1;
			if (dfs(dep - 1)) return 1;
			vis[e[p]] = 0;
			have[e[p]] = 0;
			if (dep > 9) vis[e[p] + 1] = 0;
        }
    }
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("joke.in", "r", stdin);
	freopen("joke.out", "w", stdout);
	scanf("%s", st);
	len = strlen(st);
	n = findN(len);
	//cout << n << endl;
	MST(vis, 0);
    REPP(i, 1, n)
    {
		int lim = len - 1;
		if (i > 9) lim = len - 2;
        REPP(j, 0, lim)
        {
			int x;
			if (i <= 9) x = st[j] - '0';
			else x = (st[j] - '0') * 10 + st[j + 1] - '0';
			if (x == i) link(i, j);
        }
    }
    dfs(n);
	return 0;
}
