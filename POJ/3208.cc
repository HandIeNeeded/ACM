#include <cstdio>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

LL dp[20][3][2], bit[20], pw[20];
bool vis[20][3][2];

LL dfs(int dep, int num, int has, int flag) {
    if (dep < 0) return has || num == 3;
    else if (flag && has) return pw[dep + 1];
    else if (flag && vis[dep][num][has]) return dp[dep][num][has];
    else {
        if (flag) {
            vis[dep][num][has] = 1;
            LL &ans = dp[dep][num][has];
            REP(i, 10) {
                ans += dfs(dep - 1, i == 6 ? num + 1 : 0, has || (num + (i == 6) >= 3), flag);
            }
            return ans;
        }
        else {
            LL ans = 0;
            REP(i, bit[dep] + 1) {
                ans += dfs(dep - 1, i == 6 ? num + 1 : 0, has || (num + (i == 6) >= 3), i < bit[dep]);
            }
            return ans;
        }
    }
}

LL count(LL x) {
    if (x == 0) return 0;
    int len = 0;
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, 0, 0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    pw[0] = 1;
    REPP(i, 1, 10) pw[i] = pw[i - 1] * 10;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        LL lo = 1, hi = 1e12;
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            if (count(mid) >= n) hi = mid;
            else lo = mid;
        }
        printf("%lld\n", hi);
    }

    return 0;
}
