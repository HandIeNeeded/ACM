#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int inf = 1e9;

template<int N, int M, typename T>
struct MF{
    int fi[N], en[M << 1], ne[M << 1], edge;
    T cap[M << 1];
    int cur[N], lvl[N], source, sink;

    void init(int S, int R) {
        source = S, sink = R;
        memset(fi, 0, sizeof(fi)), edge = 1;
    }

    void _add(int x, int y, int z) {
        ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z;
    }

    void add(int x, int y, int z) {
        _add(x, y, z);
        _add(y, x, 0);
    }

    bool bfs() {
        memset(lvl, -1, sizeof(lvl));
        queue<int> q;
        lvl[source] = 1, q.push(source);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
                int y = en[go];
                if (lvl[y] < 0) {
                    lvl[y] = lvl[x] + 1;
                    q.push(y);
                }
            }
        }
        return lvl[sink] != inf;
    }

    T dfs(int x, T flow) {
        if (x == sink || flow == (T) 0) return flow;
        T tmp = 0, ans = 0;
        for (int &go = cur[x]; go; go = ne[go]) {
            int y = en[go];
            if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
                ans += tmp, flow -= tmp;
                cap[go] -= tmp, cap[go ^ 1] += tmp;
                if (flow == 0) return ans;
            }
        }
        return ans;
    }

    T dinic() {
        T ans = 0;
        while (bfs()) {
            cout << "hehe" << endl;
            memcpy(cur, fi, sizeof(fi));
            ans += dfs(source, inf);
        }
        return ans;
    }
};
MF<1005, 20005, int> flow;

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, x;
        scanf("%d%d%d", &n, &m, &x);
        flow.init(0, x + n);
        REPP(i, 1, m) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            flow.add(a, b, c);
        }
        REPP(i, 1, n) {
            int c;
            scanf("%d", &c);
            flow.add(0, i, c);
        }
        REPP(i, 1, n) {
            int c;
            scanf("%d", &c);
            flow.add(i, i + n, c);
        }
        REPP(i, 1, n) if (i != x) {
            flow.add(i + n, x + n, inf);
        }
        printf("%d\n", flow.dinic());
    }
    return 0;
}


