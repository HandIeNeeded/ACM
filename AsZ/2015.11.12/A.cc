#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    int h, w;
    cin >> h >> w;
    if (h < w) swap(h, w);
    double x = h / 3.0;
    x = min(x, 1.0 * w);
    double y = h / 2.0;
    y = min(y, w / 2.0);
    x = max(x, y);
    cout << fixed << setprecision(3) << x << endl;

    return 0;
}


