#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = (1 << 18) + 5;
const int L = 20;
const int MO = 1e9 + 7;

int fac[N], finv[N], inv[N], a[N], pw[L];

void init() {
    pw[0] = 1;
    REPP(i, 1, L - 1) pw[i] = pw[i - 1] << 1;
    fac[0] = fac[1] = inv[1] = finv[0] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
    REPP(i, 1, N - 1) finv[i] = 1LL * inv[i] * finv[i - 1] % MO;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return 1LL * fac[x] * finv[y] % MO * finv[x - y] % MO;
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

int Inv(int x) {
    return pow_mod(x, MO - 2);
}

int sqr(int x) {
    return 1LL * x * x % MO;
}

int main() {
#ifdef HOME
    freopen("E.in", "r", stdin);
#endif

    init();
    int K, n;
    scanf("%d", &K);
    n = 1 << K;
    REPP(i, 1, n) scanf("%d", a + i);
    int ans = 0;
    REPP(i, 1, K) {
        int now = 1LL * sqr(fac[pw[K - i]]) * fac[n - pw[K - i + 1]] % MO;
        now = 2LL * now * pw[i - 1] % MO;
        int tmp = C(n - 2, pw[K - i] - 1);
        int res = 0;
        REPP(j, 2, n) {
            add(res, 1LL * a[j] * tmp % MO);
            tmp = 1LL * tmp * (n - j - pw[K - i] + 1) % MO * inv[n - j] % MO;
            if (tmp == 0) break;
        }
        int sum = res;
        //cout << "sum : " << sum << endl;
        int cof = C(n - 1 - pw[K - i], pw[K - i] - 1);
        res = 1LL * cof * res % MO;
        res = 1LL * a[1] * res % MO;
        add(ans, 1LL * res * now % MO);
        //cout << "ans " << ans << endl;
        tmp = C(n - 2, pw[K - i] - 1);
        cof = C(n - 2 - pw[K - i], pw[K - i] - 1);
        REPP(j, 2, n) {
            add(sum, MO - 1LL * a[j] * tmp % MO);
            int need = 1LL * sum * cof % MO;
            need = 1LL * need * a[j] % MO;
            //cout << need << endl;
            add(ans, 1LL * need * now % MO);
            tmp = 1LL * tmp * (n - j - pw[K - i] + 1) % MO * inv[n - j] % MO;
            if (n - j - pw[K - i] <= 0) cof = 0;
            else cof = 1LL * cof * (n - j - pw[K - i + 1] + 1) % MO * inv[n - j - pw[K - i]] % MO;
        }
        //cout << ans << endl;
    }
    //cout << ans << endl;
    ans = 1LL * ans * finv[n] % MO;
    cout << ans << endl;
    return 0;
}
//2
//1 2 3 4
//ans = 336/24 = (280 + 56) / 24

