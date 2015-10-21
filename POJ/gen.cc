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
    int t = 1;
    cout << t << endl;
    REP(i, t) {
        cout << rand() % 1000 + 1 << endl;
    }


    return 0;
}

