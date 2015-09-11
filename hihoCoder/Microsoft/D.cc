#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int M = 2005;

int mp[N][N];
int dp[N][M];


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            scanf("%d", &mp[i][j]);
        }
    }
    REPP(i, 1, n) dp[i][0] = 0;
    REPP(k, 1, m) {
        REPP(i, 1, n) {
            REPP(j, 1, n) if (i != j && k >= mp[i][j]) {
                dp[i][k] = max(dp[i][k], dp[j][k - mp[i][j]] + 1);
            }
        }
    }
    int ans = 0;
    REPP(i, 1, n) {
        ans = max(ans, dp[i][m]);
    }
    printf("%d\n", ans);


    return 0;
}

