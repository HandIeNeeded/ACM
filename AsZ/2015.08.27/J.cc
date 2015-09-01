#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int MO = 1e9 + 7;
int dp[N][N];
int n, m;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
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

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        dp[0][0] = 1;
        REPP(i, 0, n - 1) {
            int upper = min(i, m);
            REPP(j, 0, upper) if (dp[i][j]) {
                if (j + 1 <= m) {
                    add(dp[i + 1][j + 1], 1LL * dp[i][j] * (m - j) % MO);
                }
                if (j - 1 >= 0) {
                    add(dp[i + 1][j - 1], 1LL * dp[i][j] * j % MO);
                }
            }
        }
        int ans = 0;
        REPP(i, 1, n) {
            int tmp = dp[i][0];
            add(tmp, dp[i][1]);
            add(ans, 1LL * tmp * (n - i + 1) % MO * pow_mod(m, n - i) % MO);
        }
        printf("%d\n", ans);
        REPP(i, 1, n) {
            REPP(j, 0, m) dp[i][j] = 0;
        }
    }




    return 0;
}

