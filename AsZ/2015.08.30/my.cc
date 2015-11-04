#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 505;
const int M = 100005;
const int inf = 0x3f3f3f3f;

int type[N], level[N], atk[N];
int mp[N][N];
vector<int> id[2][13];

void update(int &x, int y) {
    if (x < y) x = y;
}

const int INF = 0x3f3f3f3f;
template<int N> struct CostFlow {
    int s,t,vis[N],d[N],head[N],cur[N],etot;
    struct Edge {int v,cap,cost,next;} g[555555];
    void add_edge(int u,int v,int cap,int cost) {
        g[etot].v = v; g[etot].cap = cap; g[etot].cost = cost; g[etot].next = head[u]; head[u] = etot ++;
        g[etot].v = u; g[etot].cap = 0; g[etot].cost = -cost; g[etot].next = head[v]; head[v] = etot ++;
    }
    void init() {
        memset(head,-1,sizeof(head)); etot = 0;
    }
    int aug(int u,int a) {
        if (u==t) return a;
        vis[u] = 1;
        int flow = 0,f;
        for (int &i = cur[u]; i != -1; i = g[i].next) {
            Edge &e = g[i];
            if (e.cap && !vis[e.v] && d[u]==d[e.v]+e.cost)
                if (f = aug(e.v,min(a,e.cap))) {
                    flow += f;
                    e.cap -= f;
                    g[i^1].cap += f;
                    a -= f;
                    if (a==0) break;
                }
        }
        return flow;
    }
    bool modlabel() {
        int tmp = INF;
        for (int u = 0; u < N; u ++) if (vis[u]) {
            for (int i = head[u]; i != -1; i = g[i].next) {
                Edge &e = g[i];
                if (e.cap && !vis[e.v])
                    tmp = min(tmp,d[e.v]+e.cost-d[u]);
            }
        }
        if (tmp==INF) return true;
        for (int u = 0; u < N; u ++) if (vis[u]) {
            vis[u] = 0;
            d[u] += tmp;
        }
        return false;
    }
    void mcmf(int _s,int _t,int &cost,int &flow) {
        s = _s; t = _t; cost = flow = 0; int f;
        memset(d,0,sizeof(d));
        while (true) {
            memcpy(cur,head,sizeof(head));
            while (f=aug(s,INF)) {
                flow += f;
                cost += f*d[s];
                memset(vis,0,sizeof(vis));
            }
            if (modlabel()) break;
        }
    }
};
CostFlow<505> flow;

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        flow.init();
        REP(j, 2) REPP(i, 1, 12) id[j][i].clear();
        int tot = 0;
        REPP(i, 1, n) {
            scanf("%d%d%d", type + i, level + i, atk + i);
            id[type[i]][level[i]].push_back(i);
            if (type[i]) flow.add_edge(0, i, 1, 0);
            else flow.add_edge(i, n + 1, 1, 0);
            tot += atk[i];
        }
        MST(mp, 0);
        REPP(i, 1, m) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (z == 0) {
                REPP(a, 1, x - 1) {
                    int b = x - a;
                    REP(j, id[0][a].size()) {
                        REP(k, id[1][b].size()) {
                            int p = id[0][a][j], q = id[1][b][k];
                            if (y - atk[p] - atk[q] > 0) {
                                update(mp[q][p], y - atk[p] - atk[q]);
                            }
                        }
                    }
                }
            }
            else if (z == 1) {
                int u, v;
                scanf("%d", &u);
                int b = x - level[u];
                int ty = type[u] ^ 1;
                REP(j, id[ty][b].size()) {
                    v = id[ty][b][j];
                    if (y - atk[v] - atk[u] > 0) {
                        if (ty == 1) {
                            update(mp[v][u], y - atk[v] - atk[u]);
                        }
                        else {
                            update(mp[u][v], y - atk[v] - atk[u]);
                        }
                    }
                }
            }
            else {
                int u, v;
                scanf("%d%d", &u, &v);
                if (type[v]) swap(u, v);
                if (y - atk[u] - atk[v] > 0) {
                    update(mp[u][v], y - atk[u] - atk[v]);
                }
            }
        }
        REPP(i, 1, n) REPP(j, 1, n) if (mp[i][j] > 0) {
            //cout << i << ' ' << j << ' ' << -mp[i][j] << endl;
            flow.add_edge(i, j, inf, -mp[i][j]);
        }
        int cost, f;
        flow.mcmf(0, n + 1, cost, f);
        printf("%d\n", tot - cost);
    }
    return 0;
}
