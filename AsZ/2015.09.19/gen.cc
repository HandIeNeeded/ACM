#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e5 + 5;
const int M = 200000;

int main() {
	ios :: sync_with_stdio(0);
    //freopen("tmp.in", "w", stdout);
	srand(time(0) % clock());
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = M, m = M / 4;
        cout << n << ' ' << m << endl;
        REPP(i, 1, m) {
            int type = rand() % 3 + 1;
            cout << type << ' ';
            if (type <= 2) {
                if (type == 1) {
                    int x = rand() % (2 * n - 1) + 2, y = rand() % (2 * n - 1) + 2;
                    if (x > y) swap(x, y);
                    cout << x << ' ' << y << endl;
                }
                else {
                    int x = n - 1 - rand() % (2 * n - 1), y = n - 1 - rand() % (2 * n - 1);
                    if (x > y) swap(x, y);
                    cout << x << ' ' << y << endl;
                }
            }
            else {
                int a = rand() % n + 1, b = rand() % n + 1;
                int c = rand() % n + 1, d = rand() % n + 1;
                if (a > b) swap(a, b);
                if (c > d) swap(c, d);
                cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
            }
        }
    }
	return 0;
}

