#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
const int MO = 998244353;
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

int pow_mod(int a, int b = MO - 2) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("figure.in", "r", stdin);
	//freopen("figure.out", "w", stdout);
	int n;
	init();
	while (cin >> n, n) {
		if (2 * n > N) {
			int tmp = 0;
			while (1) tmp++;
		}
		int ans = C(2 * n, n);
		ans = 1LL * ans * pow_mod(n + 1) % MO;
		cout << ans << endl;
	}
    return 0;
}

