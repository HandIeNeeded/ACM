#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 2e5 + 5;
PII p[N];

int dp[N << 2], ans[N];
int qx, qd, ql, qr;

void modify(int x, int l, int r) {
	if (l == r) {
		dp[x] = max(dp[x], qd);
	}
	else {
		if (qx <= MID) modify(LC);
		else modify(RC);
		dp[x] = max(dp[L], dp[R]);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return dp[x];
	}
	else {
		int ans = 0;
		if (ql <= MID) ans = max(ans, query(LC));
		if (qr > MID) ans = max(ans, query(RC));
		return ans;
	}
}

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> num;
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		num.push_back(x), num.push_back(y);
		p[i] = {y, x};
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	int tot = num.size() + 1;
	REP(i, n) {
		p[i].first = lower_bound(num.begin(), num.end(), p[i].first) - num.begin() + 2;
		p[i].second = lower_bound(num.begin(), num.end(), p[i].second) - num.begin() + 2;
	}
	sort(p, p + n);
	REP(i, n) {
		int j = i;
		while (j < n && p[j].first == p[i].first) {
			//cout << p[j].second << ' ' << p[j].first << endl;
			ql = 1, qr = p[j].second - 1;
			ans[j] = query(1, 1, tot) + 1;
			j++;
		}
		for (int k = i; k < j; k++) {
			qx = p[k].second, qd = ans[k];
			modify(1, 1, tot);
		}
		i = j - 1;
	}
	int res = 0;
	REP(i, n) res = max(res, ans[i]);
	cout << res << endl;

    return 0;
}


