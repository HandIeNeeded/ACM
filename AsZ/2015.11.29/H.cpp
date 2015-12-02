#include <bits/stdc++.h>
#define MAXT 112345
#define MAXN 11234

using namespace std;

struct node {
    int pl, st, fn;
} g[MAXT];

typedef int arrayN[MAXN];

int com(node A, node B) {
    return (A.pl < B.pl) || ((A.pl == B.pl && A.st < B.st));
}

arrayN cntPl, rmost, vis, rmTT, havePl;
int now;

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif // HOME
    int K, N, T;
    scanf("%d%d%d", &K, &N, &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d%d", &g[i].pl, &g[i].st, &g[i].fn);
    }
    sort(g + 1, g + T + 1, com);


    for (int i = 1; i <= N; ++i)
        rmost[i] = i;
    for (int i = 1; i <= T; ++i) {
        int j = i;
        for (; j + 1 <= T && g[j + 1].pl == g[j].pl; ++j);
        havePl[g[i].pl] = 1;
        ++now;
        for (int k = i; k <= j; ++k) {
            for (int t = g[k].st; t < g[k].fn; ++t) {
                cntPl[t]++;
                vis[t] = now;
            }
        }
        i = j;

        int last = N;
        for (int k = N - 1; k >= 1; --k) {
            if (vis[k] == now) last = k;
            rmost[k] = max(rmost[k], last);
        }
    }

    for (int i = 1; i <= K; ++i)
        if (!havePl[i]) {
            for (int i = 1; i <= N; ++i)
                rmost[i] = N;
            break;
        }
  //  for (int i = 1; i <= N; ++i)
    //    printf("%d: %d\n", i, rmost[i]);

    long long ans = 0;
    for (int i = 1; i <= N - 1; ++i)
        ans -= (rmost[i] - i);

    for (int i = 1; i <= N - 1; ++i) {
        if (cntPl[i] == K) continue;
        int j = i;
        for (; j + 1 <= N - 1 && cntPl[j + 1] != K; ++j);
        int l = j - i + 1;
        ans += 1LL * (l + 1) * l / 2;
        i = j;
    }
    /*rmTT[N] = N;
    int last = N;
    for (int i = N - 1; i >= 1; --i) {
        if (cntPl[i] == K) last = i;
        rmTT[i] = last;
    }

    for (int i = 1; i <= T; ++i) {
        int u = g[i].st;
        int v = g[i].fn;
        if (rmTT[u] >= v && rmost[u] < v) {
            cout << u << ' ' << v << endl;
            --ans;
        }
    } */

    cout << ans << endl;
    return 0;
}

