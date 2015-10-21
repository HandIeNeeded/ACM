#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
char mp[3][N], tmp[3][N], g[55][3][N];
bool vis[55][3][N];
int n, k;

void getNext(int id) {
    memcpy(g[id], mp, sizeof(mp));
    REP(i, 3) REPP(j, 1, n - 3) tmp[i][j] = mp[i][j + 3];
    REP(i, 3) tmp[i][n - 2] = tmp[i][n - 1] = tmp[i][n] = '.';
    memcpy(mp, tmp, sizeof(tmp));
}

int dx[] = {0, -1, 1}, dy[] = {0, 0, 0};

bool good(int now, int x, int y) {
    return x >= 0 && x < 3 && g[now][x][y] == '.' && g[now - 1][x][y + 1] == '.';
}

bool bfs(int sx, int sy) {
    MST(vis, 0);
    int now = 0, x = sx, y = sy;
    queue<int> q;
    q.push(now), q.push(x);
    while (q.size()) {
        now = q.front(); q.pop();
        x = q.front(); q.pop();
        //cout << now << ' ' << x << endl;
        if (now > 50) {
            return 1;
        }
        REP(i, 3) {
            if (g[now][x][y + 1] != '.') continue;
            int tx = x + dx[i];
            if (good(now + 1, tx, y)) {
                if (!vis[now + 1][tx][y]) {
                    q.push(now + 1), q.push(tx);
                    vis[now + 1][tx][y] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        REP(i, 3) {
            cin >> (mp[i] + 1);
        }
        int sx, sy;
        REP(i, 3) {
            REPP(j, 1, n) if (mp[i][j] == 's') {
                sx = i, sy = j;
                mp[i][j] = '.';
            }
        }
        REP(i, 54) getNext(i);
        //REP(i, 5) {
        //    REP(j, 3) {
        //        cout << g[i][j] + 1 << endl;
        //    }
        //    cout << "***********************************************" << endl;
        //}
        if (bfs(sx, sy)) puts("YES");
        else puts("NO");
    }
    return 0;
}

