#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200;

int dp[MAXN][MAXN][MAXN], sum[MAXN], a[MAXN], b[MAXN];

int bias = 200;
int dfs(int n, int i, int A, int B) {
    // eat
    if (i > n) return 0;
    /*if (A == 0) {
        dp[i][A][B] = 0;
        return 0;
    }
    if (B == 0) {
        dp[i][A][B] = sum[i];
        return dp[i][A][B];
    }*/
    //eat
    int tmp = 0;
    int nA = min(A + a[i], bias);
    int nB = B;
    if (dp[i + 1][nB][nA] == -1) dfs(n, i + 1, nB, nA);
    tmp = max(tmp, b[i] + sum[i + 1] - dp[i + 1][nB][nA]);

    // not eat
    if (A) {
        nA = A - 1;
        nB = min(B + a[i], bias);
        if (dp[i + 1][nA][nB] == -1) dfs(n, i + 1, nA, nB);
        tmp = max(tmp, dp[i + 1][nA][nB]);
    }


    /*if (A > B) {
        nA = A - B - 1;
        nB = min(a[i], bias);
        if (dp[i + 1][nA][nB] == -1) dfs(n, i + 1, nA, nB);
        tmp = max(tmp, dp[i + 1][nA][nB]);
    }

    if (A <= B) {
        nA = min(bias, a[i]);
        nB = B - A;
        if (dp[i + 1][nB][nA] == -1) dfs(n, i + 1, nB, nA);
        tmp = max(tmp, b[i] + sum[i + 1] - dp[i + 1][nB][nA]);
    }*/

    return dp[i][A][B] = tmp;
}

int main() {
#ifdef HOME
freopen("I.in", "r", stdin);
#endif
    int n, A, B;
    scanf("%d%d%d", &n, &A, &B);;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    A = min(A, bias);
    B = min(B, bias);
    for (int i = n; i >= 1; --i)
        sum[i] = sum[i + 1] + b[i];
    memset(dp, -1, sizeof(dp));
    int u = dfs(n, 1, A, B);
    printf("%d %d", u, sum[1] - u);
    return 0;
}
