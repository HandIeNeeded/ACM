#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int MO = 1e9 + 7;

vector<int> edge[N], type[N];
int parent[N][18], pw[M], up[N], down[N], dep[N], n, LOG;

void dfs(int x, int p) {
    parent[x][0] = p;
    REPP(i, 1, LOG) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    dep[x] = dep[p] + 1;
    for (auto &y: edge[x]) {
        if (y != p) {
            dfs(y, x);
        }
    }
}

int goStep(int x, int step) {
    REP(i, LOG + 1) if (step & (1 << i)) {
        x = parent[x][i];
    }
    return x;
}

int getLca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    x = goStep(x, dep[x] - dep[y]);
    if (x == y) return x;
    for (int i = LOG; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

void query(int x, int y) {
    if (x == y) return ;
    int z = getLca(x, y);
    up[x]++, up[z]--;
    down[y]++, down[z]--;
}

void DFS(int x, int p) {
    for (auto &y: edge[x]) {
        if (y != p) {
            DFS(y, x);
            up[x] += up[y];
            down[x] += down[y];
        }
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int ans = 0;

void getAns(int x, int p) {
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
            if (type[x][i]) {
                if (type[x][i] == 1) {
                    add(ans, pw[up[y]] - 1);
                }
                else {
                    add(ans, pw[down[y]] - 1);
                }
            }
            getAns(y, x);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    pw[0] = 1;
    REPP(i, 1, M - 1) pw[i] = pw[i - 1], add(pw[i], pw[i]);
    scanf("%d", &n);
    LOG = 0;
    while ((1 << LOG) < n) LOG++;
    REPP(i, 1, n - 1) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edge[x].push_back(y), type[x].push_back(z);
        edge[y].push_back(x), type[y].push_back(z);
        if (z) type[y].back() = 2;
    }
    dfs(1, 0);
    int k;
    scanf("%d", &k);
    int pre = 1;
    REP(i, k) {
        int x;
        scanf("%d", &x);
        query(pre, x);
        pre = x;
    }
    DFS(1, 0);
    getAns(1, 0);
    printf("%d\n", ans);

    return 0;
}

