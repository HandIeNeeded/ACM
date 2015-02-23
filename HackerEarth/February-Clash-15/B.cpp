#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
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

int calc(int n, int i) {
	int tmp = p[i];
	if (tmp * tmp >= n) return 0;
	int lim = n / tmp;
	lim = min(1000000, lim);
	int pos = upper_bound(p, p + tot, lim) - p;
	return pos - i - 1;
}

int get(int l, int r) {
	int ans = 0;
	for (int i = 0; i < tot && p[i] * p[i] < r; i++) {
		ans += calc(r, i) - calc(l - 1, i);
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	prime();
	int t;
	cin >> t;
	while (t--) {
		int L, R;
		cin >> L >> R;
		cout << get(L, R) << endl;
	}

	return 0;
}
