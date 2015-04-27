#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

vector<int> num;

void dfs(int now) {
	if (now > int(1e6)) return ;
	if (now <= int(1e6)) num.push_back(now);
	dfs(10 * now);
	dfs(10 * now + 1);
}

int dp[int(1e6 + 5)], pre[int(1e6 + 5)];
vector<int> ans;

void go(int n) {
	while(n) {
		ans.push_back(n - pre[n]);
		n = pre[n];
	}
}

int main() {
	ios :: sync_with_stdio(0);
	dfs(1);
	sort(num.begin(), num.end());
	int n;
	cin >> n;
	dp[0] = 0;
	REPP(i, 1, n) {
		dp[i] = 1e7;
		REP(j, num.size()) {
			if (i >= num[j]) {
				if (dp[i] > dp[i - num[j]] + 1) {
					dp[i] = dp[i - num[j]] + 1;
					pre[i] = i - num[j];
				}
			}
			else break;
		}
	}
	go(n);
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return 0;
}

