#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 32

using namespace std;


char st[10][5];
long long f[MAXN][3], g[MAXN][3];

int getOther(int u, int v) {
    int vis[3];
    for (int i = 0; i <= 2; ++i) vis[i] = 0;
    vis[u] = vis[v] = 1;
    for (int i = 0; i <= 2; ++i) if (!vis[i]) return i;
}
void dfs(int n, int u) {
    if (f[n][u] != -1) return ;

    int ou = u;


    if (f[n - 1][u] == -1) dfs(n - 1, u);
    int v1 = g[n - 1][u];
    long long tmp = f[n - 1][u];
    int nowu;
    while (1) {
        tmp++;
        nowu = getOther(u, v1);
        if (f[n - 1][v1] == -1) dfs(n - 1, v1);
        int v2 = g[n - 1][v1];
        tmp += f[n - 1][v1];
        if (v2 == nowu) {
            break;
        }
        u = nowu;
        v1 = v2;
    }
    g[n][ou] = nowu;
    f[n][ou] = tmp;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("H.in", "r", stdin);
#endif
    int n;
    scanf("%d\n", &n);
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= 6; ++i) {
        scanf("%s", st[i]);
        int u = st[i][0] - 'A';
        int v = st[i][1] - 'A';
        if (f[1][u] == -1) {
            f[1][u] = 1;
            g[1][u] = v;
        }
    }
    dfs(n, 0);
    cout << f[n][0] << endl;
    return 0;
}
