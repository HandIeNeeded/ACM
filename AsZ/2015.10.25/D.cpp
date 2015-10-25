#include <bits/stdc++.h>
#define MAXN 1123

using namespace std;

struct node {
    int t, s, f;
    int k, b, l, r;
    void calcOther() {
        if (f < s) {
            k = -1;
            b = s + t;
            l = t;
            r = t + s - f;
        } else {
            k = 1;
            b = s - t;
            l = t;
            r = t + f - s;
        }
    }
} g[MAXN];

int checkParellel(node u, node v) {
    if (u.k * v.t + u.b != v.s) return 0;
    if (u.l >= v.l && u.l <= v.r) return 1;
    if (u.r >= v.r && u.r <= v.r) return 1;
    if (v.l >= u.l && v.l <= u.r) return 1;
    if (v.r >= u.r && v.r <= u.r) return 1;
    return 0;
}

int checkX(node u, node v) {
    int dy = u.b + v.b;
    int dt = (dy - 2 * u.b) / u.k;
    if (dt >= 2 * u.l && dt <= 2 * u.r && dt >= 2 * v.l && dt <= 2 * v.r) return 1;
    return 0;
}

int check(int u, int v) {
    if (g[u].k == g[v].k) return checkParellel(g[u], g[v]);
    else return checkX(g[u], g[v]);
}
int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &g[i].t, &g[i].s, &g[i].f);
        g[i].calcOther();
    }
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 1; j <= n; ++j)
            if (i != j) ans += check(i, j);
        printf("%d%c", ans, " \n"[i == n]);
    }
    return 0;
}
