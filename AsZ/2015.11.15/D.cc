#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int inf = 1e9;

template<int N, int M, typename Type>
struct MaxFlow{
    int edge, source, sink;
    int lvl[N], cur[N];
    int fi[N], ne[M << 1], en[M << 1];
    Type cap[M << 1];

    void init(int S, int T) {
        source = S, sink = T;
        edge = 1, MST(fi, 0);
    }

    void _add(int x, int y, Type z) {
        ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
    }

    void add(int x, int y, Type z) {
        _add(x, y, z);
        _add(y, x, 0);
    }

    bool bfs() {
        queue<int> q;
        MST(lvl, 0);
        q.push(source), lvl[source] = 1;
        while(q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
                int y = en[go];
                lvl[y] = lvl[x] + 1;
                q.push(y);
            }
        }
        return lvl[sink];
    }

    Type dfs(Type x, Type flow) {
        if (x == sink || flow == 0) {
            return flow;
        }
        Type ans = 0, tmp = 0;
        for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
            int y = en[go];
            if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, (Type) cap[go]))) > 0) {
                ans += tmp, flow -= tmp;
                cap[go] -= tmp, cap[go ^ 1] += tmp;
                if (flow == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }

    Type dinic() {
        Type ans = 0;
        while (bfs()) {
            memcpy(cur, fi, sizeof(fi));
            ans += dfs(source, inf);
        }	
        return ans;
    }
};
MaxFlow<1005, 100005, int> flow;

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
            flow.add(a, b + n, c);
            //flow.add(a + n, b, c);
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
        printf("%d\n", flow.dinic());
    }
    return 0;
}


