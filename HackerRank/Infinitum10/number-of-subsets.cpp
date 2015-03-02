#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MO = 1e9 + 7;
const int PHI = 1e9 + 6;

int pow_mod(int x, long long y, int mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		int inv = pow_mod(2, n, MO);
		inv = pow_mod(inv, MO - 2, MO);
		int tmp = pow_mod(2, n, PHI >> 1);
		if (tmp & 1) tmp += (PHI >> 1);
		cout << 1LL * pow_mod(2, tmp, MO) * inv % MO << endl;
	}

	return 0;
}
