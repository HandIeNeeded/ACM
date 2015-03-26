#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
int a[N], b[N], c[N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("knockout.in", "r", stdin);
	freopen("knockout.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) cin >> a[i] >> b[i];
	REPP(i, 1, n) c[i] = abs(a[i] - b[i]) << 1;
	while (m--) {
		int l, r, t;
		cin >> l >> r >> t;
		int cnt = 0;
		REPP(i, 1, n) {
			int tmp = t;
			tmp %= c[i];
			int dir = b[i] - a[i] > 0 ? 1 : -1;
			if (tmp <= (c[i] >> 1)) {
				int ans = a[i] + dir * tmp;
				if (ans >= l && ans <= r) {
					cnt++;
				}
			}
			else {
				int ans = b[i] - dir * (tmp - (c[i] >> 1));
				if (ans >= l && ans <= r) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}


