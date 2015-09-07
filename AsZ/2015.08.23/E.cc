#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
int dp[2][N][N];
int n, m, A[N], B[N], W[N];

void update(int &x, int y) {
    if (y > x) x = y;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        REPP(i, 1, n) {
            scanf("%d%d%d", W + i, A + i, B + i);
        }
        REP(i, 2) {
            REPP(j, 0, n) {
                REPP(k, 0, m) {
                    dp[i][j][k] = 0;
                }
            }
        }
        REPP(i, 0, n - 1) {
            int w = W[i + 1], a = A[i + 1], b = B[i + 1];
            REPP(j, 0, m) if (j + w <= m) {
                update(dp[0][i + 1][j + w], dp[0][i][j] + a + b);
                update(dp[0][i + 1][j + w], dp[1][i][j] + a + b);
            }
            REPP(j, 0, m) {
                if(j) update(dp[0][i + 1][j], dp[0][i + 1][j - 1]);
                dp[1][i + 1][j] = dp[0][i + 1][j];
                update(dp[1][i + 1][j], dp[0][i][j]);
                update(dp[1][i + 1][j], dp[1][i][j]);
            }
            REPP(j, 0, m) if (j + w <= m) {
                update(dp[1][i + 1][j + w], dp[1][i + 1][j] + a);
            }
            REPP(j, 1, m) {
                update(dp[1][i + 1][j], dp[1][i + 1][j - 1]);
            }
        }
        printf("%d\n", dp[1][n][m]);
    }

    return 0;
}

