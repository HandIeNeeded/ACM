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
#define pb push_back
#define make make_pair

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 2e5 + 5;
LL prefix[N], suffix[N], a[N];

int main() {
	ios :: sync_with_stdio(0);
    int n, k, x;
    cin >> n >> k >> x;
    REPP(i, 1, n) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] | a[i];
    }
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1] | a[i];
    }
    LL tmp = 1;
    REP(i, k) tmp *= x;
    LL ans = 0;
    REPP(i, 1, n) {
        LL num = a[i] * tmp;
        ans = max(ans, prefix[i - 1] | num | suffix[i + 1]);
    }
    cout << ans << endl;


	return 0;
}

