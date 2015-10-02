#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2e5 + 5;
int a[N], n;
double b[N];

double go(double x) {
    REPP(i, 1, n) {
        b[i] = a[i] - x;
    }
    double mx = 0, mi = 0;
    double now = 0;
    REPP(i, 1, n) {
        now += b[i];
        if (now < 0) now = 0;
        mx = max(mx, now);
    }
    now = 0;
    REPP(i, 1, n) {
        now += b[i];
        if (now > 0) now = 0;
        mi = min(mi, now);
    }
    return max(abs(mi), abs(mx));
}

int main() {

    cin >> n;
    REPP(i, 1, n) {
        cin >> a[i];
    }
    double lo = -20000, hi = 20000;
    REP(i, 100) {
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;
        if (go(a) > go(b)) {
            lo = a;
        }
        else {
            hi = b;
        }
    }
    cout << fixed << setprecision(12) << go(lo) << endl;
    return 0;
}

