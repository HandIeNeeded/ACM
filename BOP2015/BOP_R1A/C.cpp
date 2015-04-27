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

const int N = 5e5 + 5;
int vis[N], p[N], tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int a[N], cnt, b[N];

bool check() {
	REP(i, cnt) {
		REPP(j, i + 1, cnt - 1) {
			if (b[i] % b[j] == 0) {
				if (!vis[b[i] / b[j]]) return 0;
			}
			if (b[j] % b[i] == 0) {
				if (!vis[b[j] / b[i]]) return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	vis[1] = 1;
	prime();
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REP(i, n) cin >> a[i];
		int ans = 0;
		REP(i, 1 << n) {
			cnt = 0;
			REP(j, n) if (i & (1 << j)) {
				b[cnt++] = a[j];
			}
			if (cnt < ans) continue;
			if (check()) ans = cnt;
		}
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

