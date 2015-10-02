#include <bits/stdc++.h>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))

using namespace std;

typedef tuple<int, int, int> chain;
const int N = 1e5 + 5;
const int LOG = 17;
int dep[N], top[N], pre[N], size[N], pos[N], son[N];
int parent[N][LOG], dp[N], s[N];
vector<int> edge[N];
vector<chain> val[N];
int n, m, now;

void update(int x, int d) {
    while (x <= n) {
        s[x] += d;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += s[x];
        x -= LB(x);
    }
    return ans;
}

void dfs(int x, int p = 0) {
    dep[x] = dep[p] + 1, parent[x][0] = p;
    REPP(i, 1, LOG - 1) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    son[x] = 0, size[x] = 1, pre[x] = p;
    for (auto &y: edge[x]) {
        if (y != p) {
            dfs(y, x);
            size[x] += size[y];
            if (size[y] > size[son[x]]) {
                son[x] = y;
            }
        }
    }
}

void divide(int x, int tp) {
    pos[x] = ++now, top[x] = tp;
    if (son[x]) divide(son[x], tp);
    for (auto &y: edge[x]) {
        if (y != pre[x] && y != son[x]) {
            divide(y, y);
        }
    }
}

int goStep(int x, int step) {
    REP(i, LOG) if (step & (1 << i)) {
        x = parent[x][i];
    }
    return x;
}

int getLca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    x = goStep(x, dep[x] - dep[y]);
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int query(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(pos[x]) - query(pos[top[x]] - 1);
        x = pre[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans += query(pos[x]) - query(pos[y] - 1);
    return ans;
}

void toMax(int &x, int y) {
    if (x < y) x = y;
}

void go(int x, int p = 0) {
    int sum = 0;
    for (auto &y: edge[x]) {
        if (y != p) {
            go(y, x);
            sum += dp[y];
        }
    }
    int &ans = dp[x];
    ans = sum;
    REP(i, val[x].size()) {
        int a, b, c;
        tie(a, b, c) = val[x][i];
        toMax(ans, c + sum - query(a, b));
    }
    update(pos[x], ans - sum);
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        now = 0;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) val[i].clear(), edge[i].clear(), s[i] = 0;
        REPP(i, 1, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        dfs(1), divide(1, 1);
        REPP(i, 1, m) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            int p = getLca(x, y);
            val[p].push_back(make_tuple(x, y, z));
        }
        go(1);
        printf("%d\n", dp[1]);
    }
    return 0;
}
