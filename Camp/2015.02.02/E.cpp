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

int main() {
	int l, s;
	cin >> l >> s;
	int bad = 0;
	if (l & 1) bad = 1;
	int a = l / 4, b = (l - 2 * a) / 2; //a <= b;
	if (1LL * a * b < s || a + b - 1 > s) bad = 1;
	if (bad) {
		cout << "-1" << endl;
	}
	else {
		long long ago = 1LL * a * b - s;
		vector<pair<int, int> > ans;
		ans.push_back({0, a});
		ans.push_back({0, 0});
		ans.push_back({b, 0});
		if (!ago) {
			ans.push_back({b, a});
		}
		else {
			int x = ago / (a - 1), y = ago % (a - 1);
			if (x) {
				ans.push_back({b, 1});
				ans.push_back({b - x, 1});
			}
			if (y) {
				ans.push_back({b - x, a - y});
				ans.push_back({b - x - 1, a - y});
				ans.push_back({b - x - 1, a});
			}
			else {
				ans.push_back({b - x, a});
			}
		}
		cout << ans.size() << endl;
		REP(i, ans.size()) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}

	return 0;
}
