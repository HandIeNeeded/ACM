#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;

int L[N], R[N];
int vis[N * 100];
int n, A, B, l;

int main() {
#ifdef HOME
    freopen("10.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &A, &B, &l);
        REPP(i, 1, n) scanf("%d%d", L + i, R + i);
        REPP(i, 1, l) vis[i] = 0;
        REPP(i, 1, n) {
            REPP(j, L[i], R[i] - 1) vis[j] = 1;
        }
        int now = 0, ans = INT_MAX;
        REPP(i, 0, l - 1) {
            ans = min(ans, now);
            if (vis[i]) now -= A;
            else now += B;
        }
        ans = min(ans, now);
        printf("Case #%d: %d\n", ca++, -ans);
    }

    return 0;
}

