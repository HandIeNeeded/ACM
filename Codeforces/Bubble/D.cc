#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    cout << 1996 << endl;
    REPP(i, 2, 999) {
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    }
    for (int i = 999; i >= 2; i--) {
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    }

    return 0;
}

