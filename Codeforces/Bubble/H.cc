#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e6 + 5;
//int dp[N][N], vis[N][N];

//int dfs(int x, int y) {
//    if (vis[x][y]) return dp[x][y];
//    if (x == 0 || y == 0) return x + y + 1;
//    else {
//        vis[x][y] = 1;
//        dp[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
//        dp[x][y]++;
//        return dp[x][y];
//    }
//}

const int MO = 1e9 + 7;

int fac[N], inv[N];

void init() {
	fac[0] = inv[0] = inv[1] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
	REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
	REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
    return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    //REPP(i, 1, 5) {
    //    dfs(i, i);
    //    cout << dp[i][i] << endl;
    //}
    init();
    int n;
    cin >> n;
    n += 1;
    int ans = C(2 * n, n);
    add(ans, MO - 1);
    cout << ans << endl;

    return 0;
}

