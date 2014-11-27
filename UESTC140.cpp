#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1005;
const int MOD = (int) 1e9 + 7;
const int INV = 166666668;
int a[N], n, m;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int cal(int st, int ed, int d, int head) {
	return 1LL * (head + (ed - st) * d + head) * (ed - st + 1) / 2 % MOD;
}	

int getone() {
	int ans = 0;
	REP(i, m) {
		int x = a[i];
		if (x & 1) {
			add(ans, cal(1, x >> 1, 1, 0));
			add(ans, cal(x / 2 + 1, x - 1, -1, x / 2 - 1));
		}
		else {
			add(ans, cal(1, x >> 1, 1, 0));
			add(ans, cal(x / 2 + 1, x - 1, -1, x / 2 - 2));
		}
		
		add(ans, cal(x + 1, min(2 * x - 1, n), -1, x - 2));
		add(ans, cal(x + 1, min(2 * x, n), 1, 0));
		if (n > 2 * x) {
			add(ans, cal(2 * x + 1, n, 0, x - 1));
		}
	}
	return ans;
}

int gettwo() {
	int ans = 0;
	REP(i, m) REPP(j, i + 1, m - 1) {
		int tot = min(n, a[i] + a[j] - 1) - (a[j] - a[i] + 1) + 1;
		if (a[i] >= a[j] - a[i] + 1) tot--;
		tot--;
		add(ans, tot);
	}
	return ans;
}

int getthree() {
	int ans = 0;
	REP(i, m) REPP(j, i + 1, m - 1) {
		int pos = upper_bound(a, a + m, a[i] + a[j] - 1) - a;
		add(ans, pos - j - 1);
	}
	return ans;
}

int main() {
	//freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	int T, ca = 1;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		REP(i, m) cin >> a[i];
		sort(a, a + m);
		int ans = 1LL * n * (n - 1) % MOD * (n - 2) % MOD * INV % MOD, tot = 0;

		int k = n >> 1;
		int k1, k2;
		if (n & 1) {
			k1 = k, k2 = k;
		}
		else {
			k1 = k - 1, k2 = k;
		}
		add(tot, 1LL * k1 * (k1 + 1) % MOD * (2 * k1 + 1) % MOD * INV % MOD);
		add(tot, 1LL * k2 * (k2 + 1) % MOD * (2 * k2 + 1) % MOD * INV % MOD);
		add(tot, MOD - 1LL * k2 * (k2 + 1) / 2 % MOD);

		add(ans, MOD - tot);
		add(ans, MOD - getone());

		if (m >= 2) {
			add(ans, gettwo());
		}
		
		if (m >= 3) {
			add(ans, MOD - getthree());
		}
		cout << "Case " << ca++ << ": " << ans << endl;
	}



	return 0;
}