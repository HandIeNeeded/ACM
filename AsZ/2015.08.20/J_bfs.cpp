#include <cstdio>
#include <algorithm>
#define N 500500

using namespace std;

int line[N * 2], nex[N * 2], q[N];
int en[N], w[N], f[N], vis[N], res[N], fa[N];
int ca, tot, ans;

void ins(int x, int y)
{
	line[++tot] = y;
	nex[tot] = en[x];
	en[x] = tot;
}

void dp(int u)
{
	f[u] = 1;
	vis[u] = ca;
	int i = en[u];
	while (i)
	{
		int v = line[i];
		if (vis[v] < ca)
		{
			dp(v);
			if (w[u] < w[v])
				f[u] += f[v];
		}
		i = nex[i];
	}
}

void dfs(int u, int fa)
{
	vis[u] = ca;
	res[u] = f[u];
	if (u && w[u] < w[fa])
		res[u] += res[fa];
	ans = max(ans, res[u]);
	int i = en[u];
	while (i)
	{
		int v = line[i];
		if (vis[v] < ca)
			dfs(v, u);
		i = nex[i];
	}
}

int main()
{
	freopen("J.in", "r", stdin);
	int n;
	ca = 1;
	while (scanf("%d", &n) != EOF)
	{
		tot = 0;
		for (int i = 0; i < n; i++)
			en[i] = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);
		for (int i = 0; i < n - 1; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			ins(x, y);
			ins(y, x);
		}
		int len = 1;
		q[0] = 0;
		vis[0] = ca;
		for (int i = 0; i < n; i++)
		{
			int j = en[q[i]];
			while (j)
			{
				int u = line[j];
				if (vis[u] < ca)
				{
					q[len++] = u;
					fa[u]
					vis[u] = ca;
				}
				j = nex[j];
			}
		}
		ca++;
		dp(0);
//		for (int i = 0; i < n; i++)
//			printf("%d%c", f[i], " \n"[i == n - 1]);
		ca++;
		ans = 0;
		dfs(0, -1);
		ca++;
		printf("%d\n", ans);
	}
	return 0;
}
