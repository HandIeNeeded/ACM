#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    srand(time(0) % clock());
    int t = 10;
    cout << t << endl;
    while (t--) {
        int n = rand() % 100000100 + 1;
        int m = rand() % 10000 + 1;
        cout << n << ' ' << m << endl;
        REP(i, m) {
            int x = rand() % 100000100 + 1, y = rand() % 100000100 + 1;
            cout << x << ' ' << y << endl;
        }
    }

    return 0;
}


