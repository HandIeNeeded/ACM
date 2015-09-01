#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int MO = 258280327;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int mul(int x, int y)
{
    return (1LL * x * y) % MO;
}

int dp[N][N];
int C[N][N];

void init() {
    REPP(i, 0, 2000) {
        C[i][0] = C[i][i] = 1;
        REPP(j, 1, i - 1) {
            C[i][j] = C[i - 1][j];
            add(C[i][j], C[i - 1][j - 1]);
        }
    }
}

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

int ans[N];

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, y, p, q;
        scanf("%d%d%d", &n, &x, &y);
        x %= MO, y %= MO;
        p = 1LL * x * pow_mod(y, MO - 2) % MO;
        q = 1 - p, add(q, MO);

        REPP(i, 0, n) {
            REPP(j, 0, n) {
                dp[i][j] = 0;
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0][n] = 1;
        REPP(i, 0, n - 1) {
            REPP(j, 0, n) if (dp[i][j]) {
                REPP(k, 0, j - 1) {
                    add(dp[i + 1][k], 1LL * C[j - 1][k] * pow_mod(q, k) % MO * pow_mod(p, j - 1 - k) % MO * dp[i][j] % MO);
                }
            }
        }
        REPP(i, 0, n - 1) ans[i] = 0;
        REPP(i, 0, n - 1) {
            REPP(j, 1, n) {
                add(ans[i], dp[i][j]);
            }
        }
        REPP(i, 0, n - 1) {
            printf("%d%c", 1LL * ans[i] * pow_mod(n, MO - 2) % MO, " \n"[i == n - 1]);
        }
    }


    return 0;
}


