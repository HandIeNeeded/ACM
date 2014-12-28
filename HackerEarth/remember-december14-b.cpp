#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

LL getodd(int x) {
	return 1LL * (x + 1) * (x + 1);
}

LL geteven(int x) {
	return 1LL * x * (x + 2);
}

void getans(int &x, int &y, LL n) {
	int l = 0, r = 1e8;
	
	while (l + 1 < r) {
		int mid = l + r >> 1;
		int tmp = 2 * mid + 1;
		if (getodd(tmp) + geteven(tmp + 1) <= n) {
			l = mid;
		}
		else r = mid;
	}
	x = 2 * l + 1;
	y = 2 * l + 2;

	l = 0, r = 1e8;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		int tmp = 2 * mid;
		if (getodd(tmp + 1) + geteven(tmp) <= n) {
			l = mid;
		}
		else r = mid;
	}

	x = max(x, 2 * l);
	y = max(y, 2 * l + 1);
}

int main() {
	ios :: sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		if (n < 12) {
			cout << "0 0" << endl;
			continue;
		}
		int a, b;
		getans(a, b, n);
		if (b & 1) swap(a, b);
		cout << a << ' ' << b << endl;	
	}

	return 0;
}

