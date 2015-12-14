#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 205;
int a[N], b[N];
LL dp[N][N], f[N][N];

void update(LL &x, int y) {
    if (x > y) x = y;
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        a[0] = a[n + 1] = b[0] = b[n + 1] = 0;
        REPP(i, 1, n) REPP(j, 1, n) dp[i][j] = f[i][j] = 0;
        REPP(i, 1, n) {
            scanf("%d", a + i);
        }
        REPP(i, 1, n) {
            scanf("%d", b + i);
        }
        if (n == 2) {
            printf("Case #%d: %d\n", ca++, min(a[1] + b[1 + 1] + a[1 + 1], a[1 + 1] + b[1] + a[1]));
            continue;
        }
        REPP(i, 1, n) dp[i][i] = a[i] + b[i], f[i][i] = a[i];
        REPP(i, 1, n - 1) {
            dp[i][i + 1] = min(a[i] + a[i + 1] + 2 * b[i + 1], a[i] + a[i + 1] + 2 * b[i]);
            f[i][i + 1] = min(a[i] + b[i + 1] + a[i + 1], b[i] + a[i + 1] + a[i]);
        }
        REPP(k, 2, n - 1) {
            REPP(i, 1, n) if (i + k <= n) {
                int j = i + k;
                f[i][j] = min(dp[i][i] + dp[i + 1][j], dp[j][j] + dp[i][j - 1]);
                if (f[i][j] == 15) {
                    cout << "hehe" << i << ' ' << j << endl;
                }
                dp[i][j] = min(dp[i][i] + dp[i + 1][j], dp[j][j] + dp[i][j - 1]);
                REPP(end, i, j - 1) {
                    update(f[i][j], min(f[i][end] + dp[end + 1][j], dp[i][end] + f[end + 1][j]));
                    update(dp[i][j], dp[i][end] + dp[end + 1][j]);
                }
            }
        }
        REPP(i, 1, n) {
            REPP(j, 1, n) {
                cout << f[i][j] << ' ';
            }
            cout << endl;
        }
        REPP(i, 1, n) {
            REPP(j, 1, n) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        printf("Case #%d: %lld\n", ca++, f[1][n]);
    }
    return 0;
}

