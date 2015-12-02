#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int M = 10000;
const int L = 35;
int p[N], vis[N], pcnt[N], tot;
double dp[M][L], f[M][L];
//double pre[N][L], sum[N][L];

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, pcnt[tot - 1] = 1;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            pcnt[i * p[j]] = pcnt[i];
            if (i % p[j] == 0) break;
            else {
                pcnt[i * p[j]]++;
            }
        }
    }
}

vector<LL> fac, num;
vector<pair<LL, int>> factor;
set<LL> pm;

int getId(LL x, int pos) {
    return lower_bound(factor.begin(), factor.begin() + pos, make_pair(x, 0)) - factor.begin();
}

void dfs(int dep, LL now, int l) {
    if (dep == int(fac.size())) {
        factor.push_back({now, l});
    }
    else {
        REP(i, num[dep] + 1) {
            dfs(dep + 1, now, l + i);
            now *= fac[dep];
        }
    }
}

void go(LL n, int pos) { //0based
    //if (n < N) {
    //    memcpy(dp[pos], pre[n], sizeof(dp[pos]));
    //    memcpy(f[pos], sum[n], sizeof(sum[pos]));
    //    return ;
    //}
    //else {
        int L = factor[pos].second;
        //cout << n << ' ' << pos << ' ' << L << endl;
        REP(dep, L) {
            double &ans = dp[pos][dep];
            if (dep == 0) {
                if (pm.count(factor[pos].first)) ans = 1;
                else ans = 0;
                continue;
            }
            int tot = 0;
            REPP(i, 1, pos - 1) if (n % factor[i].first == 0) {
                LL x = factor[i].first;
                LL y = n / x;
                tot++;
                int j = getId(y, pos);
                assert(factor[j].first == y);
                if (dep > 1) {
                    ans += f[i][dep - 1] * f[j][dep - 1] - f[i][dep - 2] * f[j][dep - 2];
                }
                else {
                    ans += f[i][dep - 1] * f[j][dep - 1];
                }
            }
            ans /= tot;
        }
        f[pos][0] = dp[pos][0];
        REPP(i, 1, ::L) {
            f[pos][i] = f[pos][i - 1] + dp[pos][i];
        }
    //}
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        fac.clear(), num.clear(), factor.clear(), pm.clear();
        for (int i = 0; i < tot && 1LL * p[i] * p[i] <= n; i++) {
            if (n % p[i] == 0) {
                int cnt = 0;
                while (n % p[i] == 0) {
                    cnt++;
                    n /= p[i];
                }
                fac.push_back(p[i]);
                num.push_back(cnt);
                pm.insert(p[i]);
            }
        }
        if (n > 1) {
            fac.push_back(n);
            num.push_back(1);
            pm.insert(n);
        }
        dfs(0, 1, 0);
        sort(factor.begin(), factor.end());
        //for (auto &now: factor) {
        //    cout << now.first << ' ' << now.second << endl;
        //}
        //0based
        REPP(i, 1, factor.size() - 1) {
            //cout << "calc: " << i << ' ' << factor[i].first << ' ' << i << endl;
            memset(dp[i], 0, sizeof(dp[i]));
            go(factor[i].first, i);
        }
        //REPP(i, 1, factor.size() - 1) {
        //    int x = factor[i].second;
        //    REP(j, x) {
        //        cout << "(" << i << ' ' << j << ' ' << dp[i][j] << ' ' << f[i][j] << ")" << ' ';
        //    }
        //    cout << endl;
        //}
        double ans = 0;
        REPP(i, 0, factor.back().second - 1) {
            ans += dp[factor.size() - 1][i] * i;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}

