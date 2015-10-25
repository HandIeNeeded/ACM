#include <bits/stdc++.h>
#define MAXN 101234

using namespace std;
typedef int arrayN[MAXN];

arrayN e, nxt, fir, f, vis, imp;
int num;

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

vector < vector <int> > ans;

void addPath(int u, int v, int rt) {
    vector <int> vecU, vecV;
    for (; u != rt; u = f[u]) vecU.push_back(u);
    for (; v != rt; v = f[v]) vecV.push_back(v);
    vecU.push_back(rt);
    for (int i = vecV.size() - 1; i >= 0; --i)
        vecU.push_back(vecV[i]);
    ans.push_back(vecU);
}

int dfs(int x, int fa) {
    vis[x] = 1;
    f[x] = fa;
    int le = 0;
    for (int p = fir[x]; p; p = nxt[p]) {
        int q = e[p];
        if (!vis[q]) {
            int tmp = dfs(q, x);
            if (tmp) {
                if (le) {
                    addPath(le, tmp, x);
                    le = 0;
                } else le = tmp;
            }
        }
    }
    if (imp[x]) {
        if (le) {
            addPath(le, x, x);
            le = 0;
        } else le = x;
    }
    return le;
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        link(u, v);
        link(v, u);
    }
    for (int i = 1; i <= k; ++i) {
        int x;
        scanf("%d", &x);
        imp[x] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            dfs(i, 0);
        }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i].size() - 1);
        for (int j = 0; j < ans[i].size(); ++j) {
            printf("%d%c", ans[i][j], " \n"[j == ans[i].size() - 1]);
        }
    }
    return 0;
}
