#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define debug(x) cout << #x << "is: " << x << endl

#define FI first
#define SE second
#define VI vector<int>
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define make make_pair

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 1e5 + 5;
int f[N], use[N];

int main() {
	ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> f[i];  
    vector<int> fix;
    vector<PII> ans;
    REPP(i, 1, n) if (f[i] == i) {
        fix.push_back(i);
    }
    int bad = 0;
    REPP(i, 1, n) if (f[i] != i && !use[i]) {
        if (f[f[i]] == i) {
            ans.push_back({i, f[i]});
            use[i] = use[f[i]] = 1;
        }
        else {
            bad = 1;
            break;
        }
    }

    if (bad) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        if (fix.size()) {
            REP(i, fix.size() - 1) {
                cout << fix[0] << ' ' << fix[i + 1] << endl;
            }
            REP(i, ans.size()) {
                cout << fix[0] << ' ' << ans[i].first << endl;
                cout << fix[0] << ' ' << ans[i].second << endl;
            }
        }
        else {
            int pa, pb;
            tie(pa, pb) = ans[0];
            cout << pa << ' ' << pb << endl;
            REPP(i, 1, ans.size() - 1) {
                int a, b;
                tie(a, b) = ans[i];
                cout << a << ' ' << pa << endl;
                cout << b << ' ' << pb << endl;
            }
        }
    }

	return 0;
}

