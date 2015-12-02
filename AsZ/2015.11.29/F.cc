#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 15;
const double eps = 1e-5;
LL a[N];
LL d[N][N];
int n;

bool good(LL x) {
    double res = 0;
    double pw = 1;
    //cout << "hehe: " << x << endl;
    REPP(i, 0, n) {
        res += a[i] * pw;
        pw *= x;
    }
    //cout << fixed << setprecision(10) << res << ' ' << pw << endl;
    return fabs(res) < eps;
}

bool test(LL x, int now) {
    double res = 0;
    double pw = 1;
    REPP(i, 0, n) {
        res += d[now][i] * pw;
        pw *= x;
    }
    return fabs(res) < eps;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    cin >> n;
    REPP(i, 0, n - 1) cin >> a[i];
    a[n] = 1;
    reverse(a, a + n);
    REPP(i, 0, n) d[0][i] = a[i];
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            d[i][j - 1] = d[i - 1][j] * j;
        }
    }
    //LL x = a[n];
    int ans = n;
    REPP(i, -10, 10) {
        if (good(i)) {
            int now = 1;
            while (test(i, now)) now++;
            ans -= now;
        }
    }
    cout << ans << endl;

    return 0;
}


