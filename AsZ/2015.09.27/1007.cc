#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MO = 1e9 + 7;

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int Inv(LL x) {
    x %= MO;
    return pow_mod(x, MO - 2);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int b1, q, a1, d, n, m;
        scanf("%d%d%d%d%d%d", &b1, &q, &a1, &d, &n, &m);
        q %= MO, d %= MO, b1 %= MO, a1 %= MO;
        int ans = 0;
        int inv = MO - Inv(q - 1);
        int C = 1;
        LL s = 1LL * n + m - 2, r = n - 1;
        REP(i, n - 1) {
            C = 1LL * C * s % MO * Inv(r) % MO;
            s--, r--;
        }
        REPP(i, 1, n) {
            int tmp = a1;
            add(tmp, 1LL * b1 * inv % MO % MO);
            add(ans, 1LL * tmp * C % MO);
            add(a1, d);
            b1 = 1LL * b1 * q % MO * (MO - inv) % MO;
            C = 1LL * C * (n - i) % MO * Inv(n - 1LL + m - i) % MO;
        }
        add(ans, 1LL * b1 * pow_mod(q, m - 1) % MO);
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}

