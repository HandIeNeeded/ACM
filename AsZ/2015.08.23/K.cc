#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
int cnt[N << 1];
vector<pair<int, int> > edge[N];

void dfs(int x, int p, int now) {
    cnt[now]++;
    for (auto &y: edge[x]) {
        if (y.first != p) {
            dfs(y.first, x, now ^ y.second);
        }
    }
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REP(i, N) cnt[i] = 0;
        REPP(i, 1, n) edge[i].clear();
        REPP(i, 1, n - 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edge[x].push_back({y, z});
            edge[y].push_back({x, z});
        }
        dfs(1, 0, 0);
        int q;
        scanf("%d", &q);
        while (q--) {
            int x;
            scanf("%d", &x);
            LL ans = 0;
            REP(i, N) {
                ans += 1LL * cnt[x ^ i] * cnt[i];
            }
            if (x == 0) {
                ans -= n;
                ans >>= 1;
                ans += n;
            }
            else {
                ans >>= 1;
            }
            printf("%lld\n", ans);
        }
    }


    return 0;
}

