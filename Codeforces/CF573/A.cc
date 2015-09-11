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

const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

using namespace std;

const int N = 1e5 + 5;
int a[N];

bool test(int x) {
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    return x == 1;
}

int main() {
	ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    REPP(i, 1, n) cin >> a[i];
    int d = 0;
    REPP(i, 1, n) d = __gcd(d, a[i]);
    REPP(i, 1, n) a[i] /= d;
    REPP(i, 1, n) if (!test(a[i])) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;


	return 0;
}
