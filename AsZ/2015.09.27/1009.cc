#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 31;
int mp[N][N];
int dp[N][N];
pair<int, int> pre[N][N];
int C, n, m;

inline int sqr(int x) {
    return x * x;
}

void update(int a, int b, int c, int d, int avg) {
    int tmp = dp[c][d] + sqr(C * mp[a][b] - avg);
    if (dp[a][b] > tmp) {
        dp[a][b] = tmp;
        pre[a][b] = {c, d};
    }
}

int go_dp(int avg) {
    dp[1][1] = sqr(C * mp[1][1] - avg);
    REPP(i, 2, m) dp[1][i] = dp[1][i - 1] + sqr(C * mp[1][i] - avg), pre[1][i] = {1, i - 1};
    REPP(i, 2, n) dp[i][1] = dp[i - 1][1] + sqr(C * mp[i][1] - avg), pre[i][1] = {i - 1, 1};
    REPP(i, 2, n) {
        REPP(j, 2, m) {
            dp[i][j] = INT_MAX;
            update(i, j, i - 1, j, avg);
            update(i, j, i, j - 1, avg);
        }
    }
    int a = n, b = m, tot = 0, sum = 0;
    while (a || b) {
        tot += mp[a][b];
        sum += sqr(mp[a][b]);
        tie(a, b) = pre[a][b];
    }
    return C * sum - sqr(tot);
}

int main() {
#ifdef HOME
    freopen("test.in", "r", stdin);
    clock_t st = clock();
#endif

    int t, ca = 1;
    scanf("%d", &t);
    assert(t <= 30);
    while (t--) {
        scanf("%d%d", &n, &m);
        assert(n <= 30 && n > 0);
        assert(m <= 30 && m > 0);
        REPP(i, 1, n) {
            REPP(j, 1, m) {
                scanf("%d", &mp[i][j]);
                assert(mp[i][j] >= 0 && mp[i][j] <= 30);
            }
        }
        C = n + m - 1;
        int ans = INT_MAX;
        REPP(i, 0, C * 30) {
            ans = min(ans, go_dp(i));
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
#ifdef HOME
    clock_t ed = clock();
    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}
