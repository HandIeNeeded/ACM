#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    if (n == 1) {
        puts("0 0");
        return 0;
    }
    int ans = 0;
    if (n & 1) {
        ans = (n - 1) / 2 * 3;
    }
    else {
        ans = (n - 2) / 2 * 3 + 1;
    }
    printf("%d %d\n", n - 1, max(ans, n - 1));

    return 0;
}

