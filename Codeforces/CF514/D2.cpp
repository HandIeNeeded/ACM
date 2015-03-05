#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int a[5][N], ans[5];
int n, m, k;

bool check(int mid) {
	deque<int> q[5];
	REPP(i, 1, n + 1) {
		if (i > mid) {
			int sum = 0;
			REP(j, m) {
				sum += a[j][q[j].front()];
				ans[j] = a[j][q[j].front()];
			}
			if (sum <= k) return 1;
		}
		if (i <= n) {
			REP(j, m) {
				while (q[j].size() && q[j].front() + mid - 1 < i) {
					q[j].pop_front();
				}
			}
			REP(j, m) {
				while (q[j].size() && a[j][q[j].back()] <= a[j][i]) {
					q[j].pop_back();
				}
				q[j].push_back(i);
			}
		}
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> m >> k;
	REPP(i, 1, n) {
		REP(j, m) {
			cin >> a[j][i];
		}
	}
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	if (l == 0) {
		REP(i, m) ans[i] = 0;
	}
	else {
		check(l);
	}
	REP(i, m) cout << ans[i] << " \n"[i == m - 1];

	return 0;
}
