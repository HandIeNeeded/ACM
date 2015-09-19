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
    REPP(i, 1, n) if (f[i] == i) {
        fix.push_back(i);
    }
    if (fix.size()) {
        cout << "YES" << endl;
        REPP(i, 1, n) if (i != fix[0]) {
            cout << i << ' ' << fix[0] << endl;
        }
        return 0;
    }
    int a = 0, b = 0;
    VP ans;
    int good = 1;
    REPP(i, 1, n) {
        if (f[f[i]] == i) {
            a = i, b = f[i];
            use[a] = use[b] = 1;
            break;
        }
    }
    if (!a || !b) good = 0;
    REPP(i, 1, n) {
        if (!use[i]) {
            int tmp = i;
            int cnt = 0;
            VI num;
            while (!use[tmp]) {
                num.push_back(tmp);
                use[tmp] = 1;
                cnt++;
                tmp = f[tmp];
            }
            if (cnt & 1) {
                good = 0;
                break;
            }
            else {
                REP(i, num.size()) {
                    if (i & 1) ans.push_back({a, num[i]});
                    else ans.push_back({b, num[i]});
                }
            }
        }
    }
    if (!good) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << a << ' ' << b << endl;
        REP(i, ans.size()) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }

	return 0;
}

