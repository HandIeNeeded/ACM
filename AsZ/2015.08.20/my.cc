#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int cnt[2];
int a[2][N], dp[2][N][17];
map<int, int> f[2];
vector<pair<int, int> > g[2];

int query(int type, int L, int R) {
    int bit = 0;
    while ((1 << (bit + 1)) < (R - L + 1)) bit++;
    return __gcd(dp[type][L][bit], dp[type][R - (1 << bit) + 1][bit]);
}

void init(int id) {
    int n = cnt[id];
    REP(i, n) dp[id][i][0] = a[id][i];
    REPP(j, 1, 16) {
        REP(i, n) {
            if (i + (1 << j) > n) break;
            dp[id][i][j] = __gcd(dp[id][i][j - 1], dp[id][i + (1 << (j - 1))][j - 1]);
        }
    }
    REP(i, n) {
        int L = i, R = i, now = a[id][i];
        while (R < n) {
            int lo = R, hi = n;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (query(id, L, mid) == now) {
                    lo = mid;
                }
                else hi = mid;
            }
            g[id].push_back(make_pair(now, hi - L));
            f[id][now] = max(f[id][now], hi - L);
            now = __gcd(now, a[id][hi]);
            R = hi;
        }
    }
}

int main() {
    freopen("tmp.in", "r", stdin);
    while (scanf("%d%d", &cnt[0], &cnt[1]) > 0) {
        REP(i, 2) {
            f[i].clear(), g[i].clear();
            a[i][cnt[i]] = 0;
            REP(j, cnt[i]) {
                scanf("%d", &a[i][j]);
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
                cout << x << "hehe" << endl;
                ans = min(f[0][x], f[1][x]);
            }
        }
        REP(i, 2) {
            f[i].clear();
            REP(j, cnt[i]) {
                if (j + ans > cnt[i]) continue;
                f[i][query(i, j, j + ans - 1)]++;
            }
        }
        for (auto &p: f[0]) {
            int x, y;
            tie(x, y) = p;
            if (!f[1].count(x)) continue;
            cout << x << ' ' << f[0][x] << ' ' << f[1][x] << endl;
            num += 1LL * f[0][x] * f[1][x];
        }
        printf("%d %lld\n", ans, num);
    }

    return 0;
}
