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

const int N = 4005;
const int MO = 1e9 + 7;
int c[N][N], dp[N] = {1, 1}, fac[N] = {1, 1}, f[N] = {1};

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

void init() {
    REPP(i, 2, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
    REPP(i, 0, N - 1) {
        c[i][0] = c[i][i] = 1;
        REPP(j, 1, i - 1) {
            c[i][j] = c[i - 1][j];
            add(c[i][j], c[i - 1][j - 1]);
        }
    }
}

int main() {
	ios :: sync_with_stdio(0);
    init();
    int n;
    cin >> n;
    REPP(i, 2, n) {
        REPP(j, 1, i) {
            add(dp[i], 1LL * c[i - 1][j - 1] * dp[i - j] % MO);
        }
    }
    REPP(i, 1, n) {
        add(f[n], 1LL * c[n][i] * dp[n - i] % MO);
    }
    cout << f[n] << endl;
	return 0;
}
