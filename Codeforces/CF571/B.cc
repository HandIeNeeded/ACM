#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 3e5 + 5;
const int M = 5005;

int a[N];
LL dp[M][M];

void update(LL &x, LL y) {
    if (x > y) x = y;
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
    int n, K;

    scanf("%d%d", &n, &K);
    REPP(i, 1, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int t = n / K + 1, a = n % K, b = K - a;
    //a longer than b
    MST(dp, 0x3f);
    dp[0][0] = 0;
    REP(i, K) {
        REP(j, i + 1) {
            int k = i - j;
            if (j > a) continue;
            if (k > b) continue;
            int tot = j * t + k * (t - 1);
            if (j + 1 <= a) {
                int pos = tot + t;
                update(dp[j + 1][k], dp[j][k] + ::a[pos] - ::a[tot + 1]);
            }
            if (k + 1 <= b) {
                int pos = tot + t - 1;
                update(dp[j][k + 1], dp[j][k] + ::a[pos] - ::a[tot + 1]);
            }
        }
    }
    int ans = dp[a][b];
    printf("%d", ans);
    return 0;
}

