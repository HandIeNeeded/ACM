#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int N = 1e5 + 5;
long long a[N], s[N], n, k;
 
long long calculate(long long x) {
	return 1LL * x * (x + 1) >> 1;
}
 
int main() {
	ios :: sync_with_stdio(0);
 
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		REPP(i, 1, k) {
			cin >> a[i];
		}
		sort(a + 1, a + k + 1);
		REPP(i, 1, k) {
			s[i] = s[i - 1] + a[i];
		}
		long long ans = calculate(n) - s[k] + 1;
		REPP(i, 1, k) {
			long long x = a[i];
			long long y = calculate(x) - s[i] + 1;
			if (y == a[i]) {
				ans = a[i];
				//cout << i << endl;
				break;
			}
			//if (count(a + 1, a + k + 1, y)) {
			//	ans = y;
			//	break;
			//}
		}
		if (ans & 1) {
			cout << "Chef" << endl;
		}
		else {
			cout << "Mom" << endl;
		}
		//cout << ans << endl;
	}
	return 0;
}
