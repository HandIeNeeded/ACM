#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
const int MO = 1e9 + 7;
int fac[N], inv[N];

void init() {
	fac[0] = inv[0] = inv[1] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
	REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
	REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int dp[N], c[N];

int main() {
    ios :: sync_with_stdio(0);
	init();
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> c[i];
		c[i] += c[i - 1];
	}
	dp[1] = 1;
	REPP(i, 2, n) {
		int now = c[i] - c[i - 1];
		dp[i] = 1LL * dp[i - 1] * C(c[i - 1] + now - 1, c[i - 1]) % MO;
	}
	cout << dp[n] << endl;

    return 0;
}


