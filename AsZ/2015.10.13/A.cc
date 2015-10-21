#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define left Left
#define right Right

using namespace std;

const int N = 30;
char mp[N][N];
char g[N][N][N], tmp[N][N][N];
bool vis[N], use[N][N];
int k, n, w, h, up, down, left, right;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

bool invalid(int x, int y) {
    return x < up || x >= down || y < left || y >= right;
}

bool check(int tx, int ty, int id) {
    REP(i, 3 * h - 2) {
        REP(j, 3 * w - 2) {
            char a = mp[tx + i][ty + j], b = g[id][i][j];
            if (invalid(tx + i, ty + j) && isalpha(b)) return 0;
            if (isalpha(a) && isalpha(b)) return 0;
        }
    }
    return 1;
}

bool good() {
    int cnt = 0, sx = 0, sy = 0;
    REPP(i, up, down - 1) {
        REPP(j, left, right - 1) {
            use[i][j] = 0;
            if (mp[i][j] == '.') sx = i, sy = j, cnt++;
        }
    }
    if (cnt == 0) return 1;
    queue<int> q;
    q.push(sx), q.push(sy);
    while (q.size()) {
        sx = q.front(); q.pop();
        sy = q.front(); q.pop();
        REP(i, 4) {
            int tx = sx + dx[i];
            int ty = sy + dy[i];
            if (invalid(tx, ty) || mp[tx][ty] != '.') continue;
            if (!use[tx][ty]) {
                cnt--;
                use[tx][ty] = 1;
                q.push(tx);
                q.push(ty);
            }
        }
    }
    return cnt == 0;
}

void paint(int tx, int ty, int id) {
    REP(i, 3 * h - 2) {
        REP(j, 3 * w - 2) {
            char a = mp[tx + i][ty + j], b = g[id][i][j];
            tmp[id][tx + i][ty + j] = a;
            mp[tx + i][ty + j] = a == '.' ? b : a;
        }
    }
}

void recover(int tx, int ty, int id) {
    REP(i, 3 * h - 2) {
        REP(j, 3 * w - 2) {
            mp[tx + i][ty + j] = tmp[id][tx + i][ty + j];
        }
    }
}

bool dfs(int dep, int x, int y, int tx, int ty) {
    if (dep == k) return 1;
    REP(i, k) {
        if (vis[i]) continue;
        if (check(tx, ty, i)) {
            paint(tx, ty, i);
            if (good()) {
                int nx = x, ny = y + 1;
                int nr = tx, nc = ty + w;
                if (ny == n) {
                    nx++, ny = 0;
                    nr = tx + h, nc = 0;
                }
                vis[i] = 1;
                if (dfs(dep + 1, nx, ny, nr, nc)) return 1;
            }
            recover(tx, ty, i);
            vis[i] = 0;
        }
    }
    return 0;
}

int main() {
    cin >> k >> w >> h;
    n = int(sqrt(k + 0.5));
    up = h - 1, down = n * h + (h - 1), left = w - 1, right = n * w + (w - 1);
    REP(i, k) {
        REP(j, 3 * h - 2) {
            cin >> g[i][j];
        }
    }
    memset(mp, '.', sizeof(mp));
    dfs(0, 0, 0, 0, 0);
    int W = n * w, H = n * h;
    cout << W << ' ' << H << endl;
    for (int i = h - 1, j = 0; j < H; i++, j++) {
        for (int k = w - 1, l = 0; l < W; k++, l++) {
            cout << mp[i][k];
        }
        cout << endl;
    }
    return 0;
}
