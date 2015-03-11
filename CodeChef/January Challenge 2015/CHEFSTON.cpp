#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
using namespace std;
 
const int N = 1e5 + 5;
int a[N], b[N];
 
int main() {
	long long ans = 0;
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		ans = 0;
		REPP(i, 1, n) {
			cin >> a[i];
		}
		REPP(i, 1, n) {
			cin >> b[i];
		}
		REPP(i, 1, n) {
			ans = max(ans, 1LL * m / a[i] * b[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
