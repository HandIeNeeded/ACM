#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

struct Edge{
    int next, tail, id;
}edge[N << 1];

int head[N], tot;
int low[N], vis[N], bridge[N << 1], now;
int L[N], R[N], mx[N], path[N], prefix[N], suffix[N], stamp;
int n, m;

void add(int x, int y, int z) {
    edge[++tot].next = head[x], head[x] = tot;
    edge[tot].tail = y, edge[tot].id = z;
}

void dfsTree(int x, int p) {
    L[x] = ++stamp, path[stamp] = x;
    mx[x] = x, vis[x] = now, low[x] = stamp;
    for (int go = head[x]; go; go = edge[go].next) {
        int y = edge[go].tail;
        if (y != p) {
            if (vis[y] != now) {
                dfsTree(y, x);
                low[x] = min(low[x], low[y]);
                mx[x] = max(mx[x], mx[y]);
                if (low[y] > L[x]) bridge[go] = bridge[go ^ 1] = now;
            }
            else {
                low[x] = min(low[x], L[y]);
            }
        }
    }
    R[x] = stamp;
}

void init() {
    prefix[0] = suffix[n + 1] = 0;
    REPP(i, 1, n) prefix[i] = max(prefix[i - 1], path[i]);
    for (int i = n; i >= 1; i--) suffix[i] = max(suffix[i + 1], path[i]);
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        now++;
        tot = 1, stamp = 0;
        REPP(i, 1, n) head[i] = 0;
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y, i), add(y, x, i);
        }
        dfsTree(1, 0);
        init();
        for (int i = 2; i <= 2 * m; i += 2) {
            if (bridge[i] == now) {
                int a = edge[i].tail, b = edge[i ^ 1].tail;
                if (L[a] > L[b]) {
                    swap(a, b);
                }
                int ans = 0;
                if (mx[b] == n) {
                    ans = max(ans, prefix[L[b] - 1]);
                    ans = max(ans, suffix[R[b] + 1]);
                }
                else {
                    ans = mx[b];
                }
                printf("%d %d\n", ans, ans + 1);
            }
            else {
                puts("0 0");
            }
        }
    }

    return 0;
}
