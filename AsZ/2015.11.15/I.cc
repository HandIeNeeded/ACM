#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 505;
int mp[N][N], w, h;
int tmp[N][N];
vector<pair<int, int> > id[N];

void solve(int n) {
    int a = (n + 1) >> 1, b;
    h = a;
    memset(mp, 0, sizeof(mp));
    memset(tmp, 0, sizeof(tmp));
    REPP(i, 1, h) {
        REPP(j, 1, h) {
            mp[i][j] = mp[j][i] = 2 * i - 1;
        }
    }
    int x = 1, y = 1;
    REPP(i, 1, n / 2) {
        if (i & 1) {
            REP(j, i) {
                REP(k, 2) {
                    tmp[x + j][y + k] = 2 * i;
                }
            }
            x += i, y = 1;
        }
        else {
            REP(j, 2) {
                REP(k, i) {
                    tmp[x + j][y + k] = 2 * i;
                }
            }
            x = 1, y += i;
        }
    }
    x = 1, y = h + 1;
    w = h;
    if ((n / 2) & 1) {
        b = n / 2 + 1, a = b - 1;
    }
    else {
        b = n / 2, a = b + 1;
    }
    if (h == a) {
        w += b;
        REP(i, a) REP(j, b) {
            mp[x + i][y + j] = tmp[1 + i][1 + j];
        }
    }
    if (h == b) {
        w += a;
        REP(i, b) REP(j, a) {
            mp[x + i][y + j] = tmp[1 + j][1 + i];
        }
    }
}

bool vis[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool in(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
}

void dfs(int x, int y, int i) {
    //cout << x << ' ' << y << ' ' << i << endl;
    id[i].push_back({x, y});
    vis[x][y] = 1;
    REP(d, 4) {
        int tx = x + dx[d], ty = y + dy[d];
        if (in(tx, ty) && !vis[tx][ty] && mp[tx][ty] == i) {
            dfs(tx, ty, i);
        }
    }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        solve(n);
        printf("%d %d\n", h, w);
        memset(vis, 0, sizeof(vis));
        REPP(i, 1, n) {
            id[i].clear();
            REPP(x, 1, h) {
                REPP(y, 1, w) if (!vis[x][y] && mp[x][y] == i) {
                    dfs(x, y, i);
                }
            }
        }
        REPP(i, 1, n) {
            int k = id[i].size();
            REP(j, k) {
                printf("%d %d%c", id[i][j].first, id[i][j].second, " \n"[j == k - 1]);
            }
        }
    }
    return 0;
}
