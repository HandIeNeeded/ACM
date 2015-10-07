#include <bits/stdc++.h>
#define MAXN 51234

using namespace std;

int b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        int lim = 30;
        double fm = 1.0 * (n + 1) * n / 2.0;
        double ansAnd = 0, ansOr = 0, ansXor = 0;
        for (int i = 0; i <= lim; ++i) {
            int lastOne = 0;
            int lastZero = 0;
            int oneCnt = 0;
            int sum[2];
            sum[0] = sum[1] = 0;
            for (int j = 1; j <= n; ++j) {
                int x = ((b[j] & (1 << i)) ? 1 : 0);
                if (x == 0) lastZero = j;
                else {
                    oneCnt++;
                    sum[oneCnt & 1] += j - lastOne;
                    lastOne = j;
                }
                ansAnd += 1.0 * (1 << i) / fm * (j - lastZero);
                ansOr += 1.0 * (1 << i) / fm * lastOne;
                ansXor += 1.0 * (1 << i) / fm * sum[oneCnt & 1];
            }
        }
        printf("Case #%d: %.6f %.6f %.6f\n", ca, ansAnd, ansOr, ansXor);
    }
    return 0;
}
