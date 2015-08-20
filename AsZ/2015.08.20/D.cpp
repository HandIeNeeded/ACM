#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int vis[MAXN][MAXN], g[MAXN][MAXN];
char ch[MAXN][MAXN];

int main()
{
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	for (; ca; --ca)
	{
		int n;
		scanf("%d", &n);
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", ch[i]);
			m = strlen(ch[i]);
			for (int j = 0; j < m; ++j)
				if (ch[i][j] == 'B')
					g[i][j] = 1;
				else if (ch[i][j] == 'R')
					g[i][j] = 2;
				else if (ch[i][j] == 'G')
					g[i][j] = 3;
				else g[i][j] = 0;
		}
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (vis[i][j] == g[i][j]) continue;
                int tmp = g[i][j] - vis[i][j];
                if (tmp & 1)
                {
					++ans;
                    int ti = i, tj = j;
                    for (;ti < n && tj >= 0;)
                    {
                        if ((g[ti][tj] & 1) && !(vis[ti][tj] & 1))
                        {
							vis[ti][tj] += 1;
							ti++;
							tj--;
						} else break;
					}
                }
                if (tmp & 2)
                {
					++ans;
                    int ti = i, tj = j;
                    for (;ti < n && tj < m;)
                    {
                        if ((g[ti][tj] & 2) && !(vis[ti][tj] & 2))
                        {
							vis[ti][tj] += 2;
							ti++;
							tj++;
						} else break;
					}
                }
			}
		cout << ans << endl;
	}
	return 0;
}
