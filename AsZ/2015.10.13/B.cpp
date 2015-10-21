#include <bits/stdc++.h>
#define MAXN 3123

using namespace std;

double f[2][MAXN][MAXN];
long long n, a, b;
int vis[2][MAXN][MAXN];
//a f[0] VIP

void dfs(int k, int u, int v) {
    if (vis[k][u][v]) return ;
    vis[k][u][v] = 1;
    if (u + v == n) {
        f[k][u][v] = 1;
        return;
    }
    int tu = a - u, tv = b - v, slot;
    long long sum = 2LL * tu + tv;
    if (k = 0) sum += 2;
    else sum++;
    f[k][u][v] = 0;
    if (u + 1 <= a) {
        dfs(k, u + 1, v);
        f[k][u][v] += ((2.0 * tu) / sum) * f[k][u + 1][v];
    }
    if (v + 1 <= b) {
        dfs(k, u, v + 1);
        f[k][u][v] += ((1.0 * tv) / sum) * f[k][u][v + 1];
    }
}
int main() {
    freopen("bonus.in", "r", stdin);

#ifndef HOME
    freopen("bonus.out", "w", stdout);
#endif
    cin >> n >> a >> b;
    dfs(0, 0, 0);
    dfs(1, 0, 0);
    printf("%.10f\n%.10f", 1 - f[0][0][0], 1 - f[1][0][0]);
    return 0;
}
