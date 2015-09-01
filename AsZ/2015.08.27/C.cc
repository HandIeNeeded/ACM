#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

vector<int> ans[15];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif
    int n, m;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        LL sum = 1LL * (n + 1) * n / 2 / m;
        if (sum < n || m > n || 1LL * n * (n + 1) / 2 % m) {
            puts("NO");
            continue;
        }
        REP(i, m) ans[i].clear();
        while (n > 40) {
            for (int i = 0, j = n; i < m; i++, j--) {
                ans[i].push_back(j);
            }
            for (int i = m - 1, j = n - m; i >= 0; i--, j--) {
                ans[i].push_back(j);
            }
            n -= 2 * m;
        }
        set<int> s;
        REP(i, n) s.insert(i + 1);
        sum = n * (n + 1) / 2 / m;
        REP(i, m) {
            int now = sum;
            while (now) {
                auto it = s.lower_bound(now);
                if (it == s.end()) {
                    it--;
                }
                ans[i].push_back(*it);
                now -= *it;
                s.erase(it);
            }
        }
        puts("Yes");
        REP(i, m) {
            printf("%lu", ans[i].size());
            REP(j, ans[i].size()) {
                printf(" %d", ans[i][j]);
            }
            puts("");
        }
    }

    return 0;
}
