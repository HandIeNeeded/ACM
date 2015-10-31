#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define PII pair<LL, int>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 6;
const LL inf = 1LL << 60;
vector<int> edge[M * 2], val[M * 2];
bool vis[M * 2];

LL dis[M * 2][2];
int n, m;

void dijkstra(int x, int id) {
    REPP(i, 1, n + m) dis[i][id] = inf, vis[i] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    dis[x][id] = 0;
    q.push({0, x});
    while (q.size()) {
        int x = q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        REP(i, edge[x].size()) {
            int y = edge[x][i];
            if (vis[y]) continue;
            if (dis[y][id] > dis[x][id] + val[x][i]) {
                dis[y][id] = dis[x][id] + val[x][i];
                q.push({dis[y][id], y});
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("1013.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int now = n;
        REPP(i, 1, m) {
            now++;
            int cost, cnt;
            scanf("%d%d", &cost, &cnt);
            REP(i, cnt) {
                int x;
                scanf("%d", &x);
                edge[x].push_back(now), val[x].push_back(cost);
                edge[now].push_back(x), val[now].push_back(cost);
            }
        }
        dijkstra(1, 0), dijkstra(n, 1);
        REPP(i, 1, n) dis[i][0] = max(dis[i][0], dis[i][1]);
        LL ans = inf;
        vector<int> res;
        REPP(i, 1, n) {
            if (dis[i][0] < ans) {
                ans = dis[i][0];
                res.clear();
                res.push_back(i);
            }
            else if (dis[i][0] == ans) {
                res.push_back(i);
            }
        }
        printf("Case #%d: ", ca++);
        if (ans == inf) {
            puts("Evil John");
        }
        else {
            printf("%lld\n", ans / 2);
            REP(i, res.size()) {
                printf("%d%c", res[i], " \n"[i == int(res.size()) - 1]);
            }
        }
        REPP(i, 1, now) edge[i].clear(), val[i].clear();
    }

    return 0;
}


