#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

pair<LL, LL> get(int d, int a, int b) {
    LL res = 0;
    LL n = d - a % d;
    if (n == d) n = 0;
    d = __gcd(a + n, b + n);
    res = 1LL * (a + n) * (b + n) / d;
    return {res, n};
}

void update(LL &ans, LL &n, pair<LL, LL> res) {
    if (res.first < ans) {
        tie(ans, n) = res;
    }
    else if (res.first == ans && res.second < n) {
        n = res.second;
    }
}

int main() {
#ifdef HOME
    //freopen("D2.in", "r", stdin);
#endif

    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int d = a - b;
    LL ans = LLONG_MAX, n = 0;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            if (a % d != b % d) continue;
            pair<LL, LL> res = get(i, a, b);
            update(ans, n, res);
            res = get(d / i, a, b);
            update(ans, n, res);
            
        }
    }
    //cout << ans << endl;
    cout << n << endl;
    return 0;
}
