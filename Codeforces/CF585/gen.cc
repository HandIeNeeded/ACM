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
    int n = 200;
    cout << n << endl;
    REPP(i, 1, n) {
        cout << rand() % int(1e7) + 1 << ' ' ;
    }
    cout << endl;


    return 0;
}


