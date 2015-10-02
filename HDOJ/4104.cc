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

    int n;
    while (scanf("%d", &n) > 0) {
        REPP(i, 1, n) scanf("%d", a + i);
        sort(a + 1, a + n + 1);
        int sum  = 0, ans = 0;
        REPP(i, 1, n) {
            if (a[i] > sum + 1) {
                ans = sum + 1;
                break;
            }
            else {
                sum += a[i];
                ans = sum + 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}


