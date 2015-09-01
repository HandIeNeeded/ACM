#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 258280327;
int dp[N][10], a[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        if (a == 9) a = 0;
        if (b == 9) b = 0;
        int s = 0;
        REPP(i, 1, n) scanf("%d", ::a + i), s += ::a[i];
        s %= 9;
        dp[0][0] = 1;
        REPP(i, 0, n - 1) {
            REP(j, 10) dp[i + 1][j] = dp[i][j];
            REP(j, 10) {
                int tmp = j + ::a[i];
                if (tmp >= 9) tmp -= 9;
                add(dp[i + 1][tmp], dp[i][j]);
            }
        }
        int ans = 0;
        if (s == (a + b) % 9) {
            add(ans, dp[n][a]);
            add(ans, dp[n][b]);
            ans = 1LL * ans * (MO / 2 + 1) % MO;
        }
        else {
            if (s == a || s == b) ans = 1;
        }
        printf("%d\n", ans);
    }


    return 0;
}

