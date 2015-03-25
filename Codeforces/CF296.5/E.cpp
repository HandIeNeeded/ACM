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

const int N = 5005;
vector<int> a, b[21];

int main() {
	ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	REP(i, n) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	REP(i, n) {
		REP(j, k + 1) {
			b[j].push_back(a[i] * j);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int ans = -1;
		int find = 0;
		REPP(i, 1, k) {
			REPP(j, 1, i) {
				for (auto y: b[j]) {
					int k = i - j;
					int z = x - y;
					if (*lower_bound(b[k].begin(), b[k].end(), z) == z) {
						ans = i;
						find = 1;
						break;
					}
				}
			}
			if (find) break;
		}
		cout << ans << endl;
	}

	return 0;
}

