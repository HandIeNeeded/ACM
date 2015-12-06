#include <bits/stdc++.h>
#define MAXN 1123
#define MAXT 123

using namespace std;

int dp[MAXN][MAXT];

struct node {
    int q, x;
} g[MAXN];

const int MO = 1e9+7;

int f[300][300];

void add(int &x, int y) {
    x = (x + y) % MO;
}

void mul(int &x, int y) {
    long long tmp = 1LL * x * y % MO;
    x = tmp;
}

void getDpg(int t) {
    for (int x = 0; x <= 250; ++x)
        for (int len = 0; len <= 250; ++len) {
            f[len][x] = 0;
            if (x == 0) {
                f[len][x] = 1;
                continue;
            }

            if (len < x) continue;

            else {
                for (int i = 1; i <= len; ++i) {
                    int nlen = len - i - t;
                    if (nlen <= 0) {
                        if (x == 1) add(f[len][x], 1);
                        continue;
                    }
                    add(f[len][x], f[nlen][x - 1]);
                }
            }
        }
    for (int len = 0; len <= 250; ++len)
        for (int x = 1; x <= 250; ++x)
            add(f[len][x], f[len][x - 1]);
}

int main() {
    freopen("kebab.in", "r", stdin);
#ifndef HOME
    freopen("kebab.out", "w", stdout);
#endif // HOME
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &g[i].q, &g[i].x);
    dp[0][t] = 1;
    getDpg(t);
  /*  for (int i = 0; i <= 4; ++i)
        for (int j = 0; j <= 4; ++j)
            printf("f[%d][%d] = %d\n", i, j, f[i][j]);
    */
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= t; ++j) {
            //no hole in i + 1
            int len = j + g[i + 1].q;
            int nj = min(len, t);
            add(dp[i + 1][nj], dp[i][j]);

            int holeCnt = g[i + 1].q - g[i + 1].x - 1;
            if (holeCnt >= 0) {
                for (int k = 1; k <= g[i + 1].q; ++k) {
                    len = j + k - 1;
                    int nj = min(t, g[i + 1].q - k);
                    if (len < t) continue;
                    len -= 2 * t;
                    if (len <= 0) {
                        add(dp[i + 1][nj], dp[i][j]);
                        continue;
                    }
                    int tmp = dp[i][j];
                    mul(tmp, f[len][holeCnt]);
                    add(dp[i + 1][nj], tmp);
                }
            }

        }
    int ans = 0;
    for (int i = 0; i <= t; ++i)
        add(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}

