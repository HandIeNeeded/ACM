#include <bits/stdc++.h>
#define MAXN 112345

using namespace std;

const int lim = 50;
const long long INF = 1e16 + 10;

long long g[MAXN];
int ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int N, n;
        scanf("%d", &n);
        N = 0;
        for (int i = 0; i < MAXN; ++i)
            g[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int ua;
            long long ux;
            scanf("%d%lld", &ua, &ux);
            g[ua] += ux;
            N = max(N, ua);
        }
        for (int i = 0; i <= N; ++i)
            ans[i] = 0;
        long long last = 0;
        int lastPos = N;
        for (int i = N; i >= 0; --i) {
            last = last * 2;
            if (last >= INF) last = INF;
            if (last <= g[i])  {
                g[i] -= last;
                last = g[i] & 1;
                ans[i] = last;
                for (int j = i + 1; j <= lastPos; ++j)
                    ans[j] = 0;
                if (last == 1) lastPos = i;
                else lastPos = i - 1;
            } else {
                int j = i;
                int jw = 0;
                long long x = g[i];
                for (long long tmp = x; tmp || jw != 0; tmp /= 2, ++j) {
                    int u = tmp & 1;
                    int v = ans[j];
                    // v + jw - u
                    int tt = v + jw - u;
                    if (tt < 0) {
                        jw = -1;
                        tt += 2;
                    } else jw = 0;
                    ans[j] = tt;
                }
                for (; ans[lastPos] != 1; --lastPos);

                last = 0;
                for (int j = lastPos; j >= i && last < INF; --j) {
                    last = last * 2 + ans[j];
                }
              /*  last += x & 1;
                ans[i] = x & 1; */
            }
        }
        printf("Case #%d: ", ca);
        if (lastPos >= 0) {
            for (int i = lastPos; i >= 0; --i)
                printf("%d", ans[i]);
        } else printf("0");
        printf("\n");
    }
    return 0;
}
