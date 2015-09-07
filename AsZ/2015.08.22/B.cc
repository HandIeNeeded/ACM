#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int T = 17;

pair<int, int> dp[N][T];
int a[N], n;

void init() {
    REPP(i, 1, n) dp[i][0] = {a[i], a[i]};
    REPP(j, 1, T - 1) {
        REPP(i, 1, n) {
            if (i + (1 << j) - 1 > n) break;
            dp[i][j].first = max(dp[i][j - 1].first, dp[i + (1 << (j - 1))][j - 1].first);
            dp[i][j].second = min(dp[i][j - 1].second, dp[i + (1 << (j - 1))][j - 1].second);
        }
    }
}

pair<int, int> query(int L, int R) {
    int now = 0;
    while (1 << (now + 1) < (R - L + 1)) now++;
    return {max(dp[L][now].first, dp[R - (1 << now) + 1][now].first), min(dp[L][now].second, dp[R - (1 << now) + 1][now].second)};
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) scanf("%d", a + i);
        init();
        int L = 1;
        LL ans = 0;
        REPP(i, 1, n) {
            pair<int, int> tmp = query(L, i);
            int x = a[i];
            while (L < i && (tmp.first >= x + m || tmp.second <= x - m)) {
                tmp = query(++L, i);
            }
            ans += i - L + 1;
        }
        printf("%lld\n", ans);
    }


    return 0;
}

