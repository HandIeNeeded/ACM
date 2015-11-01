#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
vector<int> edge[N], Edge[N];
int dis[N], vis[N], use[N], key[N], n, m;

bool dfs(int x, int p) {
    int good = 0;
    for (auto &y: Edge[x]) {
        if (y != p) {
            if (dfs(y, x)) {
                good = 1;
                edge[x].push_back(y);
                edge[y].push_back(x);
            }
        }
    }
    good |= key[x];
    use[x] = good;
    return good;
}

int bfs(int x) {
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(x), dis[x] = 0, vis[x] = 1;
    while (q.size()) {
        x = q.front(); q.pop();
        for (auto &y: edge[x]) {
            if (!vis[y]) {
                q.push(y);
                dis[y] = dis[x] + 1;
                vis[y] = 1;
            }
        }
    }
    int ans = -1, id = -1;
    REPP(i, 1, n) if (vis[i]) {
        if (dis[i] > ans) {
            ans = dis[i];
            id = i;
        }
    }
    return id;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    REPP(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }
    REPP(i, 1, m) {
        int x;
        cin >> x;
        key[x] = 1;
        if (i == m) {
            dfs(x, 0);
            int cnt = 0;
            REPP(i, 1, n) if (use[i]) cnt++;
            int start = bfs(x);
            int end = bfs(start);
            //cout << start << ' ' << end << endl;
            start = min(start, end);
            cout << start << endl;
            cout << 2 * cnt - 2 - dis[end] << endl;
        }
    }
    return 0;
}


