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

int vis[N], p[N], cnt[N], tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	prime();
	REPP(i, 1, 1e6) {
		cnt[i] = cnt[i - 1] + (vis[i] == 0);
	}
	int t, ca = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << "Case #" << ca++ << ": " << cnt[n] << endl;
	}

	return 0;
}

