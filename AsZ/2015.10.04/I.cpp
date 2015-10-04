#include <bits/stdc++.h>
#define MAXN 11234

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("I.in", "r", stdin);
#endif
    int N, M;
    int a, b;
    scanf("%d%d", &N, &M);
    scanf("%d%d", &a, &b);
    int row = N / a;
    int col = M / b;
    int ans = row * col;

    int lc = M % b;
    int flag = 1;
    if (lc) {
        int t = b / lc;
        int tmp = (row - 1) / t + 1;
        if (row) ans += tmp;
        if (tmp * t - row > 0) flag = 0;
    }
    int lr = N % a;
    if (lr) {
        int t = a / lr;
        int tmp = (col - 1) / t + 1;
        if (col) ans += tmp;
        if (tmp * t - col > 0) flag = 0;
    }

    if (lc * lr) ans += flag;

    printf("%d\n", ans);
    return 0;
}
