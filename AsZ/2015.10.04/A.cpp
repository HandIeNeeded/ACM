#include <bits/stdc++.h>
#define MAXN 11234

using namespace std;
struct point {
    int id;
    int u, v;
    point (int id1 = 0, int u1 = 0, int v1 = 0) {
        id = id1, u = u1, v = v1;
    }
};

int ans[112345];
int f[1200][1200], lab[MAXN];

struct node {
    int sco, u, v;
    vector <point> que;
} a[MAXN];

vector <int> vec[1200];

int com(int u, int v) {
    return a[u].sco > a[v].sco;
}

void getAns(int x) {
    int tot = a[x].que.size();
    for (int i = 0; i < tot; ++i) {
        point tmp = a[x].que[i];
        ans[tmp.id] = f[tmp.u][tmp.v] + 1;
    }
}

void update(int x) {
    int u = a[x].u;
    int v = a[x].v;
    int tu = vec[u].size();
    int tv = vec[v].size();
    for (int i = 0; i < tu; ++i)
        for (int j = 0; j < tv; ++j)
            f[vec[u][i]][vec[v][j]]++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);

    int lim = (1 << 10);
    for (int i = 0; i < lim; ++i)
        for (int j = 0; j <= i; ++j)
            if ((i & j) == j)
                vec[i].push_back(j);

    for (int i = 1; i <= n; ++i) {
        int tot;
        scanf("%d%d", &a[i].sco, &tot);
        a[i].u = 0;
        for (int j = 1; j <= tot; ++j) {
            int x;
            scanf("%d", &x);
            a[i].u |= (1 << (x - 1));
        }
        a[i].v = ((1 << k) - 1) - a[i].u;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int id, tot;
        scanf("%d%d", &id, &tot);
        int tmp = 0;
        for (int j = 1; j <= tot; ++j) {
            int x;
            scanf("%d", &x);
            tmp |= (1 << (x - 1));
        }
        int u = tmp & a[id].u;
        int v = tmp & a[id].v;
        point p = point(i, u, v);
        a[id].que.push_back(p);
    }

    for (int i = 1; i <= n; ++i)
        lab[i] = i;

    sort(lab + 1, lab + n + 1, com);

    for (int i = 1; i <= n; ++i) {
        int j = i;
        for (; j + 1 <= n && a[lab[j + 1]].sco == a[lab[i]].sco; ++j);
        for (int k = i; k <= j; ++k)
            getAns(lab[k]);
        for (int k = i; k <= j; ++k)
            update(lab[k]);
        i = j;
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
