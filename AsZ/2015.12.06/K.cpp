#include <bits/stdc++.h>
#define MAXN 112345

using namespace std;

struct edge{
    int u, v;
} ed[MAXN + 100];
vector <int> edIn[MAXN], edOut[MAXN];

typedef int arrayN[MAXN];

arrayN f, cnt, vis, nxt, visCheck, visIn, visOut;
int debug = 0;
int flag = -1, n, m;
vector <int> dfsNode;
vector <int> finalNode;
vector <int> goodEd, dfsEd;

int getfa(int x) {
    return (x == f[x]) ? f[x] : (f[x] = getfa(f[x]));
}

void link(int u, int v) {
    int fu = getfa(u);
    int fv = getfa(v);
    if (fu == fv) {
        if (cnt[fu] == n) {
            for (int i = 1; i <= n; ++i)
                if (!visIn[i] || !visOut[i]) {
                    flag = 0;
                    return;
                }
            flag = 1;
            return ;
        }
        flag = 0;
        return ;
    }
    f[fu] = fv;
    cnt[fv] += cnt[fu];
}

int d[MAXN];
int tot;

int check() {
    int sta = 0;
    int expCnt = finalNode.size() - 1;
    for (int i = 0; i < dfsEd.size(); ++i) {
        int lab = dfsEd[i];
        int u = ed[lab].u;
        int v = ed[lab].v;
        int fu = getfa(u);
        int fv = getfa(v);
        sta = fu;
        nxt[fu] = fv;
    }
    for (int p = nxt[sta]; p != sta; p = nxt[p]) {
        expCnt--;
    }
    return expCnt == 0;
}

void prtNoAns() {
    printf("There is no route, Karl!\n");
}

void handleNxt(int lab) {
        int u = ed[lab].u;
        int v = ed[lab].v;
        nxt[u] = v;
}

void prtCrtAns() {
    /*for (int i = 0; i < goodEd.size(); ++i) {
        handleNxt(goodEd[i]);
    }
    for (int i = 0; i < dfsEd.size(); ++i) {
        handleNxt(dfsEd[i]);
    }
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", p);
        p = nxt[p];
    }
    printf("1\n"); */
    printf("Yes\n");
}

void dfs(int dep) {
    if (dep == tot) {
        flag = check();
        if (flag == 1) {
            prtCrtAns();
        }
        return ;
    }
    int u = dfsNode[dep];
    for (int i = 0; i < edOut[u].size(); ++i) {
        int lab = edOut[u][i];
        int v = ed[lab].v;
        if (visIn[v]) continue;
        int fu = getfa(u);
        int fv = getfa(v);
        if (!vis[fv]) {
            vis[fv] = 1;
            dfsEd.push_back(lab);
            dfs(dep + 1);
            if (flag == 1) return ;
            vis[fv] = 0;
            dfsEd.pop_back();
        }
    }
}

int main() {
#ifndef HOME
    freopen("king.out", "w", stdout);
#endif
    freopen("king.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ed[i].u = u;
        ed[i].v = v;
        if (u == v) {
            --i;
            --m;
            continue;
        }
        edOut[u].push_back(i);
    }
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (edOut[i].size() == 1) {
            int edLab = edOut[i][0];
            if (visIn[ed[edLab].v] || visOut[i]) {
                prtNoAns();
                return 0;
            }
            visIn[ed[edLab].v] = 1;
            visOut[i] = 1;
            link(i, ed[edLab].v);
            goodEd.push_back(edLab);
            if (flag == 0) {
                prtNoAns();
                return 0;
            }
            if (flag == 1) {
                prtCrtAns();
                return 0;
            }

        } else {
            dfsNode.push_back(i);
        }
    }

    tot = dfsNode.size();
    for (int i = 1; i <= n; ++i)
        if (f[i] == i) {
            finalNode.push_back(i);
        }

    if (debug) {
        for (int i = 1; i <= n; ++i)
            printf("%d f[%d] = %d\n", edOut[i].size(), i, getfa(f[i]));
        for (int i = 0; i < dfsNode.size(); ++i) {
            printf("%d:\n", dfsNode[i]);
            int u = dfsNode[i];
            for (int j = 0; j < edOut[u].size(); ++j)
                printf("%d ", ed[edOut[u][j]].v);
            printf("\n");
        }
    }

    dfs(0);
    if (flag != 1) {
        prtNoAns();
    }
    return 0;
}
