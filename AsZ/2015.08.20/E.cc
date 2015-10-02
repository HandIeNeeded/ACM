#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1005;
int a[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        int m;
        scanf("%d", &m);
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", *max_element(a + x, a + y + 1));
        }
    }

    return 0;
}


