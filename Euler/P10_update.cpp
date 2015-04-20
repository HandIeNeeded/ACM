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

#define LL long long

const int N = 1e5 + 5;

int vis[N], p[N], tot;
LL prefix[N];

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
	REPP(i, 2, N - 1) {
		prefix[i] = prefix[i - 1];
		if (!vis[i]) prefix[i] += i;
	}
}

LL getsum(int n, int p) {
	if (p == 1) return 1LL * (n + 2) * (n - 1) / 2;
	else if (vis[p]) return getsum(n, p - 1);
	else if (1LL * p * p > n) return getsum(n, p - 1);
	else {
		LL ans = getsum(n, p - 1);
		ans -= (getsum(n / p, p - 1) - prefix[p - 1]) * p;
		return ans;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	clock_t st = clock(), ed;
	prime();
	cout << getsum(2e6, 2e3) << endl;
	ed = clock();
	cout << fixed << setprecision(10) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;

	return 0;
}

