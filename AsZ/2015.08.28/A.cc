#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

set<string> all;

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        all.clear();
        string s, r;
        cin >> s >> r;
        cout << s << ' ' << r << endl;
        int n = s.size(), m = r.size();

        REP(i, n) {
            REPP(j, i, n - 1) {
                string ss = s.substr(i, j - i + 1);
                all.insert(ss);
                REP(k, m) {
                    REPP(l, k, m - 1) {
                        string rr = r.substr(k, l - k + 1);
                        all.insert(rr);
                        all.insert(ss + rr);
                    }
                }
            }
        }
        cout << all.size() + 1 << endl;
    }
    return 0;
}

