#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int a[12][12], mark[12][12];
bool vis[12][12];
int ti;

inline bool outside(int x, int y)
{
    if (x <= 0 || y <= 0 || x >= 10 || y >= 10)
        return true;
    return false;
}

int bfs(int x, int y)
{
    vis[x][y] = true;
    int nx, ny, res = 0;
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (outside(nx, ny))
            continue;
        if (a[nx][ny] == 2 && !vis[nx][ny])
            res += bfs(nx, ny);
        if (a[nx][ny] == 0 && mark[nx][ny] < ti)
        {
            mark[nx][ny] = ti;
            res++;
        }
    }
    return res;
}

int main()
{
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif // HOME
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        char str[10];
        for (int i = 1; i <= 9; i++)
        {
            scanf("%s", str);
            for (int j = 1; j <= 9; j++)
            {
                if (str[j - 1] == '.')
                    a[i][j] = 0;
                if (str[j - 1] == 'x')
                    a[i][j] = 1;
                if (str[j - 1] == 'o')
                    a[i][j] = 2;
            }
        }
        bool flag = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; !flag && i <= 9; i++)
            for (int j = 1; !flag && j <= 9; j++)
                if (a[i][j] == 2 && !vis[i][j])
                {
                    ti++;
                    if (bfs(i, j) == 1)
                        flag = true;
                }
        if (flag)
            printf("Case #%d: Can kill in one move!!!\n", tt);
        else
            printf("Case #%d: Can not kill in one move!!!\n", tt);
    }
    return 0;
}
