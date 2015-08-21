#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

long long multiple(long long a, long long b, long long p) {
	a %= p;
	long long ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % p;
		b >>= 1;
		a = (a + a) % p;
	}
	return ans;
}

long long pow_mod(long long a, long long b, long long p) {
	a %= p;
	long long ans = 1;
	while (b) {
		if (b & 1) ans = multiple(ans, a, p);
		b >>= 1;
		a = multiple(a, a, p);
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("zeroes.in", "r", stdin);
	freopen("zeroes.out", "w",stdout);

	long long k, p;
	cin >> k >> p;
	long long ans = k % p * pow_mod(10, k - 1, p) % p + k % p;
	ans %= p;
	long long tmp = pow_mod(10, k, 9 * p) - 1;
	tmp /= 9;
	tmp %= p;
	ans -= tmp;
	ans %= p;
	if (ans < 0) ans += p;
	cout << ans << endl;

	return 0;
}

