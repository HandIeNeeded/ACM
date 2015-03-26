#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset((a), (b), sizeof(a))
#define MAXN 2123

using namespace std;

int a[MAXN][MAXN], vis[MAXN], lab[MAXN];
int main()
{
	//freopen("K.in", "r", stdin);
	int T, n;
	for (scanf("%d", &T); T; --T)
	{
		scanf("%d", &n);
		REPP(i, 1, n)
			REPP(j, 1, n)
				scanf("%d", &a[i][j]);
		MST(vis, 0);
        REPP(i, 1, n)
			lab[a[1][i]] = i;
		vis[a[1][1]] = vis[a[1][2]] = 1;
		printf("%d %d\n", a[1][1], a[1][2]);
        REPP(ii, 2, n)
        {
			int i = a[1][ii];
			int u = a[i][1];
			int v = a[i][2];
			if (vis[u] && vis[v]) continue;
			if (vis[u] || vis[v])
			{
				vis[u] = vis[v] = 1;
				printf("%d %d\n", u, v);
				continue;
			}
            if (lab[u] > lab[v]) swap(u, v);
            REPP(j, 1, n)
            {
				if (vis[a[v][j]])
				{
					printf("%d %d\n", u, a[v][j]);
					break;
				}
			}
            printf("%d %d\n", u, v);
            vis[u] = vis[v] = 1;
        }
        printf("\n");
	}
	return 0;
}
