#include <bits/stdc++.h>
#define MAXN 60
#define LIM 112345

using namespace std;

int f[MAXN], lab[MAXN], swi[MAXN];
vector <int> son[MAXN];

struct node {
    int point;
    int ti;
    int u;
} g[LIM];

int com(node A, node B) {
    return A.ti < B.ti;
}

int main() {
    freopen("instruction.in", "r", stdin);
#ifndef HOME
    freopen("instruction.out", "w", stdout);
#endif // HOME
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        char ch;
        scanf("%c %d", &ch, &f[i]);
        son[f[i]].push_back(i);
        if (ch == 'p') {
            char labCh;
            scanf(" %c\n", &labCh);
            lab[labCh - 'a'] = i;
        } else {
            scanf("\n");
        }
    }
    int m, tot = 0;
    scanf("%d\n", &m);
    for (int i = 1; i <= m; ++i) {
        int t;
        char ch;
        scanf("%d %c", &t, &ch);
        int pos = lab[ch - 'a'];
        vector < pair <int, int> > vec;
        int last = pos;
        for (pos = f[pos]; pos; pos = f[pos]) {
            vec.push_back({pos, last});
            last = pos;
        }
        reverse(vec.begin(), vec.end());
       // printf("%d:\n", i);
        for (int j = 0; j < vec.size(); ++j) {
            g[++tot].ti = t + j + 1;
            int u = vec[j].first;
            int v = vec[j].second;
            if (v == son[u][0]) g[tot].point = 0;
            else g[tot].point = 1;
            g[tot].u = u;

          //  printf("%d %d %d\n", g[tot].ti, g[tot].u, g[tot].point);
        }

    }

    memset(swi, 0, sizeof(swi));
    sort(g + 1, g + tot + 1, com);
    vector < pair <int ,int> > ans;
    for (int i = 1; i <= tot; ++i) {
       // printf("%d %d %d\n", g[i].ti, g[i].u, g[i].point);
        if (swi[g[i].u] != g[i].point) {
            ans.push_back({g[i].u, g[i].ti});
            swi[g[i].u] = g[i].point;
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
