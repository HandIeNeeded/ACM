#include <algorithm>
#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define pb push_back
#define sz(x) (int((x).size()))

typedef vector<int> VI;
const int MX = 100005;
int n, m;
VI adj[MX];
int a[MX], b[MX];
int d[MX], low[MX], ctr;
int stk[MX], sn;
int id[MX], cn;
int r[MX], z[MX];

inline void chkmax(int& x, int y) {
    if (x < y) x = y;
}

inline void chkmin(int& x, int y) {
    if (y < x) x = y;
}

void DFS(int u, int p) {
    int i, v, w;
    
    low[u] = d[u] = ++ctr;
    stk[++sn] = u;
    for (i = sz(adj[u]) - 1; i >= 0; i--) {
        v = adj[u][i];
        if (v == p) continue;
        if (!d[v]) {
            DFS(v, u);
            chkmin(low[u], low[v]);
            if (low[v] > d[u]) {
                cn++;
                do {
                    w = stk[sn--];
                    id[w] = cn;
                }
                while (w != v);
            }
        }
        else chkmin(low[u], d[v]);
    }
}

void BCC_bridge() {
    int u, i;
    
    fill_n(d, n, 0);
    ctr = cn = 0;
    int cnt = 0;
    for (u = 0; u < n; u++) {
        if (d[u]) continue;
        cnt++;
        sn = 0;
        DFS(u, -1);
        cn++;
        for (i = 1; i <= sn; i++) id[stk[i]] = cn;
    }
}

void DFS1(int u, int p) {
    int i, v;
    
    d[u] = ++ctr;
    z[u] = r[u];
    for (i = sz(adj[u]) - 1; i >= 0; i--) {
        v = adj[u][i];
        if (v == p) continue;
        DFS1(v, u);
        chkmax(z[u], z[v]);
    }
}

int main() {
    int tc, u, v, k;
    
    for (scanf("%d", &tc); tc--; ) {
        scanf("%d%d", &n, &m);
        for (u = 1; u <= n; u++) adj[u].clear();
        for (k = 0; k < m; k++) {
            scanf("%d%d", &u, &v);
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
            a[k] = u, b[k] = v;
        }
        
        BCC_bridge();
        fill_n(r + 1, cn, 0);
        for (u = 0; u < n; u++) chkmax(r[id[u]], u);
        for (u = 1; u <= cn; u++) adj[u].clear();
        for (k = 0; k < m; k++) {
            u = id[a[k]], v = id[b[k]];
            if (u == v) continue;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for (u = 1; u <= cn; u++) {
            if (r[u] == n - 1) break;
        }
        ctr = 0;
        DFS1(u, 0);
        for (k = 0; k < m; k++) {
            u = id[a[k]], v = id[b[k]];
            if (u == v) {
                puts("0 0");
                continue;
            }
            if (d[u] > d[v]) swap(u, v);
            printf("%d %d\n", z[v] + 1, z[v] + 2);
        }
    }
    return 0;
}
