#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MO = 1e9 + 7;
const int inv = (MO + 1) >> 1;
const int N = 1e5 + 5;

int a[N], b[N];

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

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) {
            scanf("%d%d", a + i, b + i);
        }
        int Inv = pow_mod(inv, n), Mul = pow_mod(2, n);
        int A = pow_mod(2, 2 * n - 1), B = pow_mod(inv, n + 1);
        int sumA = 0, sumB = 0, sumC = 0, sumD = 0, ans = 0;
        for (int i = n; i >= 1; i--) {
            int tmp = 1LL * A * a[i] % MO * sumA % MO;
            add(ans, tmp);
            tmp = 1LL * B * b[i] % MO * sumB % MO;
            add(ans, tmp);
            tmp = 1LL * B * a[i] % MO * sumC % MO;
            add(ans, MO - tmp);
            tmp = 1LL * A * b[i] % MO * sumD % MO;
            add(ans, MO - tmp);
            add(sumA, 1LL * b[i] * Inv % MO);
            add(sumB, 1LL * a[i] * Mul % MO);
            add(sumC, 1LL * b[i] * Mul % MO);
            add(sumD, 1LL * a[i] * Inv % MO);
            Inv = 2LL * Inv % MO;
            Mul = 1LL * inv * Mul % MO;
            A = 1LL * inv * A % MO;
            B = 2LL * B % MO;
        }
        printf("%d\n", ans);
    }
    return 0;
}

