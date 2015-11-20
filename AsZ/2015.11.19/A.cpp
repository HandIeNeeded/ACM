#include <bits/stdc++.h>
#define MAXN (1 << 22)

using namespace std;

int n, now, d[50][50];
int g[MAXN], sum[50];

void dfs(int s) {
    if (g[s] == now) return ;
    g[s] = now;
    for (int i = 0; i < n; ++i)
        if (!(s & (1 << i)) && sum[i] > 0) {
            for (int j = 0; j < n; ++j)
                sum[j] -= d[j][i];
            dfs(s | (1 << i));
            for (int j = 0; j < n; ++j)
                sum[j] += d[j][i];
        }
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (; T; --T) {
        ++now;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            sum[i] = 0;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &d[i][j]);
                sum[i] += d[i][j];
            }
          //  printf("%d: %d\n", i, sum[i]);
        }
        /*for (int i = 0; i < (1 << n); ++i)
            printf("%d: %d\n", i, g[i]); */

        dfs(0);
        int flag = 1;
        for (int i = 0; i < n; ++i)
            if (g[((1 << n) - 1) - (1 << i)] == now) {
                if (flag == 0) printf(" ");
                flag = 0;
                printf("%d", i + 1);
            }
        if (flag) printf("0");
        printf("\n");
    }
    return 0;
}
