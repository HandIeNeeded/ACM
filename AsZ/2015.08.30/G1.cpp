#include <bits/stdc++.h>
#define MAXN 555
#define MAXM 51123456

using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN];
int visL[MAXN], visH[MAXN], ans[MAXN], vis[MAXN];

//vector <int> vec[2][i][j];
//int fir[MAXN], e[MAXM], nxt[MAXM];

struct node
{
    char ch;
    int x, y;
} g[MAXN];
int main()
{
   // freopen("g.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &b[i][j]);
          //      vec[0][i][j].clear();
           //     vec[1][i][j].clear();
            }
        scanf("\n");

        for (int i = 1; i <= m; ++i)
        {
            char ch;
            int x, y;
            scanf("%c%d%d\n", &g[i].ch, &g[i].x, &g[i].y);
        }
        memset(visH, 0, sizeof(visH));
        memset(visL, 0, sizeof(visL));
        memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        for (int tm = m; tm >= 1; --tm)
        {
            for (int i = 1; i <= m; ++i)
                if (!vis[i])
                {
                    int ok = 1;
                    char ch = g[i].ch;
                    int x = g[i].x, y = g[i].y;
                    if (ch == 'H')
                    {
                        if (visH[x]) ans[tm] = i;
                        else
                        {
                            for (int j = 1; j <= n && ok; ++j)
                                if (b[x][j] != y && b[x][j] != -1)
                                    ok = 0;

                            if (ok)
                            {
                                for (int j = 1; j <= n; ++j)
                                    b[x][j] = -1;
                                ans[tm] = i;
                                visH[x] = 1;
                            }
                        }
                    } else
                    {
                        if (visL[x]) ans[tm] = i;
                        else
                        {
                            for (int j = 1; j <= n && ok; ++j)
                                if (b[j][x] != y && b[j][x] != -1)// vec[0][j][x].push_back(i);
                                    ok = 0;
                            if (ok)
                            {
                                for (int j = 1; j <= n; ++j)
                                    b[j][x] = -1;
                                ans[tm] = i;
                                visL[x] = 1;
                            }
                        }
                            //else vec[1][j][x].push_back(i);
                    }
                    if (ok)
                    {
                        vis[i] = 1;
                        break;
                    }
                }
        }
   //     num = 0;
        /*memset(fir, 0, sizeof(fir));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int t1 = 0; t1 < vec[0][i][j].size(); ++t1)
                    for (int t2 = 0; t2 < vec[1][i][j].size(); ++t2); */
        for (int i = 1; i <= m; ++i)
            printf("%d%c", ans[i], " \n"[i == m]);


    }
    return 0;
}
