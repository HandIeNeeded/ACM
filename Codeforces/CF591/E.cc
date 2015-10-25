#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1005;
char mp[N][N];
int dp[N][N][1 << 3];
int vis[N][N][1 << 3];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, m;

bool good(int x, int y) {
    return x <= n && x >= 1 && y <= m && y >= 1 && mp[x][y] != '#';
}

deque<int> q;

void spfa() {
    while (q.size()) {
        int x = q.front(); q.pop_front();
        int y = q.front(); q.pop_front();
        int st = q.front(); q.pop_front();
        REP(i, 4) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (good(tx, ty)) {
                int cost = mp[tx][ty] == '.';
                if (dp[tx][ty][st] > dp[x][y][st] + cost) {
                    dp[tx][ty][st] = dp[x][y][st] + cost;
                    if (!vis[tx][ty][st]) {
                        vis[tx][ty][st] = 1;
                        if (!q.size() || dp[tx][ty][st] <= dp[q[0]][q[1]][q[2]]) {
                            q.push_front(st);
                            q.push_front(ty);
                            q.push_front(tx);
                        }
                        else {
                            q.push_back(tx);
                            q.push_back(ty);
                            q.push_back(st);
                        }
                    }
                }
            }
        }
        vis[x][y][st] = 0;
    }
}

int go() {
    memset(dp, 0x3f, sizeof(dp));
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            if (mp[i][j] != '#' && mp[i][j] != '.') {
                int c = mp[i][j] - '1';
                dp[i][j][1 << c] = 0;
                vis[i][j][1 << c] = 1;
                //cout << i << ' ' << j << ' ' << c << endl;
                q.push_front(1 << c);
                q.push_front(j);
                q.push_front(i);
            }
        }
    }
    REP(st, 8) {
        REPP(i, 1, n) {
            REPP(j, 1, m) {
                int all = st;
                for (int sub = all; sub; sub = all & (sub - 1)) {
                    if (dp[i][j][st] > dp[i][j][sub] + dp[i][j][st ^ sub]) {
                        int cost = mp[i][j] == '.';
                        dp[i][j][st] = dp[i][j][sub] + dp[i][j][st ^ sub] - cost;
                        if (!vis[i][j][st]) {
                            vis[i][j][st] = 1;
                            if (!q.size() || dp[i][j][st] <= dp[q[0]][q[1]][q[2]]) {
                                q.push_front(st);
                                q.push_front(j);
                                q.push_front(i);
                            }
                            else {
                                q.push_back(i);
                                q.push_back(j);
                                q.push_back(st);
                            }
                        }
                    }
                }
            }
        }
        spfa();
    }
    int ans = inf;
    REPP(i, 1, n) {
        REPP(j, 1, m) {
            ans = min(ans, dp[i][j][7]);
        }
    }
    if (ans == inf) ans = -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REPP(i, 1, n) {
        cin >> (mp[i] + 1);
    }
    cout << go() << endl;
    return 0;
}

