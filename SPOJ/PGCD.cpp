#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

const int N = 1e7 + 5;
int vis[N], p[N], tot, mobius[N] = {0, 1};
int cnt[N], mcnt;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i, mobius[i] = -1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			mobius[i * p[j]] = -mobius[i];
			if (i % p[j] == 0) {
				mobius[i * p[j]] = 0;
				break;
			}
		}
	}
	for (int i = 1; i < N; i++) if (mobius[i]) {
		mcnt++;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			cnt[i * p[j]] += mobius[i];
		}
	}
	REPP(i, 1, N - 1) cnt[i] += cnt[i - 1];
}

int main() {
	ios :: sync_with_stdio(0);
	prime();
	//REP(i, 10) {
	//	cout << i << ' ' << p[i] << ' ' << mobius[i] << endl;
	//}
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int c = min(a, b);
		long long ans = 0;
		REPP(i, 1, c) {
			int pos1 = a / i, pos2 = b / i;
			int pos3 = a / pos1, pos4 = b / pos2;
			ans += 1LL * pos1 * pos2 * (cnt[min(pos3, pos4)] - cnt[i - 1]);
			i = min(pos3, pos4);
		}
		cout << ans << endl;
	}

	return 0;
}

