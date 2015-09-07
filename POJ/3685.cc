#include <cstdio>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

LL calc(int x, int y) {
    return 1LL * x * x + 100000LL * x + 1LL * y * y - 100000LL * y + 1LL * x * y;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;

    scanf("%d", &t);
    while (t--) {
        int n;
        unsigned int m;
        scanf("%d%u", &n, &m);
        LL lo = -5e11, hi = 5e11;
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            LL cnt = 0;
            REPP(i, 1, n) {
                int lo = 0, hi = n + 1;
                while (lo + 1 < hi) {
                    int middle = (lo + hi) >> 1;
                    if (calc(middle, i) <= mid) {
                        lo = middle;
                    }
                    else {
                        hi = middle;
                    }
                }
                cnt += lo;
            }
            if (cnt < m) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        printf("%lld\n", hi);
    }

    return 0;
}

