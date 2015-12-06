#include <bits/stdc++.h>
#define MAXN 112345

using namespace std;

typedef int arrayN[MAXN];

arrayN fir, e, nxt, vis;
int num;

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

int cnt, ans, n, m;

void dfs(int x) {

    for (int p = fir[x]; p; p = nxt[p]) {
        if (cnt == n && e[p] == 1) {
            ans = 1;
            printf("Yes\n");
            return;
        }
        if (!vis[e[p]]) {
            vis[e[p]] = 1;
            cnt++;
            dfs(e[p]);
            if (ans) return ;
            vis[e[p]] = 0;
            cnt--;
        }
    }
}
int main() {
#ifndef HOME
    freopen("kingstd.out", "w", stdout);
#endif
    freopen("king.in", "r", stdin);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        link(u, v);
    }
    ans = 0;
    cnt = 1;
    vis[1] = 1;
    dfs(1);
    if (ans == 0) {
        printf("There is no route, Karl!\n");
    }
    return 0;
}
