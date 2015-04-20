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

const int N = 1005;
pair<int, int> q[N], p[N];
int n, m, a, b;

inline LL sqr(int x) {return 1LL * x * x;}

LL calc(int x, int y) {
	LL ans = 0;
	REPP(i, 1, a) ans += sqr(p[i].first - x) + sqr(p[i].second - y);
	int tmp = 1 << 30;
	REPP(i, 1, b) {
		tmp = min(tmp, abs(q[i].first - x) + abs(q[i].second - y));
	}
	ans += tmp;
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b;
		REPP(i, 1, a) {
			int x, y;
			cin >> x >> y;
			p[i] = {x, y};
		}
		REPP(i, 1, b) {
			int x, y;
			cin >> x >> y;
			q[i] = {x, y};
		}
		LL ans = 1LL << 60;
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				ans = min(ans, calc(i, j));
			}
		}
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

