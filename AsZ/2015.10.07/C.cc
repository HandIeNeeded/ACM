#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int q;
        scanf("%d", &q);
        printf("Case #%d:\n", ca++);
        while (q--) {
            int x;
            scanf("%d", &x);
            int a = max(1, x - m);
            int b = min(n, x - 1);
            int ans = max(0, b - a + 1);
            printf("%d\n", ans);
        }
    }


    return 0;
}


