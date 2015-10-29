#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int MO = 10007;

int get(int x) {
    int ans = 0;
    while (x) {
        x /= MO;
        ans += x;
    }
    return ans;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

const int N = MO;
int fac[N], inv[N];

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = fac[i - 1] * i % MO;
        inv[i] = MO - MO / i * inv[MO % i] % MO;
    }
}

int pow_mod(int a, int b, int mod = MO) {
    a %= mod; 
    if (a < 0) a += mod;
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int calc(int x) {
    if (x < MO) return fac[x];
    else {
        int k = x / MO, b = x % MO;
        if (k & 1) return MO - calc(k) * calc(b) % MO;
        else return calc(k) * calc(b) % MO;
    }
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    init();

    int n;
    cin >> n;
    int tot = get(n);
    int ans = 0;
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        int a = i, b = n / i;
        int cnt = 0, res = 0;
        REPP(i, 1, a) {
            cnt += get(b + a - i) - get(a - i);
        }
        if (tot == cnt) {
            res = calc(n);
            REPP(i, 1, a) {
                res = 1LL * res * calc(a - i) * inv[calc(b + a - i)] % MO;
            }
        }
        add(ans, res);
        if (a != b) {
            add(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}

