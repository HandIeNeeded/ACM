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
		int n, m;
		cin >> n >> m;
		REPP(i, 1, n) cin >> a[i];
		b[0] = c[n + 1] = 0;
		REPP(i, 1, n) {
			b[i] = gcd(b[i - 1], a[i]);
			c[n + 1 - i] = gcd(c[n + 2 - i], a[n + 1 - i]);
		}
		REPP(i, 1, m) {
			int x, y;
			cin >> x >> y;
			cout << gcd(b[x - 1], c[y + 1]) << endl;
		}
	}
 
	return 0;
}
