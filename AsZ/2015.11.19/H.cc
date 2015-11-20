#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 15;
int r[N];

int calc(int x, int y) {
    int sqr = x * x + y * y;
    int pos = lower_bound(r + 1, r + 10 + 1, sqr) - r;
    return 11 - pos;
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    REPP(i, 1, 10) {
        r[i] = (20 * i) * (20 * i);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            ans += calc(x, y);
        }
        printf("%d\n", ans);
    }


    return 0;
}


