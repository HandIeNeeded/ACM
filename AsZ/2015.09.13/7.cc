#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1006;
int a[N];

int main() {
#ifdef HOME
    freopen("7.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        int q;
        scanf("%d", &q);
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int mx = -1;
            REPP(i, x, y) {
                mx = max(mx, a[i]);
            }
            printf("%d\n", mx);
        }
    }


    return 0;
}

