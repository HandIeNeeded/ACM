#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2020;
const int INF = 0x3f3f3f3f;

string pname[N << 1];
int dp[N][N];
pair<int, int> p[N][N];
vector<pair<int, int> > boy, girl;
vector<vector<int> > ans;

void go(int n, int m) {
	while (p[n][m].first || p[n][m].second) {
		int x = p[n][m].first, y = p[n][m].second;
		vector<int> tmp;
		REPP(i, n, x - 1) tmp.push_back(boy[i].second);
		REPP(i, m, y - 1) tmp.push_back(girl[i].second);
		ans.push_back(tmp);
		n = x, m = y;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("taxi.in", "r", stdin);

	int n, m;
	int now = 0;
	cin >> n;
	REP(i, n) {
		pair<int, int> tmp;
		cin >> pname[i] >> tmp.first;
		tmp.second = now++;
		boy.push_back(tmp);
	}
	cin >> m;
	REP(i, m) {
		pair<int, int> tmp;
		cin >> pname[now] >> tmp.first;
		tmp.second = now++;
		girl.push_back(tmp);
	}
	sort(boy.begin(), boy.end());
	sort(girl.begin(), girl.end());
	MST(dp, 0x3f);
	dp[n][m] = 0;
	for (int i = n; i >= 1; --i) {
		for (int j = m; j >= 0; --j) {
			if (!i && !j) break;
			if (i + j < 4) {
				int cost = boy[i - 1].first;
				if (j) cost = max(cost, girl[j - 1].first);
				if (dp[0][0] > dp[i][j] + cost) {
					dp[0][0] = dp[i][j] + cost;
					p[0][0] = {i, j};
				}
			}
			REPP(k, 1, 4) {
				if (3 * (i - k) < j - (4 - k)) continue;
				if (i >= k && 4 - k <= j) {
					int cost = boy[i - 1].first;
					if(j && k < 4) {
						cost = max(cost, girl[j - 1].first);
					}
					if (dp[i - k][j - (4 - k)] > dp[i][j] + cost) {
						dp[i - k][j - (4 - k)] = dp[i][j] + cost;
						p[i - k][j - (4 - k)] = {i, j};
					}
				}
			}
		}
	}
	//REPP(i, 0, n) {
	//	REPP(j, 0, m) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	go(0, 0);
	cout << dp[0][0] << endl;
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << "Taxi " << i + 1 << ": ";
		REP(j, ans[i].size()) {
			cout << pname[ans[i][j]];
			if (j == (int) ans[i].size() - 2) {
				cout << " and ";
			}
			else if (j == (int) ans[i].size() - 1) {
				cout << "." << endl;
			}
			else {
				cout << ", ";
			}
		}
	}

	return 0;
}
