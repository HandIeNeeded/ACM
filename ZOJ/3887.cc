#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int cnt[2];
int a[N], dp[N][17];
map<int, int> f[2];
vector<pair<int, int> > g[2];

int query(int L, int R) {
    int bit = 0;
    while ((1 << (bit + 1)) < (R - L + 1)) bit++;
    return __gcd(dp[L][bit], dp[R - (1 << bit) + 1][bit]);
}

void init(int id) {
    int n = cnt[id];
    REP(i, n) dp[i][0] = a[i];
    REPP(j, 1, 16) {
        REP(i, n) {
            if (i + (1 << j) > n) break;
            dp[i][j] = __gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    REP(i, n) {
        int L = i, R = i, now = a[i];
        while (R < n) {
            int lo = R, hi = n;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (query(L, mid) == now) {
                    lo = mid;
                }
                else hi = mid;
            }
            g[id].push_back(make_pair(now, hi - L));
            f[id][now] = max(f[id][now], hi - L);
            now = __gcd(now, a[hi]);
            R = hi;
        }
    }
}

int main() {
#ifdef HOME
        freopen("3887.in", "r", stdin);
#endif

    while (scanf("%d%d", &cnt[0], &cnt[1]) > 0) {
        REP(i, 2) {
            f[i].clear(), g[i].clear();
            a[cnt[i]] = 0;
            REP(j, cnt[i]) {
                scanf("%d", &a[j]);
            }
            init(i);
        }
        int ans = 0;
        LL num = 0;
        for (auto &p: f[0]) {
            int x, y;
            tie(x, y) = p;
            if (!f[1].count(x)) continue;
            if (min(f[0][x], f[1][x]) > ans) {
                ans = min(f[0][x], f[1][x]);
            }
        }
        REP(i, 2) {
            f[i].clear();
            for (auto &x: g[i]) {
                int a, b;
                tie(a, b) = x;
                if (b >= ans) f[i][a]++;
            }
        }
        for (auto &p: f[0]) {
            int x, y;
            tie(x, y) = p;
            if (!f[1].count(x)) continue;
            num += 1LL * f[0][x] * f[1][x];
        }
        printf("%d %lld\n", ans, num);
    }
    return 0;
}
