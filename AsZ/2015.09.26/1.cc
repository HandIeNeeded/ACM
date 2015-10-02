#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int cnt[N], val[N], ans[N];
int p[N], vis[N], mobius[N] = {0, 1}, tot;
vector<int> fac[N], use[N], edge[N];

void go(const vector<int> &a, vector<int> &b, int now, int dep = 0) {
    if (1u * dep == a.size()) {
        b.push_back(now);
        return ;
    }
    go(a, b, now, dep + 1);
    go(a, b, now * a[dep], dep + 1);
}

void prime() {
    use[1].push_back(1);
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, mobius[i] = -1, fac[i].push_back(i);
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            fac[i * p[j]] = fac[i];
            mobius[i * p[j]] = -mobius[i];
            if (i % p[j] == 0) {
                mobius[i * p[j]] = 0;
                break;
            }
            else {
                fac[i * p[j]].push_back(p[j]);
            }
        }
    }
    REPP(i, 2, N - 1) {
        go(fac[i], use[i], 1, 0);
    }
}

void dfs(int x, int p = 0) {
    int v = val[x];
    vector<int> tmp(use[v].size(), 0);
    int now = 0;
    for (auto &y: use[v]) {
        tmp[now++] = cnt[y];
    }
    for (auto &y: edge[x]) {
        if (y != p) {
            dfs(y, x);
        }
    }
    for (auto &y: use[v]) {
        cnt[y]++;
    }
    now = 0;
    int &res = ans[x];
    for (auto &y: use[v]) {
        res += mobius[y] * (cnt[y] - tmp[now++]);
    }
}

int main() {
#ifdef HOME
    freopen("1.in", "r", stdin);
#endif

    prime();
    int n, ca = 1;
    while(scanf("%d", &n) > 0) {
        REP(i, N - 1) cnt[i] = 0;
        REPP(i, 1, n) edge[i].clear(), ans[i] = 0;
        REPP(i, 1, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        REPP(i, 1, n) scanf("%d", val + i);
        dfs(1);
        printf("Case #%d:", ca++);
        REPP(i, 1, n) printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}

