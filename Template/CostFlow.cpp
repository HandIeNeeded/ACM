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
            //if (dp[sink] >= 0) break; 最小费用流(不要求最大流)
            int tmp = inf;
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
        return {cost, flow};
    }
}flow;

