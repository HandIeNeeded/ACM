#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int L = 70;
const int N = 7e4 + 5;
const int p[5] = {3, 5, 17, 257, 65537};
const int inv[5] = {0, 2, 6, 86, 21846};
LL dp[L][5][N], pw[L][5] = {1};
bool vis[L][5][N];
int bit[L];

LL solve(int dep, int k, int now, int flag) {
    if (dep < 0) return now == 0;
    if (flag && vis[dep][k][now]) {
        return dp[dep][k][now];
    }
    else {
        if (flag) {
            vis[dep][k][now] = 1;
            LL &ans = dp[dep][k][now];
            ans += solve(dep - 1, k, now, 1);
            ans += solve(dep - 1, k, (now + p[k] - pw[dep][k]) % p[k], 1);
            return ans;
        }
        else {
            LL ans = 0;
            ans += solve(dep - 1, k, now, bit[dep] == 1);
            if (bit[dep]) {
                ans += solve(dep - 1, k, (now + p[k] - pw[dep][k]) % p[k], 0);
            }
            return ans;
        }
    }
}

LL get(LL n, int k, int reminder) {
    int length = 0;
    while (n) {
        bit[length++] = n & 1;
        n >>= 1;
    }
    return solve(length - 1, k, reminder, 0);
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif

    REP(k, 5) pw[0][k] = 1;
    REP(k, 5) REPP(i, 1, L - 1) pw[i][k] = 3 * pw[i - 1][k] % p[k];
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        int k;
        scanf("%lld%d", &n, &k);
        k = find(p, p + 5, k) - p;
        LL ans = 0;
        REP(i, p[k]) {
            LL tmp = get(n, k, i);
            if (i == 0) tmp--;
            //cout << i << ' ' << tmp << endl;
            ans ^= tmp;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

