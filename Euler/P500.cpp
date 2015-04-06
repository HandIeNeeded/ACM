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

const int N = 1e7;
const int MO = 500500507;
const int M = 500500;
const long double EPS = 1e-9;
const int phi = 462000456;
int vis[N], p[N], tot, cnt[N];

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int pow_mod(int a, int b, int MO) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

int cmp(double x) {
	if (fabs(x) < EPS) return 0;
	else if (x > 0) return 1;
	return -1;
}

bool cmp(int i, int j) {
	return cmp(pow(2.0, cnt[j] - 1) * log(p[j]) - pow(2.0, cnt[i]) * log(p[i])) > 0;
}

int main() {
	clock_t st = clock();
	ios :: sync_with_stdio(0);
	prime();
	REP(i, M) cnt[i] = 1;
	for (int i = 0, j = M - 1; i < j && j >= 0; j--) {
		while (cnt[j] && cmp(i, j)) {
			cnt[i]++;
			cnt[j]--;
		}
		if (cnt[j] && !cmp(i, j)) i++, j++;
	}
	int ans = 1;
	REP(i, M) {
		ans = 1LL * ans * pow_mod(p[i], pow_mod(2, cnt[i], phi) - 1, MO) % MO;
	}
	cout << ans << endl;
	clock_t ed = clock();
	cout << fixed << setprecision(10) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;

	return 0;
}
