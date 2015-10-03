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

    int t = 1, n;
    REP(i, t) {
        if (i == 1) n = 1;
        else n = 1000;
        cout << rand () % 5 + 1 << endl;
        REP(i, n) {
            cout << char(rand() % 26 + 'a');
        }
        cout << endl;
    }
    cout << 0 << endl;

    return 0;
}

