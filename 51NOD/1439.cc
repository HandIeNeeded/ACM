#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e5 + 5;

int p[N], vis[N] = {0, 1}, mobius[N] = {0, 1}, tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = vis[i] = i, mobius[i] = -1;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            mobius[i * p[j]] = -mobius[i];
            if (i % p[j] == 0) {
                mobius[i * p[j]] = 0;
                break;
            }
        }
    }
}

int cnt[N], a[N];
bool in[N];

vector<int> fac;

void dfs(int dep, int now, int &ans, int d) {
    if (dep == int(fac.size())) {
        ans += mobius[now] * cnt[now];
        cnt[now] += d;
    }
    else {
        dfs(dep + 1, now, ans, d);
        dfs(dep + 1, now * fac[dep], ans, d);
    }
}

int get(int x, int d) {
    fac.clear();
    int tmp = x;
    while (tmp > 1) {
        int p = vis[tmp];
        fac.push_back(p);
        while (tmp % p == 0) tmp /= p;
    }
    int ans = 0;
    dfs(0, 1, ans, d);
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    prime();
    int n, m;
    scanf("%d%d", &n, &m);
    REPP(i, 1, n) {
        scanf("%d", a + i);
    }
    LL ans = 0;
    int tot = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        if (a[x] == 1) {
            if (in[x]) ans -= tot - 1, tot--, cnt[1]--;
            else ans += tot, tot++, cnt[1]++;
            in[x] = !in[x];
            printf("%lld\n", ans);
            continue;
        }
        if (in[x]) {
            tot--;
            int num = get(a[x], -1);
            ans -= num;
        }
        else {
            tot++;
            int num = get(a[x], 1);
            ans += num;
        }
        in[x] = !in[x];
        printf("%lld\n", ans);
    }
    return 0;
}

