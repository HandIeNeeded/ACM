#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
int fac[N], inv[N];

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
    REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
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

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(0);

    init();

    int t, ca = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans;
        if (n <= 2) {
            ans = 0;
        }
        else {
            int res = pow_mod(n, n);
            //circle == 0 be a leaf
            add(res, MO - pow_mod(n - 1, n));

            //circle == 1   
            add(res, MO - pow_mod(n - 1, n - 1));
            add(res, MO - 1LL * (n - 1) * pow_mod(n - 1, n - 2) % MO);

            //others > 1
            REPP(i, 2, n) {
                int tmp = 1LL * fac[n - 1] * inv[n - i] % MO;
                tmp = 1LL * tmp * pow_mod(n - 1, n - i) % MO;
                add(res, MO - tmp);
            }
            //cout << res << endl;

            ans = 1LL * res * n % MO;
        }
        cout << "Case #" << ca++ << ": " << ans << endl;
    }
    return 0;
}


