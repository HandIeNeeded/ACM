#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = (1 << 18) + 5;
const int K = 20;
const int MO = 1e9 + 7;
const int Inv = (1 + MO) / 2;

int a[N], fac[N], inv[N], p[N][K];

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
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

int sqr(int x) {
    return 1LL * x * x % MO;
}

int pow_mod(int a, int b, int mod = MO) {
    a %= mod; 
    if (a < 0) a += mod;
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

int k, n;

int get(int i, int j) {
    int need = 1 << j;
    return 1LL * C(n - i, need - 1) * pow_mod(C(n - 1, need - 1), MO - 2) % MO;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    init();

    scanf("%d", &k);
    n = 1 << k;
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) p[i][0] = 1;
    int ans = 0;
    REPP(turn, 1, k) {
        int sum = 0, tot = 0;
        REPP(i, 1, n) {
            add(sum, 1LL * p[i][turn - 1] * a[i] % MO);
            add(tot, sqr(1LL * p[i][turn - 1] * a[i] % MO));
        }
        int tmp = sqr(sum);
        add(tmp, MO - tot);
        tmp = 1LL * tmp * Inv % MO;
        tmp = 1LL * tmp * pow_mod(2, k - turn) % MO * pow_mod(C(1 << (k - turn + 1), 2), MO - 2) % MO;
        add(ans, tmp);
        REPP(i, 1, n) {
            p[i][turn] = get(i, turn);
        }
    }
    cout << ans << endl;

    return 0;
}

