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

int main() {
	ios :: sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int x = a / b - 1;
    if (x < 0) {
        cout << -1 << endl;
        return 0;
    }
    int k = ((a / b) - 1) >> 1;
    double p = 1.0 * (a + b) / (2 * k + 2);
    double q = 1.0 * (a - b) / (2 * k);
    cout << fixed << setprecision(12) << min(p, q) << endl;


	return 0;
}

