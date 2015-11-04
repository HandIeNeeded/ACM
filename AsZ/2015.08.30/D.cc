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

struct MinCostFlow{
    int pre[N], dp[N], vis[N], source, sink;
    int fi[N], ne[M << 1], en[M << 1], cap[M << 1], cost[M << 1], edge;

    void init(int S, int T) {
        source = S, sink = T;
        MST(fi, 0), edge = 1;
    }

    void _add(int x, int y, int z, int w) {
        ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z, cost[edge] = w;
    }

    void add(int x, int y, int z, int w) {
        _add(x, y, z, w);
        _add(y, x, 0, -w);
    }

    bool spfa() {
        MST(dp, 0x3f);
        queue<int> q;
        q.push(source), vis[source] = 1, dp[source] = pre[source] = 0;

        while (q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
                int y = en[go];
                if (dp[y] > dp[x] + cost[go]) {
                    dp[y] = dp[x] + cost[go];
                    pre[y] = go;
                    if (!vis[y]) {
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }
            vis[x] = 0;
        }
        return dp[sink] != inf;
    }

    pair<int, int> minCost() {
        int cost = 0, flow = 0;
        while (spfa()) {
            if (dp[sink] >= 0) break;
            for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
                cap[go]--, cap[go ^ 1]++;
            }
            cost += dp[sink];
            flow++;
        }
        return {cost, flow};
    }
}flow;

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        flow.init(0, n + 1);
        REP(j, 2) REPP(i, 1, 12) id[j][i].clear();
        int tot = 0;
        REPP(i, 1, n) {
            scanf("%d%d%d", type + i, level + i, atk + i);
            id[type[i]][level[i]].push_back(i);
            if (type[i]) flow.add(0, i, 1, 0);
            else flow.add(i, n + 1, 1, 0);
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
            flow.add(i, j, inf, -mp[i][j]);
        }
        printf("%d\n", tot - flow.minCost().first);
    }
    return 0;
}
