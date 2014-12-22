#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long
 
using namespace std;
 
LL check(LL x) {
	return 2 * x * (x + 1) + 1;
}
 
void getans(LL d, LL n) {
	if (n == check(d)) {
		cout << d << ' ' << 0 << endl;
		return ;
	}
	else {
		n -= check(d);
		d++;
		if (n > 2 * d + 1) {
			n -= 2 * d + 1;
			LL tmp = (n + 1) / 2;
			if (n & 1) {
				cout << tmp << ' ' << -(d - tmp) << endl;
			}
			else {
				cout << tmp << ' ' << (d - tmp) << endl;
			}
			return ;
		}
		else {
			LL tmp = n / 2;
			if (n & 1) {
				cout << (-d + tmp) << ' ' << tmp << endl;
			}
			else {
				cout << (-d + tmp) << ' ' << -tmp << endl;
			}
			return ;
		}
	}
}
 
int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		LL l = 0, r = (LL) 1e9;
		while (l + 1 < r) {
			LL mid = l + r >> 1;
			if (check(mid) > n) r = mid;
			else {
				l = mid;
			}
		}
		getans(l, n);
	}
 
	return 0;
}
