#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, t;
    cin >> n >> t;
    if (t == 10) {
        if (n == 1) {
            cout << -1 << endl;
        }
        else {
            REP(i, n - 1) {
                cout << 1;
            }
            cout << 0 << endl;
        }
    }
    else {
        REP(i, n) {
            cout << t;
        }
        cout << endl;
    }

    return 0;
}

