#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
const int MOD = 1e9 + 7;

int dp[N][N], c[N][N];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    ios :: sync_with_stdio(0);

    REPP(i, 0, 50) {
        c[i][0] = c[i][i] = 1;
        REPP(j, 1, i - 1) {
            c[i][j] = c[i - 1][j];
            add(c[i][j], c[i - 1][j - 1]);
        }
    }
    
    int n, m;
    while (cin >> n >> m) {
        REPP(i, 1, n) REPP(j, 1, m) {
            dp[i][j] = 0;
        }
        dp[0][0] = 1;
        REPP(i, 1, n) {
            REPP(j, 0, m) {
                REPP(k, 1, m) {
                    REPP(t, 0, k) if (j + t <= m) {
                        add(dp[i][j + t], 1LL * c[m - j][t] * c[j][k - t] % MOD * dp[i - 1][j] % MOD);
                    }
                }
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}
