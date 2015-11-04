#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
string s[N];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    REP(i, n) cin >> s[i];
    int ans = 0;
    REP(i, 26) REPP(j, i + 1, 25) {
        int res = 0;
        REP(k, n) {
            int bad = 0;
            REP(t, s[k].size()) {
                if (s[k][t] != 'a' + i && s[k][t] != 'a' + j) {
                    bad = 1;
                }
            }
            if (!bad) res += s[k].size();
        }
        ans = max(ans, res);
    }
    cout << ans << endl;


    return 0;
}


