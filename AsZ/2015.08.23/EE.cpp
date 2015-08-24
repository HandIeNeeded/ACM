#include <bits/stdc++.h>

#define N 2020

using namespace std;

int dp[2][N];
int w[N], a[N], b[N];

int main()
{
    freopen("EE.in", "r", stdin);
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        int n, m;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d %d", &w[i], &a[i], &b[i]);
        for (int i = 0; i <= m; i++)
            dp[0][i] = dp[1][i] = -1;
        dp[0][0] = 0;
        int now = 1, pre = 0;
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < w[k]; i++)
                dp[now][i] = -1;
            for (int i = w[k]; i <= m; i++)
            {
                dp[now][i] = -1;
                if (dp[pre][i - w[k]] != -1)
                    dp[now][i] = max(dp[now][i], dp[pre][i - w[k]] + a[k] + b[k]);
                if (dp[now][i - w[k]] != -1)
                    dp[now][i] = max(dp[now][i], dp[now][i - w[k]] + a[k]);
            }
//            for (int i = 0; i <= m; i++)
//                printf("%d%c", dp[now][i], " \n"[i == m]);
            for (int i = 0; i <= m; i++)
                dp[now][i] = max(dp[now][i], dp[pre][i]);
            now = pre;
            pre ^= 1;
        }
        int ans = 0;
        for (int i = 0; i <= m; i++)
            ans = max(ans, dp[pre][i]);
        printf("%d\n", ans);
    }
    return 0;
}
