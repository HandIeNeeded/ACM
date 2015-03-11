#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int N = 1e5 + 5;
int a[N], b[N], c[N];
 
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
 
int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) cin >> a[i];
		int sum = 0;
		bool bad = 0;
		int tot = 0;
		REPP(i, 1, n) {
			sum += a[i];
			if (a[i] > 100) {
				bad = 1;
				break;
			}
			else if (a[i] == 0) {
				tot++;
			}
		}
		if (bad) {
			cout << "NO" << endl;
			continue;
		}
		if (sum >= 100 && sum < 100 + n - tot) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
 
	return 0;
}
