#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int L = 20;

int dis[N], dep[N], parent[N][L], vis[N], order[N], now;
vector<int> edge[N], val[N];
map<int, int> mp;

void dfs(int x, int p = 0, int dep = 0) {
    dis[x] = dep, ::dep[x] = ::dep[p] + 1, order[x] = ++now;
    parent[x][0] = p;
    REPP(i, 1, L - 1) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
            dfs(y, x, dep + val[x][i]);
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

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        now = 0, mp.clear();
        REPP(i, 1, n) edge[i].clear(), val[i].clear(), vis[i] = 0;
        REPP(i, 1, n - 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            edge[x].push_back(y), val[x].push_back(z);
            edge[y].push_back(x), val[y].push_back(z);
        }
        printf("Case #%d:\n", ca++);
        dfs(1);
        int pre = 0, ans = 0, tot = 0;
        while (q--) {
            int type, x;
            scanf("%d%d", &type, &x);
            if (type == 1) {
                if (vis[x]) {
                    ans = pre;
                }
                else if (tot == 0) {
                    ans = 0;
                    vis[x] = 1;
                    mp[order[x]] = x;
                    tot++;
                }
                else {
                    vis[x] = 1;
                    int ord = order[x];
                    auto pos = mp.lower_bound(ord);
                    if (pos == mp.begin() || pos == mp.end()) {
                        int a = mp.begin()->second;
                        pos = mp.end(), pos--;
                        int b = pos->second;
                        ans = pre + dis[x] - dis[getLca(x, a)] - dis[getLca(x, b)] + dis[getLca(a, b)];
                    }
                    else {
                        int b = pos->second;
                        pos--;
                        int a = pos->second;
                        ans = pre + dis[x] - dis[getLca(x, a)] - dis[getLca(x, b)] + dis[getLca(a, b)];
                    }
                    //add it to map
                    mp[ord] = x;
                    tot++;
                }
            }
            else {
                if (vis[x] == 0) {
                    ans = pre;
                }
                else if (tot == 1) {
                    ans = 0;
                    vis[x] = 0;
                    mp.erase(order[x]);
                    tot--;
                }
                else {
                    vis[x] = 0;
                    int ord = order[x];
                    //erase it from map
                    mp.erase(ord);
                    auto pos = mp.lower_bound(ord);
                    if (pos == mp.begin() || pos == mp.end()) {
                        int a = mp.begin()->second;
                        pos = mp.end(), pos--;
                        int b = pos->second;
                        ans = pre - (dis[x] - dis[getLca(x, a)] - dis[getLca(x, b)] + dis[getLca(a, b)]);
                    }
                    else {
                        int b = pos->second;
                        pos--;
                        int a = pos->second;
                        ans = pre - (dis[x] - dis[getLca(x, a)] - dis[getLca(x, b)] + dis[getLca(a, b)]);
                    }
                    tot--;
                }
            }
            printf("%d\n", ans);
            pre = ans;
        }
    }
    return 0;
}


