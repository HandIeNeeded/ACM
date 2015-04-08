#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;

vector<int> v[32];
int a[N];

int main() {
	ios :: sync_with_stdio(0);
	//freopen("tmp.in", "r", stdin);
	int ans = 0, n, m;
	cin >> n >> m;
	REPP(i, 1, n) cin >> a[i];
	REPP(i, 1, n) v[31].push_back(a[i]);
	for (int i = 31; i >= 1; i--) {
		int bit = 1 << (i - 1);
		if ((int) v[i].size() == m) {
			int cnt = 0;
			REP(j, v[i].size()) {
				if (v[i][j] & bit) {
					cnt++;
				}
			}
			if (cnt) ans += bit;
			v[i - 1] = v[i];
		}
		else {
			int cnt = 0;
			REP(j, v[i].size()) {
				if (v[i][j] & bit) {
					cnt++;
				}
			}
			if (cnt & 1) {
				ans += bit;
				v[i - 1] = v[i];
				continue;
			}
			REP(j, v[i].size()) {
				if (!(v[i][j] & bit)) {
					v[i - 1].push_back(v[i][j]);
				}
				else {
					int tmp = v[i][j];
					int pos = j + 1;
					while (!(v[i][pos] & bit)) {
						tmp ^= v[i][pos++];
					}
					tmp ^= v[i][pos];
					j = pos;
					v[i - 1].push_back(tmp);
				}
			}
			if ((int) v[i - 1].size() < m) {
				if (cnt) ans += bit;
				v[i - 1] = v[i];
			}
		}
	}
	cout << ans << endl;

	return 0;
}
