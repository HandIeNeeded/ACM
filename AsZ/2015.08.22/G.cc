#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int M = 6e4 + 5;
const int INF = 0x3f3f3f3f;

int n, m;

struct Dinic{
    int fi[N], cap[M << 2], en[M << 2], ne[M << 2], edge;
    int lvl[N], cur[N], source, sink;

    void init() {
        edge = 1;
        source = 1, sink = n;
        REPP(i, 1, n) fi[i] = 0;
    }

    void _add(int x, int y, int z) {
        ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z;
    }

    void add(int x, int y, int z) {
        _add(x, y, z);
        _add(y, x, 0);
    }

    bool bfs() {
        queue<int> q;
        REPP(i, 1, n) lvl[i] = 0;
        lvl[source] = 1, q.push(source);
        while(q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
                int y = en[go];
                if (lvl[y]) continue;
                lvl[y] = lvl[x] + 1;
                q.push(y);
            }
        }
        return lvl[sink];
    }

    int dfs(int x, int flow = INF) {
        if (x == sink || flow == 0) return flow;
        int ans = 0, tmp;
        for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
            int y = en[go];
            if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
                cap[go] -= tmp;
                cap[go ^ 1] += tmp;
                ans += tmp;
                flow -= tmp;
                if (flow == 0) return ans;
            }
        }
        return ans;
    }

    int dinic() {
        int ans = 0;
        while (bfs()) {
            REPP(i, 1, n) cur[i] = fi[i];
            ans += dfs(source);
        }
        return ans;
    }
}flow;

vector<int> edge[N], val[N];
vector<int> e[N];

int dis[2][N];
bool vis[N];
#define PII pair<int, int>

void dijkstra(int start, int id) {
    priority_queue<PII, vector<PII>, greater<PII> > q;
    REPP(i, 1, n) dis[id][i] = INF, vis[i] = 0;
    dis[id][start] = 0;
    q.push(make_pair(0, start));
    while (q.size()) {
        int x;
        x = q.top().second, q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            if (dis[id][y] > dis[id][x] + val[x][i]) {
                dis[id][y] = dis[id][x] + val[x][i];
                q.push(make_pair(dis[id][y], y));
            }
        }
    }
}

int a[M], b[M], c[M];

void getGraph() {
    flow.init();
    REPP(i, 1, m) {
        if (dis[0][a[i]] + c[i] + dis[1][b[i]] == dis[0][n] || dis[0][b[i]] + c[i] + dis[1][a[i]] == dis[0][n]) {
            //cout << "added: " << i << endl;
            flow.add(a[i], b[i], 1);
            flow.add(b[i], a[i], 1);
            e[a[i]].push_back(b[i]);
            e[b[i]].push_back(a[i]);
        }
    }
}

int bfs() {
    queue<int> q;
    REPP(i, 1, n) dis[0][i] = INF, vis[i] = 0;
    dis[0][1] = 0, vis[1] = 1, q.push(1);
    while (q.size()) {
        int x = q.front(); q.pop();
        REP(i, e[x].size()) {
            int y = e[x][i];
            if (vis[y]) continue;
            dis[0][y] = dis[0][x] + 1, vis[y] = 1;
            q.push(y);
        }
    }
    return dis[0][n];
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif
    while (scanf("%d%d", &n, &m) > 0) {
        if (n == 1) {
            puts("0 0");
            continue;
        }
        REPP(i, 1, n) edge[i].clear(), val[i].clear();
        REPP(i, 1, n) e[i].clear();
        //cout << n << ' ' << m << endl;
        REPP(i, 1, m) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[i] = x, b[i] = y, c[i] = z;
            edge[x].push_back(y), val[x].push_back(z);
            edge[y].push_back(x), val[y].push_back(z);
        }
        dijkstra(1, 0), dijkstra(n, 1);
        if (dis[0][n] == INF) {
            printf("%d %d\n", 0, 0);
            continue;
        }
        //REPP(i, 1, n) {
        //    cout << i << ' ' << dis[0][i] << ' ' << dis[1][i] << endl;
        //}
        getGraph();
        int ans1 = bfs();
        int ans2 = flow.dinic();
        //cout << "hehe" << endl;
        //cout << "ans1 ans2: " << ans1 << ' ' << ans2 << endl;
        printf("%d %d\n", ans2, m - ans1);
    }
    return 0;
}

