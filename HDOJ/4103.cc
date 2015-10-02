#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const double pi = acos(-1);

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int a, b;
    double d;

    while (scanf("%d%d%lf", &a, &b, &d), a | b) {
        printf("%d\n", a - 1);
    }

    return 0;
}


