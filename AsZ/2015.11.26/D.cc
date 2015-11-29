#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;

int a[N], v[N];
LL dp[2][3][4 * N];

void toMax(LL &x, LL y) {
    if (y > x) x = y;
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        m <<= 1;
        REPP(i, 1, n) scanf("%d%d", a + i, v + i), a[i] <<= 1;
        int cur = 0;
        memset(dp[0], 0, sizeof(dp[0]));
        REPP(i, 1, n) {
            for (int j = m; j >= 1; j--) {
                dp[cur ^ 1][2][j] = dp[cur][2][j];
                if (j >= a[i]) {
                    toMax(dp[cur ^ 1][2][j], dp[cur][2][j - a[i]] + v[i]);
                }
                if (j >= a[i] / 2) {
                    toMax(dp[cur ^ 1][2][j], dp[cur][1][j - a[i] / 2] + v[i]);
                }
            }

            for (int j = m; j >= 1; j--) {
                dp[cur ^ 1][1][j] = dp[cur][1][j];
                if (j >= a[i]) {
                    toMax(dp[cur ^ 1][1][j], dp[cur][1][j - a[i]] + v[i]);
                }
                if (j >= a[i] / 2) {
                    toMax(dp[cur ^ 1][1][j], dp[cur][0][j - a[i] / 2] + v[i]);
                }
            }

            for (int j = m; j >= 1; j--) {
                dp[cur ^ 1][0][j] = dp[cur][0][j];
                if (j >= a[i]) {
                    toMax(dp[cur ^ 1][0][j], dp[cur][0][j - a[i]] + v[i]);
                }
            }
            cur ^= 1;
        }
        LL ans = 0;
        REP(i, 3) toMax(ans, dp[cur][i][m]);
        REPP(i, 1, n) toMax(ans, v[i]);
        printf("Case #%d: %lld\n", ca++, ans);
    }

    return 0;
}


