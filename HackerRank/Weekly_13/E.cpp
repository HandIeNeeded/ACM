#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
const int MO = 1e9 + 7;

int a[N], fac[N], inv[N];
char s[10];

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

void init() {
	fac[0] = inv[0] = 1;
	REPP(i, 1, 2e5) {
		fac[i] = 1LL * i * fac[i - 1] % MO;
		inv[i] = pow_mod(fac[i], MO - 2);
	}
}

int toInt(char *s) {
	if (s[0] == '?') return -1;
	else {
		int n = strlen(s);
		int ans = 0;
		REP(i, n) {
			ans = ans * 10 + s[i] - '0';
		}
		return ans;
	}
}

int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int solve(int x, int y) {
	int l = a[x], r = a[y];
	int ans = 0;
	add(ans, C(l - r + 2 * (y - x) - 1, y - x - 1));
	add(ans, MO - C(l - r + 2 * (y - x) - 1, l + y - x));
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("E.in", "r", stdin);

	init();
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> s;
		a[i] = toInt(s);
	}
	a[++n] = 1;
	int ans = 1;
	REPP(i, 1, n) {
		if (i == 1) {
			if (a[i] > 0) {
				cout << 0 << endl;
				return 0;
			}
			else a[1] = 0;
		}
		int j = i + 1;
		while (j <= n && a[j] == -1) {
			j++;
		}
		if (j <= n) ans = 1LL * ans * solve(i, j) % MO;
		else break;
		i = j - 1;
	}
	cout << ans << endl;
	return 0;
}
