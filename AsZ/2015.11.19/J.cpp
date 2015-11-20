#include <bits/stdc++.h>
#define MAXN 112345
#define MAXM 2123456

using namespace std;
typedef int arrayN[MAXN], arrayM[MAXM];

arrayN fir, deg, sta, a, dp, f;
arrayM e, nxt;
int num, sl, sr;

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, deg[v]++;
}

void topSort() {
    for (; sl <= sr; ) {
        int u = sta[sl++];
        for (int p = fir[u]; p; p = nxt[p]) {
            deg[e[p]]--;
            if (deg[e[p]] == 0) sta[++sr] = e[p];
        }
    }
}

int getfa(int x) {
    return (x == f[x]) ? x : (f[x] == getfa(f[x]));
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif
    int T, n, m;
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int onlyOne = 1;
        num = 0;

        for (int i = 1; i <= n; ++i) {
            fir[i] = deg[i] = 0;
            f[i] = i;
        }

        for (int i = 2; i <= n; ++i)
            if (a[i] != a[i - 1]) onlyOne = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            link(u, v);
            int fu = getfa(u);
            int fv = getfa(v);
        }

        if (onlyOne) {
            printf("0\n");
        } else {
            sl = 1, sr = 0;
            for (int i = 1; i <= n; ++i)
                if (deg[i] == 0) sta[++sr] = i;
            topSort();
            for (int i = sr; i >= 1; --i) {
                int u = sta[i];
                dp[u] = 0;
                for (int p = fir[u]; p; p = nxt[p]) {
                    int v = e[p];
                    int tmp;
                    if (a[u] != a[v]) tmp = dp[v] + 1;
                    else tmp = dp[v];
                    dp[u] = max(dp[u], tmp);
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i)
                ans = max(ans, dp[i]);
            if (ans == 0) {
                printf("1\n");
            } else {
                int co[3];
                co[1] = co[2] = 0;
                for (int i = 1; i <= n; ++i)
                    if (dp[i] == ans) co[a[i]] = 1;
                if (co[1] + co[2] == 2) ans++;
                printf("%d\n", ans);
            }


        }
    }
    return 0;
}
