#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

bool test(int x) {
    int rt = sqrt(x + 0.5);
    return rt * rt == x;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) > 0) {
        int good = 1;
        REPP(i, 1, n) {
            int x;
            scanf("%d", &x);
            good &= test(x);
        }
        good ? puts("Yes") : puts("No");
    }


    return 0;
}


