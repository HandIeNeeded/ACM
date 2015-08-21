#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int num[N];

int good(int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        if (((num[i] - num[i - 1]) & 1) == 0) {
            return 0;
        }
    }
    return 1;
}

LL sum(int l, int r) {
    LL ans = 0;
    REPP(i, l, r) {
        ans += num[i];
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    int n, m;
    while (t--) {
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) scanf("%d", num + i);
        while (m--) {
            int type, l, r;
            LL ans = -(1LL << 60);
            scanf("%d%d%d", &type, &l, &r);
            if (type) {
                num[l] = r; 
            }
            else {
                for (int i = l; i <= r; i++) {
                    for (int j = i; j <= r; j++) {
                        if (good(i, j)) {
                            ans = max(ans, sum(i, j));
                        }
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }


    return 0;
}

