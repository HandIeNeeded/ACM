#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

int mp[MAXN];

int ans[2][MAXN * 2][MAXN * 2];

void solve(int k1, int i1, int j1, int k2, int i2, int j2, int off)
{
    ans[k1][i1][j1] = ans[k2][i2][j2] + off;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i = 1; i <= 1000; ++i)
        mp[i] = -1;
    for (int i = 0; i <= 9; ++i)
        mp[1 << i] = i;

    ans[0][1][1] = 1;
    ans[0][2][1] = ans[0][2][2] = 1;
    //printf("%d\n", );
    int n;
    for (; scanf("%d", &n) != EOF; )
    {
        if (mp[n] == -1)
            printf("impossible\n");
        else
        {
            int x = mp[n];


            ans[0][1][1] = 1;
            ans[0][2][1] = ans[0][2][2] = 1;
            for (int k = 1; k <= x; ++k)
            {
                int n2 = 1 << k;
                int n1 = n2 >> 1;
                int lcnt = 1 << (2 * (k - 1));
                for (int i = 1; i <= n1; ++i)
                    for (int j = 1; j <= n1; ++j)
                    {
                        solve(1, n2 + i, j, 0, i, j, 0);
                        solve(1, n2 / 2 + i, n2 / 2 + j, 0, i, j, lcnt);
                        solve(1, j, n2 - i + 1, 0, i, j, lcnt * 2);
                        solve(1, n2 + i, n2 + n2 - j + 1, 0, i, j, lcnt * 3);
                    }

                for (int i = n1 + 1; i <= n1 + n1; ++i)
                    for (int j = 1; j <= n2; ++j)
                    {

                        solve(1, n2 + i, j, 0, i, j, 0);
                        solve(1, n2 / 2 + i, n2 / 2 + j, 0, i, j, lcnt);
                        solve(1, j, n2 - i + 1, 0, i, j, lcnt * 2);
                        solve(1, n2 + i, n2 + n2 - j + 1, 0, i, j, lcnt * 3);
                    }


                for (int i = 1; i <= n2; ++i)
                    for (int j = 1; j <= n2; ++j)
                    {
                        solve(0, i, j, 1, i, j, 0);
                    }

                for (int i = n2 + 1; i <= n2 + n2; ++i)
                    for (int j = 1; j <= n2 + n2; ++j)
                    {
                        solve(0, i, j, 1, i, j, 0);
                    }
            }

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    printf("%5d%c", ans[0][i][j], " \n"[j == n]);
            for (int i = n + 1; i <= n + n; ++i)
                for (int j = 1; j <= n * 2; ++j)
                    printf("%5d%c", ans[0][i][j], " \n"[j == n * 2]);
        }
    }
    return 0;
}
