#include <cstdio>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], c[N];
int x[N], y[N], z[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n), n) {
        REPP(i, 1, n) {
            scanf("%d%d%d", a + i, b + i, c + i);
            x[i] = a[i] - b[i];
            y[i] = a[i] - c[i];
            z[i] = c[i] - b[i];
        }

        sort(x + 1, x + n + 1);
        sort(y + 1, y + n + 1);
        sort(z + 1, z + n + 1);
        LL ans = 0;
        for (int i = 1, j = 0, k = n - 1; i <= n; i++, j++, k--) {
            ans += 1LL * (j - k) * (x[i] + y[i] + z[i]);
        }
        printf("%lld\n", ans / 2);
    }

    return 0;
}

