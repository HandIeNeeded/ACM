#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MP make_pair

using namespace std;

int line[60060], nex[60060];
int cost[60060], leng[60060];
bool vis[30030];
int en[30030];
int tot;

struct Con
{
	int v, co, le;
	Con(int v = 0, int co = 0, int le = 0) : v(v), co(co), le(le) {}
};

void ins(int x, int y, int z1, int z2)
{
	line[++tot] = y;
	cost[tot] = z1;
	leng[tot] = z2;
	nex[tot] = en[x];
	en[x] = tot;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("G.in", "r", stdin);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		tot = 0;
		MST(en, 0);
		MST(nex, 0);
		for (int i = 0; i < n - 1; i++)
		{
			int x, y, z1, z2;
			scanf("%d %d %d %d", &x, &y, &z1, &z2);
			ins(x, y, z1, z2);
			ins(y, x, z1, z2);
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			queue< Con > q;
			MST(vis, 0);
			q.push(Con(i + 1, 0, 0));
			vis[i + 1] = true;
			while (q.size())
			{
				int u = q.front().v;
				int c = q.front().co;
				int l = q.front().le;
				q.pop();

				ans = max(ans, l);

				int i = en[u];
				while (i)
				{
					int v = line[i];
					int co = cost[i];
					int le = leng[i];
					i = nex[i];

					if (vis[v])
						continue;
					if (c + co > m)
						continue;

					q.push(Con(v, c + co, l + le));
					vis[v] = true;
				}
			}
		}

		printf("Case %d: %d\n", tt, ans);
	}
	return 0;
}

