#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;

clock_t st;
pair<LL, LL> get(int, int, int);
pair<LL, LL> solve(int, int);

pair<LL, LL> get(int d, int a, int b) {
    if (d == 1) {
        return {1LL * a * b, 0};
    }
    LL res;
    LL n = d - a % d;
    if (n == d) n = 0;
    a = (a + n) / d, b = (b + n) / d;
    LL tmp;
    tie(res, tmp) = solve(a, b);
    return {res * d, n + tmp * d};
}

void update(LL &ans, LL &n, pair<LL, LL> res) {
    if (res.first < ans) {
        tie(ans, n) = res;
    }
    else if (res.first == ans && res.second < n) {
        n = res.second;
    }
}

pair<LL, LL> solve(int a, int b) {
    //cout << a << ' ' << b << "xixi" << endl;
    if (1.0 * (clock() - st) / CLOCKS_PER_SEC) {
        return {0, 0};
    }
    if (a == b + 1) {
        return {1LL * a * b, 0};
    }
    LL ans = LLONG_MAX, n = 0;
    int d = a - b;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            if (a % d != b % d) continue;
            pair<LL, LL> res;
            if (d != i * i) {
                res = get(d / i, a, b);
                update(ans, n, res);
            }
            res = get(i, a, b);
            update(ans, n, res);
        }
    }
    //cout << ans << ' ' << n << endl;
    return {ans, n};
}

int main() {
#ifdef HOME
    //freopen("D.in", "r", stdin);
#endif

    int a, b;
    cin >> a >> b;
    st = clock();
    if (a < b) swap(a, b);
    if (a == b || b == 0) {
        cout << 0 << endl;
        return 0;
    }
    LL ans, n;
    tie(ans, n) = solve(a, b);
    cout << n << endl;
    return 0;
}


