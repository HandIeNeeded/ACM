#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 505;
const int inf = -2e7;

int mp[20][N], tmp[N], dp[N][2], ans, n, m;

void update(int &x, int y) {
    if (x < y) x = y;
}

void go() {
    dp[0][0] = dp[0][1] = inf;
    REPP(i, 1, m) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        int d = i & 1;
        update(dp[i][d], tmp[i]);
        update(dp[i][d], dp[i - 1][d ^ 1] + tmp[i]);
    }
    update(ans, dp[m][0]);
    update(ans, dp[m][1]);
}

void dfs(int dep, int limit, int now) {
    if (dep == limit) {
        if (now) {
            REPP(i, 1, m) tmp[i] = 0;
            REP(i, limit) if (now & (1 << i)) {
                REPP(j, 1, m) tmp[j] += mp[i][j];
            }
            go();
        }
        return ;
    }
    dfs(dep + 1, limit, now);
    int pos = __builtin_clz(now);
    if (now == 0 || ((dep - pos) & 1) == 0) {
        dfs(dep + 1, limit, now | (1 << dep));
    }
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        REP(i, n) {
            REPP(j, 1, m) {
                scanf("%d", &mp[i][j]);
            }
        }
        ans = inf;
        dfs(0, n, 0);
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}

