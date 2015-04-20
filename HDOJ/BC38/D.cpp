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

const int NN = 2e5 + 5;
const int N = 1005;
const int MO = 1e9 + 7;
int fac[NN] = {1}, inv[NN] = {1};
int dp[N];

int C(int x, int y) {
	if (x < y || x < 0 || y < 0) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

inline void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int go(int n, int m) {
	REPP(i, 0, n) dp[i] = 0;
	dp[0] = 1;
	REPP(i, 1, n) {
		REPP(j, 0, i - 1) {
			int tmp = 1LL * C(i - 1, i - j - 1) * C(m + i - j - 1, i - j) % MO * dp[j] % MO;
			add(dp[i], tmp);
		}
	}
	return dp[n];
}

int main() {
	int t, ca = 1;
	REPP(i, 1, 120000) {
		fac[i] = 1LL * fac[i - 1] * i % MO;
	}
	inv[0] = inv[1] = 1;
	REPP(i, 2, 120000) inv[i] = 1LL * (MO - MO / i) * inv[MO % i] % MO;
	REPP(i, 1, 120000) inv[i] = 1LL * inv[i - 1] * inv[i] % MO;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case #%d: %d\n", ca++, go(n, m));
	}

	return 0;
}

