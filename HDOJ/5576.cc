#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;
const int MO = 1e9 + 7;

char s[N];
int dp[N][N][N][N], pw[N], f[N][N][N], g[N][N][N], h[N][N][N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int get(int x) {
    return x * (x - 1) / 2; // x <= 50
}

int main() {
#ifdef HOME
    freopen("5576.in", "r", stdin);
#endif

    pw[0] = 1;
    REPP(i, 1, N - 1) pw[i] = 10LL * pw[i - 1] % MO;
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, s + 1);
        int length = strlen(s + 1);
        int pos = find(s + 1, s + length + 1, '*') - s;
        //cerr << pos << endl;
        REPP(i, 0, n) REPP(x, 1, length) REPP(y, 1, length) REPP(z, 1, length) dp[i][x][y][z] = 0;
        REPP(i, 1, length) if (s[i] != '*') {
            REPP(j, i + 1, length) if (s[j] != '*') {
                dp[0][i][j][pos] = (s[i] - '0') * (s[j] - '0');
            }
        }
        REPP(turn, 1, n) {
            REPP(y, 1, length) REPP(z, 1, length) {
                int tot = 0;
                REPP(x, 1, length) add(tot, dp[turn - 1][x][y][z]);
                REPP(x, 1, length) {
                    f[x][y][z] = tot;
                    add(f[x][y][z], MO - dp[turn - 1][x][y][z]);
                }
            }
            REPP(x, 1, length) REPP(z, 1, length) {
                int tot = 0;
                REPP(y, 1, length) add(tot, dp[turn - 1][x][y][z]);
                REPP(y, 1, length) {
                    g[x][y][z] = tot;
                    add(g[x][y][z], MO - dp[turn - 1][x][y][z]);
                }
            }
            REPP(x, 1, length) REPP(y, 1, length) {
                int tot = 0;
                REPP(z, 1, length) add(tot, dp[turn - 1][x][y][z]);
                REPP(z, 1, length) {
                    h[x][y][z] = tot;
                    add(h[x][y][z], MO - dp[turn - 1][x][y][z]);
                }
            }
            REPP(x, 1, length) {
                REPP(y, 1, length) if (y != x) {
                    REPP(z, 1, length) if (x != z && y != z) { //x y z be the new state
                        add(dp[turn][x][y][z], 1LL * get(length - 3) * dp[turn - 1][x][y][z] % MO);
                        add(dp[turn][x][y][z], f[x][y][z] % MO);
                        add(dp[turn][x][y][z], g[x][y][z] % MO);
                        add(dp[turn][x][y][z], h[x][y][z] % MO);
                        add(dp[turn][x][y][z], dp[turn - 1][y][x][z]);
                        add(dp[turn][x][y][z], dp[turn - 1][x][z][y]);
                        add(dp[turn][x][y][z], dp[turn - 1][z][y][x]);
                    }
                }
            }
        }
        int ans = 0;
        REPP(x, 1, length) REPP(y, 1, length) REPP(z, 1, length) if ((x < z && z < y) || (x > z && z > y)) {
            add(ans, 1LL * dp[n][x][y][z] * pw[z - x - 1 + length - y] % MO);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}

