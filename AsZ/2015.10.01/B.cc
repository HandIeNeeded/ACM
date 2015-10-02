#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        LL ans = 0;
        REPP(i, 1, n) scanf("%d", a + i);
        int now = 1;
        REP(i, 9) {
            now *= 10;
            REPP(j, 1, n) b[i] = a[i] % now;
            sort(b + 1, b + n + 1);
            REPP(j, 1, n) {
                int need = now - b[j];
                int pos = lower_bound(b + 1, b + n + 1, need) - b;
                ans += n + 1 - pos;
                if (b[j] + b[j] >= now) ans--;
            }
        }
        printf("%lld\n", ans / 2);
    }
    return 0;
}
