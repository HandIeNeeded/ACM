#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    cin >> t;
    LL ans = 0;
    int k = t / 2 + 1;
    ans = 1LL * k * (k + 1) - 1;
    if (t % 2 == 0) {
        ans -= k;
    }
    cout << ans << endl;


    return 0;
}

