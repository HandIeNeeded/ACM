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
int mk[N], need[N], n, m;

long long count(int x) {
	long long ans = 0;
	long long clk = 1LL * x * mk[1];
	REPP(i, 1, n) {
		ans += (clk + mk[i] - 1) / mk[i];
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t, ca = 1;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		REPP(i, 1, n) cin >> mk[i];
		int lo = 0, hi = m + 1;
		while (lo + 1 < hi) {
			int mid = (lo + hi) >> 1;
			if (count(mid) >= m) hi = mid;
			else lo = mid;
		}
		long long clk = 1LL * lo * mk[1];
		REPP(i, 1, n) {
			need[i] = mk[i] - clk % mk[i];
			if (need[i] == mk[i]) need[i] = 0;
		}
		int id = 0;
		REPP(i, 1, n) {
			id += (clk + mk[i] - 1) / mk[i];
		}
		//cout << hi << ' ' << clk << ' ' << id << endl;
		int ans = -1;
		REPP(i, 0, 2 * mk[1]) {
			REPP(j, 1, n) {
				if (need[j] == 0) {
					++id;
					need[j] = mk[j];
					if (id == m) {
						ans = j;
						break;
					}
				}

			}
			if (ans > 0) break;
			REPP(j, 1, n) {
				need[j]--;
			}
		}
		cout << "Case #" << ca++ << ": " << ans << endl;
	}
	return 0;
}

