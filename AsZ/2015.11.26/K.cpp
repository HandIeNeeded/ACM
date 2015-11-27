#include <bits/stdc++.h>
#define MAXN 4123
#define LL long long

using namespace std;
const int T = 0;
const int P = 1;

struct node {
    int num;
    LL sumUD, sumDU;
    LL facSumUD, facSumDU;
} g[MAXN][2];

LL dp[MAXN][2];
int N;
const LL INF = 1e18 + 1;

void getMin(LL &u, LL v) {
    if (v < u) u = v;
}

LL costUtoD(int u, int d, int k) {
    if (u < d) return 0;
    //int len = u - d + 1;
    return g[d][k].facSumUD - g[u + 1][k].facSumUD - 1LL * (N - u) * (g[d][k].sumUD - g[u + 1][k].sumUD);
}

LL costDtoU(int d, int u, int k) {
    if (d > u) return 0;
    //int len = u - d + 1;
    return g[u][k].facSumDU - g[d - 1][k].facSumDU - 1LL * (d - 1) * (g[u][k].sumDU - g[d - 1][k].sumDU);
}

int main() {
#ifdef HOME
    freopen("K.in", "r", stdin);
#endif // HOME
    int t;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d%d", &g[i][T].num, &g[i][P].num);
        for (int k = 0; k <= 1; ++k) {
            g[0][k].sumDU = g[0][k].facSumDU = 0;
            for (int i = 1; i <= N; ++i) {
                g[i][k].sumDU = g[i - 1][k].sumDU + g[i][k].num;
                g[i][k].facSumDU = g[i - 1][k].facSumDU + 1LL * i * g[i][k].num;
            }

            g[N + 1][k].sumUD = g[N + 1][k].facSumUD = 0;
            for (int i = N; i >= 1; --i) {
                g[i][k].sumUD = g[i + 1][k].sumUD + g[i][k].num;
                g[i][k].facSumUD = g[i + 1][k].facSumUD + 1LL * (N - i + 1) * g[i][k].num;
            }
        }

        for (int i = 2; i <= N; ++i)
            for (int k = 0; k <= 1; ++k) {
                dp[i][k] = costUtoD(i - 1, 1, k);
                for (int j = 2; j < i; ++j) {
                    int mid = (i - 1 + j) / 2;
                    getMin(dp[i][k], dp[j][1 - k] + costUtoD(i - 1, mid + 1, k) + costDtoU(j, mid, k));
                }
            }
        LL ans = INF;
        for (int k = 0; k <= 1; ++k)
            for (int i = 2; i <= N; ++i)
                getMin(ans, dp[i][k] + costDtoU(i, N, 1 - k));

        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
