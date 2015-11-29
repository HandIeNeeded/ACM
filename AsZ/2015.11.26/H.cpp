#include <bits/stdc++.h>

using namespace std;

char ch[5][5];
int a[5][5], vis[15][6];

vector<int> g[5][5];
vector< pair <int, int> > st[20];

void init() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            g[i][j].push_back(i);
            g[i][j].push_back(j + 4);
            int i1 = i / 2;
            int j1 = j / 2;
            g[i][j].push_back(8 + i1 * 2 + j1);
            for (int k = 0; k < 3; ++k)
                st[g[i][j][k]].push_back({i, j});
        }
}

void getNext(int x, int y, int &nx, int &ny) {
    nx = x, ny = y + 1;
    if (ny == 4) nx++, ny = 0;
}

int dfs(int x, int y) {
    if (x == 4) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                printf("%d", a[i][j]);
            printf("\n");
        }
        return 1;
    }

    int nx, ny;
    getNext(x, y, nx, ny);
    if (a[x][y]) {
        return dfs(nx, ny);
    }

    int tvis[5];
    memset(tvis, 0, sizeof(tvis));
    for (int i = 0; i < 3; ++i) {
        int p = g[x][y][i];
        for (int k = 0; k < 4; ++k) {
            int tx = st[p][k].first;
            int ty = st[p][k].second;
            if (a[tx][ty]) tvis[a[tx][ty]] = 1;
        }
    }

    for (int i = 1; i <= 4; ++i)
        if (!tvis[i]) {
            a[x][y] = i;
            if (dfs(nx, ny)) return 1;
            a[x][y] = 0;
        }
    return 0;
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif // HOME
    int T;
    scanf("%d", &T);
    init();
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d:\n", ca);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 4; ++i) {
            scanf("%s", ch[i]);
            for (int j = 0; j < 4; ++j)
                if (ch[i][j] == '*')
                    a[i][j] = 0;
                else {
                    a[i][j] = ch[i][j] - '0';
                    for (int k = 0; k < 3; ++k)
                        vis[g[i][j][k]][a[i][j]] = 1;
                }
            }

        dfs(0, 0);
    }
    return 0;
}
