#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
char op[3] = "@.";
char mp[2][N];

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);

    int b, w;
    cin >> b >> w;
    if (b > w) {
        swap(b, w);
        swap(op[0], op[1]);
    }
    int k = w - b;
    REP(i, k + 1) {
        mp[0][2 * i] = op[1];
        mp[0][2 * i + 1] = op[0];
        mp[1][2 * i] = mp[1][2 * i + 1] = op[0];
    }
    REP(i, b - 1) {
        mp[0][2 * k + 2 + 2 * i] = mp[1][2 * k + 2 + 2 * i] = op[1];
        mp[0][2 * k + 2 + 2 * i + 1] = mp[1][2 * k + 2 + 2 * i + 1] = op[0];
    }
    cout << 2 << ' ' << strlen(mp[0]) << endl;
    cout << mp[0] << endl << mp[1] << endl;

    return 0;
}


