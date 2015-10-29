#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int MO = 105225319;
const int inv2 = (MO + 1) / 2;

int a[N], b[N], c[N];
int fac[N], inv[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void init() {
	fac[0] = inv[0] = inv[1] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
	REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
	REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
    return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

int main() {
#ifdef HOME
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    clock_t st = clock(), ed;
#endif

    int t, ca = 1;
    init();
    scanf("%d", &t);
    assert(t <= 50);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 1) {
            printf("Case #%d: %d\n", ca++, 0);
            continue;
        }
        assert(n <= 1000 && n >= 1);
        assert(m <= 1000 && m >= 1);
        MST(a, 0), MST(b, 0), MST(c, 0);
        REPP(i, 0, n) {
            REPP(j, 0, i) {
                add(a[i], 1LL * C(i, j) * pow_mod(m + 1, j * (i - j)) % MO);
            }
        }
        //REPP(i, 1, n) {
        //    cout << a[i] << ' ';
        //}
        //cout << endl;
        REPP(i, 0, n) {
            b[i] = a[i];
            REPP(j, 1, i - 1) {
                add(b[i], MO - 1LL * C(i - 1, j - 1) * b[j] % MO * a[i - j] % MO);
            }
        }
        //REPP(i, 1, n) {
        //    cout << b[i] << ' ';
        //}
        //cout << endl;
        REPP(i, 0, n) {
            if (i == 0) c[0] = 1;
            REPP(j, 1, i) {
                int tmp = 1LL * b[j] * inv2 % MO;
                add(c[i], 1LL * C(i - 1, j - 1) * tmp % MO * c[i - j] % MO);
            }
        }
        //REPP(i, 1, n) {
        //    cout << c[i] << ' ';
        //}
        //cout << endl;
        printf("Case #%d: %d\n", ca++, c[n]);
    }
#ifdef HOME 
    freopen("log", "w", stdout);
    ed = clock();
    printf("Time: %.10f\n", 1.0 * (ed -st) / CLOCKS_PER_SEC);
#endif

    return 0;
}
