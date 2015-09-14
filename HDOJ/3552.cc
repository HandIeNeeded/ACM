#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

pair<int, int> p[N];
int prefix[N], suffix[N], L[N], R[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        assert(n > 1);
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = {x, y};
        }
        p[0] = p[n + 1] = {-1, -1};
        sort(p + 1, p + n + 1);
        REPP(i, 1, n) L[i] = p[i].first == p[i - 1].first ? L[i - 1] : i - 1;
        for (int i = n; i >= 1; i--) R[i] = p[i].first == p[i + 1].first ? R[i + 1] : i + 1;
        prefix[0] = INT_MAX, suffix[n + 1] = -1;
        REPP(i, 1, n) prefix[i] = min(prefix[i - 1], p[i].second);
        for (int i = n; i >= 1; i--) {
            suffix[i] = max(suffix[i + 1], p[i].second);
        }
        int now = 1, ans = INT_MAX;
        while (R[now] <= n) {
            ans = min(ans, p[now].first + suffix[R[now]]);
            now = R[now];
        }
        if (R[now] - now > 1) {
            ans = min(ans, prefix[now] + p[now].first);
        }
        else {
            ans = min(ans, p[now].first + prefix[L[now]]);
        }
        printf("Case %d: %d\n", ca++, ans);
    }


    return 0;
}

