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

struct MCMF{
    struct Edge{
        int next, tail, cap, cost;
    }edge[M << 3];
    int head[N], cnt, pre[N], dp[N], vis[N];
    int source, sink;

    void init() {
        source = 0, sink = 2 * n + m + 1, cnt = 1;
        REPP(i, source, sink) head[i] = vis[i] = 0;
        REPP(i, 1, n) {
            add(i, i + n, 1, 0);
            add(i + n, sink, 1, 0);
        }
    }

    void _add(int x, int y, int z, int w) {
        edge[++cnt].next = head[x], edge[cnt].tail = y;
        edge[cnt].cap = z, edge[cnt].cost = w, head[x] = cnt;
    }

    void add(int x, int y, int z, int w) {
        _add(x, y, z, w);
        _add(y, x, 0, -w);
    }

    bool dijkstra() {
        REPP(i, source, sink) dp[i] = INF, vis[i] = 0;
        priority_queue<PII, vector<PII>, greater<PII> > q;
        q.push({0, source}), dp[source] = pre[source] = 0;

        while (q.size()) {
            int x = q.top().second; q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (int go = head[x]; go; go = edge[go].next) if (edge[go].cap > 0) {
                int y = edge[go].tail;
                if (dp[y] > dp[x] + edge[go].cost) {
                    dp[y] = dp[x] + edge[go].cost;
                    pre[y] = go;
                    q.push({dp[y], y});
                }
            }
        }
        return dp[sink] != INF;
    }

    pair<int, int> minCost() {
        int cost = 0, flow = 0;
        while (dijkstra()) {
            int tmp = INF;
            for (int go = pre[sink]; go; go = pre[edge[go ^ 1].tail]) {
                tmp = min(tmp, edge[go].cap);
            }
            for (int go = pre[sink]; go; go = pre[edge[go ^ 1].tail]) {
                edge[go].cap -= tmp;
                edge[go ^ 1].cap += tmp;
            }
            cost += tmp * dp[sink];
            flow += tmp;
        }
        return {cost, flow};
    }
}flow;

int mp[N][N], mark[N];
int vis[N], now;

void dfs(int x) {
    vis[x] = now;
    REPP(i, 1, n) if (mp[x][i] && vis[i] != now) {
        dfs(i);
    }
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
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
                mark[id] = flow.cnt;
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
        pair<int, int> ans = flow.minCost();
        printf("%d\n", ans.second);
        REPP(i, 2 * n + 1, id) {
            printf("%d%c", flow.edge[mark[i]].cap, " \n"[i == id]);
        }
    }
    return 0;
}
