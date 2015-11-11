#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 300;
int a[100006];
LL dp[2][N];

void update(LL &x, LL y) {
    if (x < y) x = y;
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) scanf("%x", a + i);
    memset(dp, -1, sizeof(dp));
    int cur = 0;
    dp[cur][0] = 0;
    REPP(i, 1, n) {
        REP(j, N) if (j <= i) {
            if (j == i) {
                dp[cur ^ 1][j] = 0;
                continue;
            }
            //not choose
            if (j - 1 >= 0 && dp[cur][j - 1] >= 0) update(dp[cur ^ 1][j], dp[cur][j - 1]);

            //choose
            if (dp[cur][j] >= 0) update(dp[cur ^ 1][j], dp[cur][j] + (a[i] ^ (i - j - 1)));
        }
        memset(dp[cur], -1, sizeof(dp[cur]));
        cur ^= 1;
    }
    LL ans = LLONG_MIN;
    REP(i, N) ans = max(ans, dp[cur][i]);
    cout << ans << endl;
    return 0;
}


