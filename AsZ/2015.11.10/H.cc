#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int a[N];
int dp[N], prefix[N];

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%x", a + i);
    LL ans = LLONG_MIN;
    if (n >= 2000) {
        LL now = 0;
        REP(i, n) now += i ^ a[i];
        ans = max(ans, now);
    }
    else {
        REPP(j, 1, n) dp[j] = a[j - 1], prefix[j] = max(prefix[j - 1], dp[j]);
        ans = max(ans, 1LL * prefix[n]);
        REPP(i, 2, n) {
            REPP(j, 1, n) {
                dp[j] = ((i - 1) ^ a[j - 1]) + prefix[j - 1];
            }
            REPP(j, 1, n) {
                prefix[j] = max(prefix[j - 1], dp[j]);
            }
            ans = max(ans, 1LL * prefix[n]);
        }
    }
    cout << ans << endl;
    return 0;
}


