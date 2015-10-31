#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 1e5 + 5;

int p[N], vis[N], num;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[num++] = i;
        for (int j = 0; j < num && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int n, m;
vector<int> need, factor;
int fac[20], cnt[20], tot;

LL get(int x) {
    int k = m / x;
    return 1LL * x * (k - 1) * k / 2;
}

unordered_map<int, LL> mp;
LL calc(int x) {
    if (mp.count(x)) return mp[x];
    LL ans = 0;
    REP(i, need.size()) {
        if (x % need[i] == 0) {
            ans = get(x);
            break;
        }
    }
    if (ans == 0) {
        return mp[x] = 0;
    }
    int pos = upper_bound(ALL(factor), x) - factor.begin();
    for (int i = pos; i < int(factor.size()); i++) if (factor[i] % x == 0) {
        ans -= calc(factor[i]);
    }
    return mp[x] = ans;
}

void dfs(int dep, int now, int odd) {
    if (dep == tot) {
        factor.push_back(now);
    }
    else {
        REP(i, cnt[dep] + 1) {
            dfs(dep + 1, now, odd ^ 1);
            now *= fac[dep];
        }
    }
}

int main() {
#ifdef HOME
    freopen("1006.in", "r", stdin);
#endif

    prime();
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        vector<int> d;
        REPP(i, 1, n) {
            int x;
            scanf("%d", &x);
            d.push_back(__gcd(x, m));
        }
        sort(ALL(d));
        d.resize(unique(ALL(d)) - d.begin());
        need.clear();
        for (int i = d.size() - 1; i >= 0; i--) {
            int find = 0;
            for (int j = 0; j < i; j++) {
                if (d[i] % d[j] == 0) {
                    find = 1;
                    break;
                }
            }
            if (!find) need.push_back(d[i]);
        }
        reverse(ALL(need));
        int tmp = m;
        tot = 0;
        for (int i = 0; i < num && p[i] * p[i] <= m; i++) {
            if (m % p[i] == 0) {
                fac[tot] = p[i];
                cnt[tot] = 0;
                while (m % p[i] == 0) m /= p[i], cnt[tot]++;
                tot++;
            }
        }
        if (m > 1) cnt[tot] = 1, fac[tot] = m, tot++;
        m = tmp;
        LL ans = 0;
        factor.clear();
        dfs(0, 1, 0);
        sort(ALL(factor));
        mp.clear();
        printf("Case #%d: ", ca++);
        for (int i = factor.size() - 1; i >= 0; i--) {
            //cout << factor[i] << ' ' << calc(factor[i]) << endl;
            ans += calc(factor[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}


