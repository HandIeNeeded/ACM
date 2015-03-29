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

const int N = 1005;
int cnt[N], a[N], f[N];
vector<int> id[N];
pair<int, int> ans[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, k, m;
	cin >> n >> k;
	m = n / k;
	REPP(i, 1, n) {
		cin >> a[i];
		if (a[i] < 0) a[i] = 1;
		cnt[a[i]]++;
		id[a[i]].push_back(i - 1);
	}
	int tot = 0;
	while (tot < k) {
		int x, find = 0;
		REPP(i, 1, k) {
			if (cnt[i] && cnt[i] < m) {
				ans[tot++].first = i;
				find = 1, x = cnt[i];
				REP(j, x) {
					f[id[i].back()] = tot - 1;
					id[i].pop_back();
				}
				cnt[i] = 0;
				break;
			}
		}
		if (!find) {
			REPP(i, 1, k) {
				if (cnt[i] >= m) {
					find = 1, x = 0;
					ans[tot++].first = i;
					break;
				}
			}
		}
		REPP(i, 1, k) {
			if (cnt[i] >= m - x) {
				ans[tot - 1].second = i;
				REP(j, m - x) {
					f[id[i].back()] = tot - 1;
					id[i].pop_back();
				}
				cnt[i] -= m - x;
				break;
			}
		}
	}
	cout << "Yes" << endl;
	REP(i, n) {
		cout << ans[f[i]].first << ' ' << ans[f[i]].second << endl;
	}

	return 0;
}

