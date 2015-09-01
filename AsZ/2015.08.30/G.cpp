#include <bits/stdc++.h>
#define MAXN 555
#define MAXM 51123456

using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN];

vector <int> vec[2][i][j];
int fir[MAXN], e[MAXM], nxt[MAXM];

int main()
{
    freopen("g.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &b[i][j]);
                vec[0][i][j].clear();
                vec[1][i][j].clear();
            }
        for (int i = 1; i <= m; ++i)
        {
            char ch;
            int x, y;
            scanf("%c%d%d", &ch, &x, &y);
            if (ch == 'H')
            {
                for (int j = 1; j <= n; ++j)
                    if (b[x][j] != y) vec[0][x][j].push_back(i);
                    else vec[1][x][j].push_back(i);

            } else
            {
                for (int j = 1; j <= n; ++j)
                    if (b[j][x] != y) vec[0][j][x].push_back(i);
                    else vec[1][j][x].push_back(i);
            }
        }
        num = 0;
        memset(fir, 0, sizeof(fir));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int t1 = 0; t1 < vec[0][i][j].size(); ++t1)
                    for (int t2 = 0; t2 < vec[1][i][j].size(); ++t2);

    }
    return 0;
}
