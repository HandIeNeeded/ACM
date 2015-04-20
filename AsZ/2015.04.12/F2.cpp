#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;
const int MO = 1e9 + 7;
int fac[N] = {1}, inv[N] = {1};

int pow_mod(int a, int b = MO - 2) {
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

int C(int x, int y) {
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int calc(int x, int n) {
	return 1LL * x * pow_mod(x - 1, n - 1) % MO;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	REPP(i, 1, int(1e6)) {
		fac[i] = 1LL * i * fac[i - 1] % MO;
		inv[i] = pow_mod(fac[i]);
	}
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n == 1) {
			int ans = 0;
			if (k == 1) {
				ans = m;
			}
			else ans = 0;
			cout << "Case #" << ca++ << ": " << ans << endl;
			continue;
		}
		int ans = 0;
		for (int i = k; i >= 1; i--) {
			int tmp = 1LL * C(k, i) * calc(i, n) % MO;
			if ((i - k) & 1) add(ans, MO - tmp);
			else add(ans, tmp);
		}
		for (int i = m; i > m - k; i--) {
			ans = 1LL * i * ans % MO;
		}
		ans = 1LL * ans * inv[k] % MO;
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

