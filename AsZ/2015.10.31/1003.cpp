#include <bits/stdc++.h>
#define MAXN 41234
#define MAXM 112345

using namespace std;

typedef int arrayN[MAXN];

arrayN fir, e, nxt, deg, f, belong, isLeaf, dSum, lab;
int num, ans, n, m, base, g[MAXN * 4];

struct edge {
    int u, v;
} ed[MAXM];

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

void dfs(int x, int fa, int bel) {
    f[x] = fa;
    if (fa == 1) bel = x;
    belong[x] = bel;
    isLeaf[x] = 1;
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != fa){
            dfs(e[p], x, bel);
            isLeaf[x] = 0;
        }
}

void dfsAns(int x) {
    dSum[x] = deg[x];
    for (int p = fir[x]; p; p = nxt[p]) {
        int q = e[p];
        if (q != f[x]) {
            dfsAns(q);
            dSum[x] += dSum[q];
        }
    }
    if (x != 1 && !isLeaf[x]) {
        for (int p = fir[x]; p; p = nxt[p]) {
            int q = e[p];
            if (q != f[x]) {
                ans = min(ans, dSum[x] - dSum[q] + 2); //case 1  fedge, sonedge
                ans = min(ans, dSum[q] + 2); //case 2  sonedge sonedge
            }
        }
    }
}

int com(edge A, edge B) {
    return A.u < B.u || ((A.u == B.u) && A.v < B.v);
}

int equ(edge A, edge B) {
    return A.u == B.u && A.v == B.v;
}

vector <int> vec[MAXN];

void change(int x, int value) {
    x += base;
    g[x] = value;
    for (x >>= 1; x; x >>= 1)
        g[x] = min(g[x << 1], g[x << 1 ^ 1]);
}

const int INF = 1e9;

void solveRoot() {
    sort(ed + 1, ed + m + 1, com);
    //for (int i = 1; i <= n; ++i)
      //  cout << dSum[i] << endl;
    //solve link
    //cout << m << endl;
    for (int i = 1; i <= m; ++i) {
        int j = i;
        for (; j + 1 <= m && equ(ed[j + 1], ed[i]); ++j);
       // cout << dSum[ed[i].u] << ' ' << dSum[ed[i].v] << endl;
        ans = min(ans, dSum[ed[i].u] + dSum[ed[i].v] - 2 * (j - i + 1) + 2);
        i = j;
        vec[ed[i].u].push_back(ed[i].v);
        vec[ed[i].v].push_back(ed[i].u);
    }
    //solve no link
    memset(g, 0x3f, sizeof(g));
    vector <int> rs;
    for (int p = fir[1]; p; p = nxt[p]) {
        rs.push_back(e[p]);
        lab[e[p]] = rs.size();
    }
    int tot = rs.size();
    for (base = 1; base <= tot + 1; base <<= 1);
    for (int i = 0; i < tot; ++i)
        change(i + 1, dSum[rs[i]]);
    for (int i = 0; i < tot; ++i) {
        int u = rs[i];
        for (int j = 0; j < (int)vec[u].size(); ++j) {
            int v = vec[u][j];
            change(lab[v], INF);
        }
        change(lab[u], INF);
        ans = min(ans, dSum[u] + g[1] + 2);
        for (; !vec[u].empty(); vec[u].pop_back()) {
            int v = vec[u].back();
            change(lab[v], dSum[v]);
        }
        change(lab[u], dSum[u]);
    }
}

int main() {
#ifdef HOME
    freopen("1003.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        num = 0;
        memset(fir, 0, sizeof(fir));
        memset(deg, 0, sizeof(deg));
        memset(isLeaf, 0, sizeof(isLeaf));
        memset(f, 0, sizeof(f));
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            link(u, v);
            link(v, u);
        }
        dfs(1, 0, 1);
        m = m - n + 1;
        int tot = m;
        m = 0;
        for (int i = 1; i <= tot; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++;
            deg[v]++;
            if (belong[u] == 1 || belong[v] == 1) continue;
            ++m;
            ed[m].u = belong[u];
            ed[m].v = belong[v];
        }
     //   for (int i = 1; i <= n; ++i)
      //      cout << belong[i] << endl;
        ans = tot + 2;
        for (int i = 1; i <= n; ++i)
            if (isLeaf[i])
                ans = min(ans, deg[i] + 2);
        dfsAns(1);
        solveRoot();
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
