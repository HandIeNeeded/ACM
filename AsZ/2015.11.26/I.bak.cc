#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 220;
const int MO = 1e9 + 7;
int dp[N][N][5][5][2];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][0] = 1;
        REP(i, n) {
            REP(j, m + 1) {
                REP(a, 5) {
                    REP(b, 5) {
                        REP(c, 2) if (dp[i][j][a][b][c]) {
                            //cout << "hehe" << i << ' ' << j << ' ' << a << ' ' << b << ' ' << c << ' ' << dp[i][j][a][b][c] << endl;
                            
                            //pair 2
                            if (!c) {
                                int limit = min(a, b);
                                limit = min(limit, 2);
                                REP(t, limit + 1) {
                                    add(dp[i + 1][j + 2 + t * 3][b - t][2 - t][1], dp[i][j][a][b][c]);
                                }
                            }

                            //pair 3
                            int limit = min(a, b);
                            limit = min(limit, 1);
                            REP(t, limit + 1) {
                                add(dp[i + 1][j + 3 + t * 3][b - t][1 - t][c], dp[i][j][a][b][c]);
                            }

                            //no pair
                            limit = min(a, b);
                            REP(t, limit + 1) {
                                add(dp[i + 1][j + t * 3][b - t][4 - t][c], dp[i][j][a][b][c]);
                            }
                        }
                    }
                }
            }
        }
        //cout << dp[2][5][1][2][1] << endl;
        int ans = 0;
        REP(a, 5) {
            REP(b, 5) {
                //cout << n << ' ' << m << ' ' << a << ' ' << b << ' ' << dp[n][m][a][b][1] << endl;
                add(ans, dp[n][m][a][b][1]);
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}


