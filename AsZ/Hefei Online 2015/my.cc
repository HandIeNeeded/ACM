#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 1e6 + 5;

int a[2][N], cnt[2][N], tmp[N], g[2][N], vis[N];
int C, n;

bool cmp(int i, int j) {
    return a[0][i] < a[0][j];
}

bool cmp1(int i, int j) {
    return a[1][i] < a[1][j];
}

int solve(int p, int q) {
    REPP(i, 1, n) tmp[i] = i;
    if (p == 0) {
        sort(tmp + 1, tmp + n + 1, cmp);
    }
    else {
        sort(tmp + 1, tmp + n + 1, cmp1);
    }
    int ans = 0;
    REPP(i, 1, n) {
        int j = i;
        vector<int> use;
        int now = a[p][tmp[i]] + 1;
        while (j <= n && a[p][tmp[j]] == a[p][tmp[i]]) {
            if (vis[a[q][tmp[j]]] != now) {
                g[q][a[q][tmp[j]]] = 0;
                use.push_back(a[q][tmp[j]]);
            }
            vis[a[q][tmp[j]]] = now;
            g[q][a[q][tmp[j]]]++;
            j++;
        }
        if (use.size() == 1u && g[q][use[0]] == cnt[q][use[0]]) C++;
        else {
            int bad = 0;
            for (auto &u: use) {
                if (g[q][u] != cnt[q][u]) {
                    bad = 1;
                    break;
                }
            }
            if (!bad) ans++;
        }
        i = j - 1;
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> num;
        REPP(i, 1, n) {
            scanf("%d%d", &a[0][i], &a[1][i]);
            num.push_back(a[0][i]);
            num.push_back(a[1][i]);
        }
        sort(ALL(num)), num.resize(unique(ALL(num)) - num.begin());
        REP(j, 2) REP(i, num.size()) cnt[j][i] = g[j][i] = 0;
        REPP(i, 1, n) {
            REP(j, 2) {
                a[j][i] = lower_bound(ALL(num), a[j][i]) - num.begin();
                cnt[j][a[j][i]]++;
            }
        }
        C = 0;
        REP(i, num.size()) vis[i] = 0;
        int A = solve(0, 1);
        REP(i, num.size()) vis[i] = 0;
        int B = solve(1, 0);
        printf("Case #%d: %d %d %d\n", ca++, A, B, C / 2);
    }
    return 0;
}
