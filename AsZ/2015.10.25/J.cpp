#include <bits/stdc++.h>
#define MAXN 15

using namespace std;
typedef int arrayNN[MAXN][MAXN];

char st[15][15];
char dir[] = "URDL";
arrayNN clean, emp, vis[4];
int ans = 0;

    int n, m;
int gx[4] = {-1, 0, 1, 0};
int gy[4] = {0, 1, 0, -1};

int check(int x, int y) {
    if (x < 0 || x >= n) return 0;
    if (y < 0 || y >= m) return 0;
    if (emp[x][y] == 1) return 0;
    return 1;
}
void dfs(int px, int py, int pp) {
    if (vis[pp][px][py]) return ;
    vis[pp][px][py] = 1;
    if (!clean[px][py]) {
        ++ans;
        clean[px][py] = 1;
    }
    int nx = px + gx[pp];
    int ny = py + gy[pp];
    if (check(nx, ny)) dfs(nx, ny, pp);
    else dfs(px, py, (pp + 1) % 4);
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", st[i]);
    }
    memset(clean, 0, sizeof(clean));
    memset(vis, 0, sizeof(vis));
    memset(emp, 0, sizeof(emp));
    int px, py, pp;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (st[i][j] == '*')
                emp[i][j] = 1;
            else {
                if (st[i][j] != '.') {
                    px = i, py = j;
                    for (int k = 0; k < 4; ++k)
                        if (dir[k] == st[i][j])
                            pp = k;
                }
            }
        }
    ans = 0;
    dfs(px, py, pp);
    printf("%d\n", ans);
    return 0;
}
