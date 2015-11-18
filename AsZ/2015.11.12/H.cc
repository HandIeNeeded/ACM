#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
const string magic[2] = {"edHs", "fEHs"};

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);
    int k;
    cin >> k;
    string A = magic[0];
    string B = magic[1];
    REP(i, k) {
        string ans;
        REP(j, 10) {
            if (i & (1 << j)) {
                ans += A;
            }
            else {
                ans += B;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
