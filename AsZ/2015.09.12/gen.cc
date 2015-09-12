#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int T = 10000;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    srand(time(0) % clock());
    int t = 5;
    cout << t << endl;
    REP(i, t) {
        int n = T, m = T, d = rand() % 1000 + 1;
        cout << n << ' ' << m << ' ' << d << endl;
        while (d--) {
            int x = rand() % m + 1, y = rand() % m + 1;
            if (x > y) swap(x, y);
            cout << x << ' ' << y << endl;
        }
    }


    return 0;
}

