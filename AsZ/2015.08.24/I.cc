#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int N = 1005;
int vis[N][N];
char mp[N][N], ans[N << 1];
vector<int> pos[N << 1];
int n, m, mx;

bool good(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs1(int x, int y) {
    //cout << x << ' ' << y << endl;
    if (vis[x][y]) return ;
    if (mp[x][y] == '1') {
        vis[x][y] = 2;
        pos[x + y].push_back(x);
        pos[x + y].push_back(y);
        mx = max(mx, x + y);
    }
    else {
        vis[x][y] = 1;
        REP(i, 4) {
            int tx = x + dx[i], ty = y + dy[i];
            if (good(tx, ty)) dfs1(tx, ty);
        }
    }
}

void dfs2(int x, int y) {
    //cout << x << ' ' << y << endl;
    if (vis[x][y]) return ;
    if (mp[x][y] == '1') {
        vis[x][y] = 2;
        pos[x + y].push_back(x);
        pos[x + y].push_back(y);
        mx = max(mx, x + y);
    }
    else {
        vis[x][y] = 1;
        REP(i, 2) {
            int tx = x + dx[i], ty = y + dy[i];
            if (good(tx, ty)) dfs2(tx, ty);
        }
    }
}

void go() {
    while (mx < n + m && !vis[n][m]) {
        int pre = mx;
        for (int i = 0; i < int(pos[pre].size()); i += 2) {
            int x = pos[pre][i], y = pos[pre][i + 1];
            //cout << x << ' ' << y << "hehe" << endl;
            REP(i, 2) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (good(tx, ty)) dfs2(tx, ty);
            }
        }
        for (int i = pre + 1; i < mx; i++) ans[i] = '0';
        ans[mx] = '1';
    }
    if (vis[n][m] == 1) {
        for (int i = mx + 1; i <= n + m; i++) {
            ans[i] = '0';
        }
    }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) {
            REPP(j, 1, m) {
                vis[i][j] = 0;
            }
        }
        REPP(i, 1, n + m) pos[i].clear();
        REPP(i, 1, n) {
            scanf("%s", mp[i] + 1);
        }
        mx = 0;
        //cout << "hehe" << endl;
        dfs1(1, 1);
        //cout << "hehe" << endl;
        ans[mx] = '1';
        //cout << mx << endl;
        //REP(i, pos[mx].size()) {
        //    cout << pos[mx][i] << ' ';
        //}
        //cout << endl;
        int start = mx;
        if (vis[n][m] == 1) {
            puts("0");
            continue;
        }
        else {
            go();
        //cout << "hehe" << endl;
        //cout << mx << endl;
            REPP(i, start, n + m) {
                putchar(ans[i]);
            }
            puts("");
        }
    }


    return 0;
}

