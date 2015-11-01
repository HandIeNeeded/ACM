#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    LL a = 34524689549219, b = 39153010938487;
    LL d = __gcd(a, b);
    cout << d << ' ' << a / d * b << endl;


    return 0;
}


