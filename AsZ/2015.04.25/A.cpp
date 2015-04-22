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
#define LL long long

using namespace std;

vector<LL> ans[11];
int bit[20], cnt[10];

bool check(int tot, LL &tmp) {
	REP(i, tot) {
		int cnt = 0;
		REP(j, tot) if (bit[j] == i) {
			cnt++;
		}
		if (cnt != bit[i]) return 0;
	}
	REP(i, tot) tmp = 10 * tmp + bit[i];
	return 1;
}

void go(int tot, int now, int dep) {
	if (dep == tot - 1) {
		cnt[dep] = now;
		go(tot, 0, dep + 1);
		return ;
	}
	if (dep == tot) {
		REP(i, tot) {
			bit[i] = cnt[i];
		}
		LL tmp = 0;
		if (check(tot, tmp)) {
			ans[tot].push_back(tmp);
		}
	}
	else {
		REP(i, now + 1) {
			cnt[dep] = i;
			go(tot, now - i, dep + 1);
		}
	}
}

void init() {
	REPP(i, 1, 10) {
		go(i, i, 0);
		sort(ans[i].begin(), ans[i].end());
	}
}

int main() {
	ios :: sync_with_stdio(0);
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (ans[n].size() == 0) cout << -1 << endl;
		else {
			REP(i, ans[n].size()) {
				cout << ans[n][i] << " \n"[i == (int) ans[n].size() - 1];
			}
		}
	}

	return 0;
}

