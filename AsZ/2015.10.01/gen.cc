#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int M = 100;
const int N = 1005;

int vis[N][N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    srand(time(0) % clock());

    int t;
    t = 1;
    REP(i, t) {
        int n = rand() % M + 2;
        cout << n << endl;
        REPP(i, 1, n) {
            cout << rand() % 100000 << ' ';
        }
        cout << endl;
    }

    return 0;
}


