#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
const int MO = 1e9 + 7;
int f[N], g[N], h[N], a[N], b[N], c[N];
int fac[N], inv[N];

int C(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
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

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, 1000) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
    REPP(i, 1, 1000) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;

    //Connected
    REPP(i, 1, 1000) h[i] = g[i] = pow_mod(2, i * (i - 1) / 2);
    REPP(i, 1, 1000) {
        REPP(j, 1, i - 1) {
            int tmp = 1LL * C(i - 1, j - 1) * h[j] % MO * g[i - j] % MO;
            add(h[i], MO - tmp);
        }
    }
    
    //Eulerian
    REPP(i, 1, 1000) f[i] = g[i] = pow_mod(2, (i - 1) * (i - 2) / 2);
    REPP(i, 1, 1000) {
        REPP(j, 1, i - 1) {
            int tmp = 1LL * C(i - 1, j - 1) * f[j] % MO * g[i - j] % MO;
            add(f[i], MO - tmp);
        }
    }

    //Biparitite
    REPP(i, 1, 1000) {
        REPP(j, 0, i) {
            add(a[i], 1LL * C(i, j) * pow_mod(2, j * (i - j)) % MO);
        }
        b[i] = a[i];
    }
    REPP(i, 1, 1000) {
        REPP(j, 1, i - 1) {
            int tmp = 1LL * C(i - 1, j - 1) * b[j] % MO * a[i - j] % MO;
            add(b[i], MO - tmp);
        }
    }
    int inv = (MO + 1) >> 1;
    c[0] = 1;
    REPP(i, 1, 1000) {
        REPP(j, 1, i) {
            add(c[i], 1LL * C(i - 1, j - 1) * b[j] % MO * inv % MO * c[i - j] % MO);
        }
    }
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("Connected: %d\n", h[n]);
        printf("Eulerian: %d\n", f[n]);
        printf("Bipartite: %d\n", c[n]);
        puts("");
    }
    return 0;
}

