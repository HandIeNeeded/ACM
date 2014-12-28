#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int MOD = 1e9 + 7;

int sqr(int x) {
	 return x * x;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int cal(int l, int r, int d) {
	int ans = 1LL * (l + r) * (r - l + 1) / 2 % MOD;
	ans = 1LL * d * ans % MOD;
	return ans;
}


int main() {
	ios :: sync_with_stdio(0);

	int n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int m = sqrt(n);
		if (sqr(m + 1) == n) m++;
		if (sqr(n - 1) == n) m--;
		int ans = 0;
		REPP(i, 1, m) {
			int r = n / i;
			int l = n / (i + 1) + 1;
			add(ans, cal(l, r, i));
		}
		int start = n / (m + 1);
		for (int i = start; i >= 1; --i) {
			add(ans, n / i * i);
		}
		cout << ans << endl;
	}

	return 0;
}

