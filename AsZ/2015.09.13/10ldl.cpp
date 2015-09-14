#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;

LL a[N], mod[N]; //x == a[i] (mod mod[i]), i = 0, 1, ... , n - 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

void add(LL &x, LL y, LL M) {
    x += y;
    if (x >= M) x -= M;
}

LL mul(LL x, LL y, LL M) {
    LL ans = 0;
    while (y) {
        if (y & 1) add(ans, x, M);
        add(x, x, M);
        y >>= 1;
    }
    return ans;
}

LL china (LL n, LL *a, LL *mod){// i = 0, 1, ... , n - 1
	LL re = 0, M = 1;
	REP(i, n) M *= mod[i];
	REP(i, n) {
		LL d, x, y;
		exgcd(M / mod[i], mod[i], d, x, y);
        LL tmp = mul(x, M / mod[i], M);
        tmp = mul(tmp, a[i], M);
        add(re, tmp, M);
	}
	return (re + M) % M;
}

int x[N], y[N], xx, yy;

const int M = 1e5 + 5;
int fac[M], inv[M];

int C(int x, int y, int p) {
    if (x < y || y < 0 || x < 0) return 0;
    return 1LL * fac[x] * inv[y] % p * inv[x - y] % p;
}

int calc(LL n, LL m, int p) {
	fac[0] = inv[0] = inv[1] = 1;
	REPP(i, 1, p - 1) fac[i] = 1LL * i * fac[i - 1] % p;
	REPP(i, 2, p - 1) inv[i] = p - 1LL * p / i * inv[p % i] % p;
	REPP(i, 1, p - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % p;

    xx = yy = 0;
    while (n) {
        x[xx++] = n % p;
        n /= p;
    }
    while (m) {
        y[yy++] = m % p;
        m /= p;
    }
    int mx = max(xx, yy);
    int ans = 1;
    REP(i, mx) {
        ans = 1LL * ans * C(x[i], y[i], p) % p;
    }
    return ans;
}

int main() {
//#ifdef HOME
    freopen("10.in", "r", stdin);
//#endif
//#ifdef ONLINE_JUDGE
//#define lld I64d
//#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        LL n, m;
        int k;
        scanf("%lld%lld", &n, &m);
        scanf("%d", &k);
        REP(i, k) scanf("%lld", mod + i);
        REP(i, k) {
            a[i] = calc(n, m, mod[i]);
        }
        LL ans = china(k, a, mod);
        printf("%lld\n", ans);
    }


    return 0;
}

