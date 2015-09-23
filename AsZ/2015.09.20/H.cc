#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const double eps = 1e-12;
const int N = 40;
double pos[N];

bool equal(double x, double y) {
    return fabs(x - y) < eps;
}

void init() {
    LL a = 1, b = 2;
    REPP(i, 1, 30) {
        pos[i] = 1.0 * (a - 1) / b;
        a <<= 1;
        b <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    init();

    int t;
    cin >> t;
    while (t--) {
        double x;
        cin >> x;
        int bad = 0;
        REPP(i, 1, 8) {
            if (equal(x, pos[i])) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            cout << "-1" << endl;
        }
        else {
            int tmp = lower_bound(pos + 1, pos + 31, x) - pos;
            //cout << tmp << "hehe" << endl;
            tmp--;
            cout << 2 * (2 * tmp) << endl;
        }
    }


    return 0;
}

