#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5;
string str = "QDM";
LL a[N];

bool check(int d, int l, int r) {
    REPP(i, l, r) if (a[i] % d != 0) return 0;
    return 1;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    srand(time(0) % clock());
    int t = 2;
    cout << t << endl;
    REP(i, t) {
        int n = 10000, m = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23;
        cout << n << ' ' << m << endl;
        REPP(i, 1, n) {
            a[i] = 1 << 29;
            cout << a[i] << ' ';
        }
        cout << endl;
        int q;
        q = 10000;
        cout << q << endl;
        REP(i, 9990) {
            int x, y;
            x = rand() % n + 1, y = rand() % n + 1;
            if (x > y) swap(x, y);
            int z = 2;
            cout << str[z] << ' ' << x << ' ' << y << ' ';
            if (z == 1) {
                int d = rand() % 30 + 1;
                while (!check(d, x, y)) {
                    d = rand() % 30 + 1;
                }
                cout << d << endl;
                REPP(i, x, y) a[i] /= d;
            }
            else if (z == 2) {
                int d = 1 << 29;
                cout << d << endl;
                REPP(i, x, y) a[i] *= d;
            }
            else {
                cout << endl;
            }
        }
        REP(i, 10) {
            int x = rand() % n + 1, y = rand() % n + 1;
            if (x > y) swap(x, y);
            if (i & 1) cout << 'Q' << ' ' << x << ' ' << y << endl;
            else {
                cout << "D" << ' ' << x << ' ' << y << ' ' << (1 << 29) << endl;
            }
        }
    }

    return 0;
}
