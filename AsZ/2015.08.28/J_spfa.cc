#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#define PII pair<int, int>

using namespace std;

const int N = 1005;
const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, k;

struct MinCostFlow{
    int pre[N], dp[N];
    int fi[N], ne[M << 2], en[M << 2], cap[M << 2], cost[M << 2], edge;
    bool vis[N];
    int source, sink;

    void init() {
        source = 0, sink = 2 * n + m + 1, edge = 1;
        REPP(i, source, sink) fi[i] = vis[i] = 0;
        REPP(i, 1, n) {
            add(i, i + n, 1, 0), add(i + n, sink, 1, 0);
        }
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
        return dp[sink] != INF;
    }
    
    pair<int, int> mincost() {
        int cost = 0, flow = 0;
        while (spfa()) {
            int tmp = INF;
            for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
                tmp = min(tmp, cap[go]);
            }
            for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
                cap[go] -= tmp;
                cap[go ^ 1] += tmp;
            }
            cost += tmp * dp[sink];
            flow += tmp;
        }
        return make_pair(cost, flow);
    }
}flow;

int mp[N][N], mark[N];
int vis[N], now;

void dfs(int x) {
    //cout << x << endl;
    vis[x] = now;
    REPP(i, 1, n) if (mp[x][i] && vis[i] != now) {
        dfs(i);
    }
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
    clock_t st = clock(), ed;
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        REPP(i, 1, n) REPP(j, 1, n) mp[i][j] = 0;
        flow.init();
        int id = 2 * n;
        while (m--) {
            now++;
            int type, x, y;
            scanf("%d", &type);
            if (type == 1) {
                id++;
                scanf("%d", &x);
                dfs(x);
                flow.add(flow.source, id, k, 0);
                mark[id] = flow.edge;
                REPP(i, 1, n) if (vis[i] == now) {
                    flow.add(id, i, k, m);
                }
            }
            else if (type == 2) {
                scanf("%d%d", &x, &y);
                mp[x][y] = mp[y][x] = 1;
            }
            else {
                int cnt;
                scanf("%d", &cnt);
                REP(i, cnt) {
                    scanf("%d%d", &x, &y);
                    mp[x][y] = mp[y][x] = 0;
                }
            }
        }
        pair<int, int> ans = flow.mincost();
        printf("%d\n", ans.second);
        REPP(i, 2 * n + 1, id) {
            printf("%d%c", flow.cap[mark[i]], " \n"[i == id]);
        }
    }
#ifdef HOME
    ed = clock();
    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
