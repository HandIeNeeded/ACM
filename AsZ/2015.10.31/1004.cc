#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("1004.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        int d = __gcd(a, b);
        printf("Case #%d: ", ca++);
        if (n / d & 1) {
            puts("Yuwgna");
        }
        else {
            puts("Iaka");
        }
    }


    return 0;
}


