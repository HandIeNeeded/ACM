#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int L = 17;

vector<int> edge[N], val[N];
int dis[N], parent[N][L], dep[N];

void dfs(int x, int p, int now) {
    //cout << x << endl;
    dis[x] = now, dep[x] = dep[p] + 1;
    parent[x][0] = p;
    REPP(i, 1, L - 1) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
            dfs(y, x, now + val[x][i]);
        }
    }
}

int goStep(int x, int step) {
    REP(i, L) if (step & (1 << i)) {
        x = parent[x][i];
    }
    return x;
}

int getLca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    x = goStep(x, dep[x] - dep[y]);
    if (x == y) return x;
    for (int i = L - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int get(int x, int y) {
    int z = getLca(x, y);
    return dis[x] - dis[z] + dis[y] - dis[z];
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) edge[i].clear(), val[i].clear();
        REPP(i, 1, n - 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edge[x].push_back(y), val[y].push_back(z);
            edge[y].push_back(x), val[x].push_back(z);
        }
        int tx, ty, tz;
        scanf("%d%d%d", &tx, &ty, &tz);
        dfs(1, 0, 0);
        //REPP(i, 1, n) {
        //    cout << i << ' ' << dis[i] << ' ' << dep[i] << endl;
        //}
        printf("Case #%d:\n", ca++);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int old = get(x, y);
            int now = min(get(x, tx) + get(y, ty), get(x, ty) + get(y, tx)) + tz;
            int ans = max(0, old - now);
            printf("%d\n", ans);
        }
    }


    return 0;
}


