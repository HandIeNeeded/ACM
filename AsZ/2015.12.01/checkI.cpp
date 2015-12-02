#include <bits/stdc++.h>
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
pair<int, int> a[N], b[N];

int ansFinal, n, m, vis[N];

int checkCan(int i, int j) {
    return a[i].first >= b[j].second;
}

int getCost(int i, int j) {
    return a[i].second <= b[j].first;
}

void dfs(int dep, int ans) {
    if (dep == m + 1) {
        ansFinal = max(ansFinal, ans);
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i] && checkCan(i, dep)) {
            vis[i] = 1;
            dfs(dep + 1, ans - getCost(i, dep));
            vis[i] = 0;
        }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif // HOME
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        ansFinal = -1;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = make_pair(x, y);
        }
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            b[i] = make_pair(x, y);
        }
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        dfs(1, n);
        printf("Case #%d: %d\n", ca++, ansFinal);
    }
    return 0;
}
