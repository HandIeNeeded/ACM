#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

LL calc(int x) {
    return 1LL * x * (x - 1) * (x - 2) / 6;
}

int a, b, c, l;

LL bad(int a, int b, int c) {
    LL ans = 0;
    for (int i = 0; i <= l; i++) {
        int aa = a + i;
        int r = l - i;

        int s = b + c;
        if (s > aa) continue;
        r = min(r, aa - s);
        ans += 1LL * (r + 1) * (r + 2) / 2;
    }

    return ans;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    cin >> a >> b >> c >> l;
    LL ans = calc(l + 3);
    ans -= bad(a, b, c);
    ans -= bad(a, c, b);
    ans -= bad(b, c, a);
    cout << ans << endl;

    return 0;
}

