#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;

long double dp[2][N], sum[N];
int a[N];

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << fixed << setprecision(12) << 1.0 << endl;
        return 0;
    }
    int tot = 0;
    REPP(i, 1, n) cin >> a[i], tot += a[i];
    int cur = 0;
    REPP(i, 1, m) {
        dp[cur][i] = (i == a[1] ? 0 : 1.0 / (m - 1));
    }
    REPP(i, 1, 2 * m) sum[i] = sum[i - 1] + dp[cur][i];
    for (int i = 2 * m; i >= m; i--) sum[i] -= sum[i - m];
    REPP(i, 2, n) {
        for (int j = 1; j <= i * m; j++) {
            dp[cur ^ 1][j] = sum[j - 1] / (m - 1);
            if (j > a[i]) dp[cur ^ 1][j] -= dp[cur][j - a[i]] / (m - 1);
        }
        cur ^= 1;
        REPP(j, 1, (i + 1) * m) {
            sum[j] = sum[j - 1] + dp[cur][j];
        }
        for (int j = (i + 1) * m; j >= m; j--) {
            sum[j] -= sum[j - m];
        }
    }
    long double ans = 0;
    REPP(i, 1, tot - 1) ans += dp[cur][i];
    ans *= (m - 1);
    ans += 1;
    cout << fixed << setprecision(16) << ans << endl;

    return 0;
}

