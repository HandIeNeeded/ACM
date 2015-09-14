#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 205;
int dp[N][N][4][4], vis[N][N][4][4], a[N];
char s[N];

void update(int &x, int y) {
    if (y >= x) x = y;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        REPP(i, 1, n) a[i] = s[i] == 'B';
        REPP(i, 1, n) {
            REPP(j, i, n) {
                REP(l, 4) {
                    REP(r, 4) {
                        dp[i][j][l][r] = -1;
                    }
                }
            }
        }
        REPP(i, 1, n) dp[i][i][a[i]][a[i]] = 0;
        REPP(i, 1, n - 1) {
            if (a[i] == a[i + 1]) {
                dp[i][i + 1][a[i] + 2][a[i] + 2] = 0;
            }
            else {
                dp[i][i + 1][a[i]][a[i + 1]] = 0;
            }
        }
        REPP(k, 2, n) {
            REPP(i, 1, n) {
                int j = i + k;
                if (j > n) break;
                REPP(mid, i, j - 1) {
                    REP(a, 4) {
                        REP(b, 4) if (dp[i][mid][a][b] != -1) {
                            REP(c, 4) {
                                REP(d, 4) if (dp[mid + 1][j][c][d] != -1) {
                                    update(dp[i][j][][], );
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        REP(l, 4) REP(r, 4) ans = max(ans, dp[1][n][l][r]);
        printf("%d\n", ans);
    }

    return 0;
}

