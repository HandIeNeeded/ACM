#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define double double

using namespace std;

const int N = 2;
const double eps = 1e-8;
double v[N], r[N], c[N];
double tv, tc;

int cmp(double x) {
    if (fabs(x) < eps) return 0;
    else if (x < 0) return -1;
    else return 1;
}

int main() {
    ios :: sync_with_stdio(0);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, ca = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> tv >> tc;
        REP(i, n) {
            cin >> r[i] >> c[i];
        }
        cout << "Case #" << ca++ << ": ";
        if (n == 1) {
            if (cmp(c[0] - tc) != 0) {
                cout << "IMPOSSIBLE" << endl;
            }
            else {
                cout << fixed << setprecision(8) << tv / r[0] << endl;
            }
        }
        else {
            if (cmp(c[0] - tc) > 0 && cmp(c[1] - tc) > 0 || cmp(c[0] - tc) < 0 && cmp(c[1] - tc) < 0) {
                cout << "IMPOSSIBLE" << endl;
            }
            else if (cmp(c[0] - tc) == 0 && cmp(c[1] - tc) == 0) {
                cout << fixed << setprecision(8) << tv / (r[0] + r[1]) << endl;
            }
            else if (cmp(c[0] - tc) == 0 || cmp(c[1] - tc) == 0) {
                if (cmp(c[0] - tc) == 0) {
                    cout << fixed << setprecision(8) << tv / r[0] << endl;
                }
                else {
                    cout << fixed << setprecision(8) << tv / r[1] << endl;
                }
            }
            else {
                double x = tc * tv - c[1] * tv;
                x /= (c[0] - c[1]);
                double ans = max(x / r[0], (tv - x) / r[1]);
                cout << fixed << setprecision(8) << ans << endl;
            }
        }
    }

    return 0;
}
