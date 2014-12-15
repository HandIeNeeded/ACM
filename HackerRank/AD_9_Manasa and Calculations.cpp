#include <bits/stdc++.h> 

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

const int MOD = (int) 1e9 + 7;

int quick_pow(int a, int b) {
	int ans = 1;
	while(b) {
		if (b & 1) {
			ans = 1LL * ans * a % MOD;
		}
		b >>= 1;
		a = 1LL * a * a % MOD;
	}
	return ans;
}

int main() {
	int n;
	int ans = 1, mul = 1;
	cin >> n;
	int flag = 0;
	REPP(i, 1, n) {
		int p, a, b;
		cin >> p >> a >> b;
		if (a == b) {
			mul = 1LL * mul * quick_pow(p, a) % MOD;
			continue;
		}
		flag = 1;
		int tmp = (quick_pow(p, a) + quick_pow(p, b)) % MOD;
		ans = 1LL * ans * tmp % MOD;
	}
	ans = 1LL * ans * mul % MOD;
	if (!flag) {
		ans = 2 * ans % MOD;
	}
	cout << ans << endl;
	return 0;
}

