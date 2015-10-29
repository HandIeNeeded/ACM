#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;
const int N = 105;
int ans[N], id[N], a[N], b[N];
bool use[N];
vector<int> mp[N][N];
map<int, int> g;

int main() {
	int m, n;
	cin >> m;
	n = int(sqrt(2 * m + 0.5)) + 1;
	assert(n * (n - 1) / 2 == m);
	REP(i, m) cin >> a[i], assert(a[i] > 0);
	REP(i, m) g[a[i]] = i;
	REP(i, m) {
		REPP(j, i + 1, m - 1) {
			int tmp = a[i] ^ a[j];
			if (g.count(tmp)) {
				tmp = g[tmp];
				mp[i][j].push_back(tmp);
				mp[j][i].push_back(tmp);
			}
		}
	}
	REP(i, m) {
		REPP(j, i + 1, m - 1) if (mp[i][j].size()) {
			REP(k, m) {
				if (k != mp[i][j][0] && mp[i][k].size() && mp[j][k].size()) {
					mp[i][j].push_back(k);
					mp[j][i].push_back(k);
				}
			}
		}
	}
	REP(i, m) {
		REPP(j, i + 1, m - 1) {
			assert(a[i] != a[j]);
		}
	}
	ans[0] = 0, ans[1] = a[0] ^ ans[0];
	int start = -1, cnt = 2;
	REP(i, m) {
		if (mp[0][i].size()) {
			id[cnt] = i;
			ans[cnt++] = a[i] ^ ans[0];
			int id = g[a[0] ^ a[i]];
			use[id] = 1;
			start = i;
			break;
		}
	}
	//REP(i, m) {
	//	REP(j, m) {
	//		cout << mp[i][j].size() << ' ';
	//	}
	//	cout << endl;
	//}
	while (cnt < n) {
		REP(i, mp[0][start].size()) {
			int y = mp[0][start][i];
			if (use[y]) continue;
			int good = 1;
			REP(i, cnt) {
				if (!mp[id[i]][y].size()) {
					good = 0;
					break;
				}
			}
			if (!good) continue;
			id[cnt] = y;
			ans[cnt++] = ans[0] ^ a[y];
			use[y] = 1;
			REP(i, cnt - 1) {
				use[g[a[id[i]] ^ a[id[cnt - 1]]]] = 1;
			}
			start = y;
			break;
		}
	}
	vector<int> A, B;
	REP(i, m) A.push_back(a[i]);
	REP(i, n) {
		REPP(j, i + 1, n - 1) {
			B.push_back(ans[i] ^ ans[j]);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	assert(A == B);
	REP(i, n) {
		cout << ans[i] << " \n"[i == n - 1];
	}
    return 0;
}
