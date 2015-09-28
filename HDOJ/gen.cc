#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int M = 10;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    srand(time(0) % clock());

    int t = 1;
    cout << t << endl;
    REP(i, t) {
        int n = M;
        cout << n << endl;
        REP(j, n) {
            cout << rand() % 3 << ' ';
        }
        cout << endl;
    }

    return 0;
}

