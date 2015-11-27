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

int N, a[MAXN];
const LL INF = ~0U>>1;

void getMin(LL &u, LL v) {
    if (v < u) u = v;
}

LL getabs(int x) {
    x = 1LL * x;
    return x < 0 ? -x : x;
}

LL calcNow() {
    LL tAns = 0;
    for (int k = 0; k <= 1; ++k)
        for (int i = 1; i <= N; ++i) {
            LL tmp = INF;
            for (int j = 1; j <= N; ++j)
                if (a[j] == k)
                    getMin(tmp, getabs(j - i) * g[i][k].num);
                tAns += tmp;
        }
    return tAns;
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

        LL ans = INF;
        for (int i = 1; i < (1 << N) - 1; ++i) {
            for (int j = 0; j < N; ++j)
                if (i & (1 << j)) a[j + 1] = T;
                else a[j + 1] = P;
            getMin(ans, calcNow());
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}

