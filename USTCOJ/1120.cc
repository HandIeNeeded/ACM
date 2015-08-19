#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 505;
int dp[N][N];
int a[N], b[N];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m), n | m) {
        REPP(i, 1, n) REPP(j, 1, m) dp[i][j] = 0;
        REPP(i, 1, n) scanf("%d", a + i);
        REPP(i, 1, m) scanf("%d", b + i); 
        REPP(i, 1, n) {
            int now = 0;
            REPP(j, 1, m) {
                dp[i][j] = dp[i - 1][j];
                if (a[i] > b[j]) now = max(now, dp[i - 1][j]);
                if (a[i] == b[j]) dp[i][j] = now + 1;
            }
        }
        int ans = 0;
        REPP(i, 1, m) ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }

    return 0;
}

