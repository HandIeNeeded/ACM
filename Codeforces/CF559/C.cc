#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
const int MO = 1e9 + 7;
pair<int, int> p[N];

int fac[N], inv[N], dp[N];

void init() {
    fac[0] = inv[0] = inv[1] = 1;
    REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
    REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int get(int a, int b) {
    return C(p[a].first - p[b].first + p[a].second - p[b].second, p[a].first - p[b].first);
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    init();

    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    p[++n] = {h, w};
    sort(p + 1, p + n + 1);
    REPP(i, 1, n) {
        dp[i] = C(p[i].first + p[i].second - 2, p[i].first - 1);
        REPP(j, 1, i - 1) {
            add(dp[i], MO - 1LL * dp[j] * get(i, j) % MO);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

