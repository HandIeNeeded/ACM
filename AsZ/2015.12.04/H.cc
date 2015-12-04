#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    if (x >= a && x <= c && y >= b && y <= d) {
        puts("Yes");
    }
    else {
        puts("No");
    }


    return 0;
}

