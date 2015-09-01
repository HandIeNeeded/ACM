#include <bits/stdc++.h>

#define g 5
#define N 2005
#define MOD 258280327

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int dp[N][N], ans[N];
int a[N * 3], b[N * 3];
int jc[N], invj[N];
int pm[N], qm[N];

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int pow_mod(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

void change(int *x, int len) {
	int u, j;
	u = j = len / 3;
	for (int i = 1; i < len - 1; i++) {
		if (i < j) swap(x[i], x[j]);
		int k = u;
		while (j >= k * 2) {
			j -= k * 2;
			k /= 3;
		}
		j += k;
	}
}

void ntt(int *x, int len, int ty) {
	change(x, len);
	for (int h = 3; h <= len; h *= 3) {
		int l = h / 3;
		int G = pow_mod(g, (MOD - 1) / h);
		for (int i = 0; i < len; i += h) {
			int n1, n2, n3;
			n3 = (n2 = (n1 = i) + l) + l;
			int g1, g2;
			g1 = g2 = 1;
			int G1 = pow_mod(G, l);
			int G2 = pow_mod(G, 2 * l);
			for (int j = 0; j < l; j++) {
				int u1 = x[n1 + j];
				int u2 = x[n2 + j];
				int u3 = x[n3 + j];
				x[n1 + j] = add(u1, add(mul(g1, u2), mul(g2, u3)));
				x[n2 + j] = add(u1, add(mul(G1, mul(g1, u2)), mul(G2, mul(g2, u3))));
				x[n3 + j] = add(u1, add(mul(G2, mul(g1, u2)), mul(G1, mul(g2, u3))));
				g1 = mul(g1, G);
				g2 = mul(g2, mul(G, G));
			}
		}
	}
	if (ty == -1) {
		for (int i = 1; i <= len / 2; i++) swap(x[i], x[len - i]);
		int inv = pow_mod(len, MOD - 2);
		for (int i = 0; i < len; i++) x[i] = mul(x[i], inv);
	}
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    clock_t st = clock();
    int hehe;

    jc[0] = 1, invj[0] = 1;
    for (int i = 1; i < N; i++) {
        jc[i] = mul(jc[i - 1], i);
        invj[i] = pow_mod(jc[i], MOD - 2);
    }

    int ca;
    scanf("%d", &ca);
    while (ca--) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        x %= MOD, y %= MOD;
        int p, q;
        p = mul(x, pow_mod(y, MOD - 2));
        q = 1 - p, q = add(q, MOD);

        qm[0] = 1;
        for (int i = 1; i <= n; i++) qm[i] = mul(qm[i - 1], q);
        pm[0] = 1;
        for (int i = 1; i <= n; i++) pm[i] = mul(pm[i - 1], p);

        int len = 1;
        while (n * 2 >= len) len *= 3;

        for (int i = 0; i < len; i++) b[i] = 0;
        for (int i = 0; i < n; i++) b[len - 1 - i] = mul(pm[i], invj[i]);
        ntt(b, len, 1);

        REPP(i, 0, n) {
            REPP(j, 0, n) {
                dp[i][j] = 0;
            }
        }
        dp[0][n] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < len; j++) a[j] = 0;
            for (int j = 0; j <= n - i + 1; j++) a[j] = mul(dp[i - 1][j], jc[j - 1]);
            ntt(a, len, 1);
            for (int j = 0; j < len; j++) a[j] = mul(a[j], b[j]);
            ntt(a, len, -1);
            for (int j = 0; j <= n - i; j++) dp[i][j] = mul(a[j], mul(qm[j], invj[j]));
        }
        REPP(i, 0, n - 1) ans[i] = 0;
        REPP(i, 0, n - 1) {
            REPP(j, 1, n) {
                ans[i] = add(ans[i], dp[i][j]);
            }
        }
        int invn = pow_mod(n, MOD - 2);
        REPP(i, 0, n - 1) {
            printf("%d%c", 1LL * ans[i] * invn % MOD, " \n"[i == n - 1]);
        }
    }
    clock_t ed = clock();
#ifdef HOME
    cout << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
