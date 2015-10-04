#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int L = 17;
vector<pair<int, int> > edge[N];
int dep[N], f1[N], f2[N]; // down up
int parent[N][L];

void dfs(int x, int p, int dir = 0) {
    if (dir == 0) {
        f1[x] = f2[x] = 0;
    }
    else {
        if (dir == 1) {
            f1[x] = f1[p] + 1, f2[x] = 0;
        }
        else {
            f1[x] = 0, f2[x] = f2[p] + 1;
        }
    }
    dep[x] = dep[p] + 1;
    parent[x][0] = p;
    REPP(i, 1, L - 1) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    REP(i, edge[x].size()) {
        int y, d;
        y = edge[x][i].first, d = edge[x][i].second;
        //tie(y, d) = edge[x][i];
        if (y != p) dfs(y, x, d);
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

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d", &n) > 0) {
        REPP(i, 1, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back({y, 1});
            edge[y].push_back({x, -1});
        }
        dfs(1, 0);
        //REPP(i, 1, n) {
        //    cout << i << ' ' << dep[i] << ' ' << f1[i] << ' ' << f2[i] << endl;
        //}
        scanf("%d", &m);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int z = getLca(x, y);
            //cout << "Lca of " << x << ' ' << y << " is: " << z << endl;
            if (f2[x] >= dep[x] - dep[z] && f1[y] >= dep[y] - dep[z]) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }

    return 0;
}


