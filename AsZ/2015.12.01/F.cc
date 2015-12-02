#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int L = 105;  
const int K = 15;
const int MO = 1e9 + 7;
int dp[K][L], c[K], sum[K];
int fac[N], inv[N];

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
    REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    init();
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        memset(dp, 0, sizeof(dp));
        scanf("%d%d%d", &n, &m, &k);
        REPP(i, 1, m) scanf("%d", c + i);
        REPP(i, 1, m) sum[i] = sum[i - 1] + c[i];
        dp[0][k] = 1;
        REPP(i, 0, m - 1) {
            REPP(j, 0, k) if (dp[i][j]) {
                REPP(a, 0, j) {//one
                    REPP(b, 0, j - a) {//two
                        if (a + 2 * b > c[i + 1]) break;
                        int tot = n - sum[i] - 2 * j;
                        int space = c[i + 1] - a - 2 * b;
                        int tmp = 1LL * C(j, a) * C(j - a, b) % MO;
                        tmp = 1LL * tmp * C(tot, space) % MO;
                        add(dp[i + 1][j - a - b], 1LL * tmp * dp[i][j] % MO);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ca++, dp[m][0]);
    }


    return 0;
}


