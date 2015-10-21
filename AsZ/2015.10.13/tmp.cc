#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 50;
char mp[N][N], g[N][N][N], tmp[N][N][N];
bool vis[N];
int use[N][N], k, n, w, h;

bool invalid(int x, int y) {
    return x < h - 1 || x >= n * h + (h - 1) || y < w - 1 || y >= n * w + (w - 1);
}

bool check(int tx, int ty, int id) {
    for (int i = tx - (h - 1), k = 0; i < tx + (2 * h - 1); i++, k++) {
        for (int j = ty - (w - 1), l = 0; j < ty + (2 * w - 1); j++, l++) {
            if (invalid(i, j) && g[id][k][l] != '.') return 0;
            if (isalpha(mp[i][j]) && isalpha(g[id][k][l])) return 0;
        }
    }
    return 1;
}

void paint(int tx, int ty, int id) {
    for (int i = tx - (h - 1), k = 0; i < tx + (2 * h - 1); i++, k++) {
        for (int j = ty - (w - 1), l = 0; j < ty + (2 * w - 1); j++, l++) {
            tmp[id][k][l] = mp[i][j];
            if (!isalpha(mp[i][j])) mp[i][j] = g[id][k][l];
        }
    }
}

void recover(int tx, int ty, int id) {
    for (int i = tx - (h - 1), k = 0; i < tx + (2 * h - 1); i++, k++) {
        for (int j = ty - (w - 1), l = 0; j < ty + (2 * w - 1); j++, l++) {
            mp[i][j] = tmp[id][k][l];
        }
    }
}

bool dfs(int dep, int x, int y, int tx, int ty) {
    if (dep == k) return 1;
    REP(i, k) {
        if (vis[i]) continue;
        if (check(tx, ty, i)) {
            paint(tx, ty, i);
            int nx = x, ny = y + 1;
            int nr = tx, nc = ty + w;
            if (ny == n) {
                nx++, ny = 0;
                nr = tx + h, nc = w - 1;
            }
            vis[i] = 1;
            if (dfs(dep + 1, nx, ny, nr, nc)) return 1;
            recover(tx, ty, i);
            vis[i] = 0;
        }
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    freopen("ascii.in", "r", stdin);
    freopen("ascii.out", "w", stdout);

    cin >> k >> w >> h;
    n = int(sqrt(k + 0.5));
    REP(i, k) {
        REP(j, 3 * h - 2) {
            cin >> g[i][j];
        }
    }
    memset(mp, '.', sizeof(mp));
    dfs(0, 0, 0, h - 1, w - 1);
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
