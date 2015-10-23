#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int ans = 0;
    REPP(i, 1, 4) {
        REPP(j, 1, 4) {
            ans += lcm(i, j);
        }
    }
    cout << ans << endl;


    return 0;
}


