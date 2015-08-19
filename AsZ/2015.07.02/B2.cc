#include <bits/stdc++.h>

#define LL unsigned long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 70;
LL dp[N];

void init() {
    dp[1] = 1;
    REPP(i, 2, 64) {
        dp[i] = 1ULL << i;
        REPP(j, 1, i / 2) {
            dp[i] -= dp[j] << (i - 2 * j);
        }
    }
}

LL calc(LL x, int n) {
    
    
    return 0;
}

int main() {
    int n;
    init();
    LL ans;
    while (scanf("%d%llu", &n, &ans), n) {
        MST(dp, 0);
        LL lo, hi;
        lo = 0, hi = (n == 64) ? -1 : (1ULL << n) - 1;
        cout << lo << ' ' << hi << endl;
        while(lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            if (calc(mid, n) < ans) lo = mid;
            else hi = mid;
        }
        REP(i, n) {
            if (hi & (1 << (n - 1 - i))) {
                putchar('B');
            }
            else {
                putchar('A');
            }
        }
        puts("");
    }

    return 0;
}

