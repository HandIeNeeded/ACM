#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
const int M = 100005;
const int K = 15;

int dp[N][K], a[N];
int A[N][N], B[N][N], C[N][N];
int n, k;

void init() {
    REPP(i, 1, n) A[i][i] = B[i][i] = a[i];
    REPP(j, 1, n - 1) {
        REPP(i, 1, n) if (i + j <= n) {
            int k = i + j;
            A[i][k] = min(A[i][k - 1], A[i + 1][k]);
            B[i][k] = max(B[i][k - 1], B[i + 1][k]);
        }
    }
}

void update(int &x, int y) {
    if (x > y) x = y;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    while (scanf("%d%d", &n, &k), n | k) {
        REPP(i, 1, n) scanf("%d", a + i), a[i] += M;
        init();
        REPP(i, 1, n) {
            REPP(j, 1, k) dp[i][j] = INT_MAX;
        }
        REPP(i, 1, n) {
            REPP(j, 1, i) {
                REPP(d, 1, k - 1) if (dp[j - 1][d] != INT_MAX) {
                    update(dp[i][d + 1], dp[j - 1][d] + C[j][i]);
                }
            }
        }
        int ans = INT_MAX;
        REPP(i, 1, k) ans = min(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}


