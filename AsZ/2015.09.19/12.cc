#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5e6 + 5;   

int a[N];
int n, A, B;
int suffixMin[N], suffixMax[N];

int main() {
#ifdef HOME
    freopen("12.in", "r", stdin);
#endif
#ifndef HOME
#define lld I64d
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &A, &B);
        REPP(i, 1, n) scanf("%d", &::a[i]);
        suffixMin[n + 1] = INT_MAX, suffixMax[n + 1] = INT_MIN;
        for (int i = n; i >= 1; i--) {
            suffixMin[i] = min(suffixMin[i + 1], a[i]);
            suffixMax[i] = max(suffixMax[i + 1], a[i]);
        }
        int mi = INT_MAX, mx = INT_MIN;
        LL ans = LLONG_MIN;
        REPP(i, 1, n) {
            int y;
            if (B >= 0) y = max(mx, suffixMax[i + 1]);
            else y = min(mi, suffixMin[i + 1]);
            ans = max(ans, 1LL * A * a[i] * a[i] + 1LL * B * y);
            mi = min(mi, a[i]); 
            mx = max(mx, a[i]);
        }
        printf("Case #%d: %lld\n", ca++, ans);
    }


    return 0;
}

