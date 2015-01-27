#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 30000

using namespace std;
typedef int arrayN[MAXN];

int num, n, c1, c2, f[MAXN][9];
arrayN fir, e, nxt;

const int INF = 0x3f3f3f3f;


void link(int u, int v)
{
	e[++num] = v, nxt[num] = fir[u];
	fir[u] = num;
}

void dfs(int x, int fa)
{
    int flag = 0;
    for (int p = fir[x]; p; p = nxt[p])
		if (e[p] != fa)
		{
			flag = 1;
            REPP(i, 0, 3)
				if (f[e[p]][i] == -1)
					dfs(e[p], x);
		}
	if (!flag)
	{
        f[x][0] = INF;
        f[x][1] = 0;
        f[x][2] = c1;
        f[x][3] = c2;
        return ;
	}

	int tmp0 = 0;
	f[x][1] = 0;
	int tmp2 = c1;
	f[x][3] = c2;
	f[x][0] = INF;
	f[x][2] = INF;
    for (int p = fir[x]; p; p = nxt[p])
		if (e[p] != fa)
		{
            tmp0 += min(f[e[p]][1], f[e[p]][2]); //-1
			f[x][1] += f[e[p]][2]; // 0
			f[x][3] += min(min(f[e[p]][0], f[e[p]][1]), min(f[e[p]][2], f[e[p]][3]));
			tmp2 += min(min(f[e[p]][1], f[e[p]][2]), f[e[p]][3]);
		}

	flag = 0;
	f[x][2] = tmp2;
	for (int p = fir[x]; p; p = nxt[p])
		if (e[p] != fa)
		{
			//if (!flag)
			//{
				//f[x][0] = tmp0 - min(f[e[p]][1], f[e[p]][2]) + f[e[p]][1];
			//	f[x][2] = tmp2 - min(min(f[e[p]][1], f[e[p]][2]), f[e[p]][3]) - c1 + f[e[p]][3];
			//}
			//else
			{
				f[x][2] = min(f[x][2], tmp2 - min(min(f[e[p]][1], f[e[p]][2]), f[e[p]][3]) + f[e[p]][3] - c1);
				f[x][0] = min(f[x][0], tmp0 - min(f[e[p]][1], f[e[p]][2]) + f[e[p]][1]);
			}
			//flag = 1;
		}
}

int main() {
	freopen("I.in", "r", stdin);
	for (;;)
	{
		scanf("%d%d%d", &n, &c1, &c2);
		if (n + c1 + c2 == 0) break;
        MST(fir, 0);
        num = 0;
        REPP(i, 1, n - 1)
        {
			int u, v;
			scanf("%d%d", &u, &v);
			link(u, v);
			link(v, u);
		}
        MST(f, -1);
        dfs(1, 1);
        int ans = min(f[1][1], min(f[1][2], f[1][3]));
        printf("%d\n", ans);
	}


	return 0;
}

