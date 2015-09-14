#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 5;
int degree[N];
map<PII, int> mp, Edge;
int vis[N];

void modify(int &x, int &y) {
    if (x > y) swap(x, y);
}

PII q[N];
vector<int> edge[N];
LL ans[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        mp.clear(), Edge.clear();
        REPP(i, 1, n) {
            degree[i] = 0, edge[i].clear();
        }
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y) continue;
            modify(x, y);
            Edge[{x, y}]++;
            edge[x].push_back(y);
            edge[y].push_back(x);
            degree[x]++, degree[y]++;
        }
        int bound = int(sqrt(m * 2 + 0.5)) + 1;
        int Q;
        scanf("%d", &Q);
        REPP(i, 1, Q) ans[i] = 0;
        REPP(i, 1, Q) {
            int x, y;
            scanf("%d%d", &x, &y);
            modify(x, y);
            q[i] = {x, y};
        }
        REPP(i, 1, n) {
            if (degree[i] >= bound) {
                REPP(k, 1, n) vis[k] = 0;
                REP(k, edge[i].size()) {
                    vis[edge[i][k]]++;
                }
                REPP(j, 1, Q) {
                    if (q[j].first == q[j].second) continue;
                    if (!Edge.count(q[j])) {
                        int x, y;
                        tie(x, y) = q[j];
                        if (vis[x] && vis[y]) {
                            ans[j] += 1LL * vis[x] * vis[y];
                        }
                    }
                }
            }
            else {
                REP(k, edge[i].size()) {
                    int x = edge[i][k];
                    REPP(j, k + 1, edge[i].size() - 1) {
                        int y = edge[i][j];
                        if (x == y) continue;
                        modify(x, y);
                        if (!Edge.count({x, y})) {
                            mp[{x, y}]++;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n", ca++);
        REPP(i, 1, Q) {
            if (q[i].first == q[i].second) {
                puts("0 1");
            }
            else if (Edge.count(q[i])) {
                printf("1 %d\n", Edge[q[i]]);
            }
            else {
                LL tmp = ans[i] + mp[q[i]];
                if (tmp) {
                    printf("2 %lld\n", tmp);
                }
                else {
                    puts("The pair of cities are not connected or too far away.");
                }
            }
        }
    }
    return 0;
}
