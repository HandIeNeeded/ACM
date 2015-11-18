#include <bits/stdc++.h>
#define MAXM 51234
#define MAXN 512

using namespace std;

struct node {
    int u, v, w;
} ed[MAXM];

int com(node A, node B) {
    return A.w < B.w;
}

int f[MAXN], vis[MAXM], g[MAXN];
vector <int> mst;

int getfa(int x) {
    return (f[x] == x) ? f[x] : (f[x] = getfa(f[x]));
}
int getMst(int n, int m) {
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    int tot = 0;
    int tmpVal = 0;
    for (int i = 1; i <= m; ++i)
        if (!vis[i]) {
            int fu = getfa(ed[i].u);
            int fv = getfa(ed[i].v);
            if (fu != fv) {
                ++tot;
                tmpVal += ed[i].w;
                f[fu] = fv;
                mst.push_back(i);
            }
            if (tot == n - 1) return tmpVal;
        }
    return -1;
}
int main() {
#ifdef HOME
freopen("in.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
    }
    sort(ed + 1, ed + m + 1, com);
    memset(vis, 0, sizeof(vis));
    int mstVal = getMst(n, m);

    for (int i = 0; i < n - 1; ++i) {
        g[i] = mst[i];
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        vis[g[i]] = 1;
        mst.clear();
        if (getMst(n, m) != mstVal) {
            ans1++;
            ans2 += ed[g[i]].w;
        }
        vis[g[i]] = 0;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
