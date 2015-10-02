#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N];
int vis[N], now, n, m, a, b;
LL dis[N];

LL bfs() {
    now++;
    queue<int> q;
    q.push(1), dis[1] = 0, vis[1] = now;
    dis[n] = LLONG_MAX;
    while (q.size()) {
        int x = q.front(); q.pop();
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            if (vis[y] != now) {
                dis[y] = dis[x] + 1;
                q.push(y);
                vis[y] = now;
            }
        }
    }
    if (dis[n] == LLONG_MAX) return dis[n];
    return 1LL * dis[n] * a;
}

int mark[N];

LL bfsb() {
    now++;
    queue<int> q;
    set<int> s;
    REPP(i, 2, n) s.insert(i);
    q.push(1), dis[1] = 0;
    dis[n] = LLONG_MAX;
    while (q.size()) {
        int x = q.front(); q.pop();
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            mark[y] = x;
        }
        set<int> :: iterator it;
        vector<int> tmp;
        for (it = s.begin(); it != s.end(); it++) {
            int y = *it;
            if (mark[y] == x) continue;
            else {
                dis[y] = dis[x] + 1;
                q.push(y);
                tmp.push_back(y);
            }
        }
        REP(i, tmp.size()) s.erase(tmp[i]);
    }
    if (dis[n] == LLONG_MAX) return dis[n];
    return 1LL * dis[n] * b;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif
    while (scanf("%d%d", &n, &m) > 0) {
        scanf("%d%d", &a, &b);
        REPP(i, 1, n) edge[i].clear();
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        printf("%lld\n", min(bfs(), bfsb()));
    }
    return 0;
}
