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

const int N = 1e5 + 5;
int h[N], d[N];

int main() {
	ios :: sync_with_stdio(0);
	int ans = 0, good = 1;
	int n, m;
	cin >> n >> m;
	REPP(i, 1, m) cin >> d[i] >> h[i];
	REPP(i, 2, m) {
		if (abs(h[i] - h[i - 1]) > d[i] - d[i - 1]) {
			good = 0;
			break;
		}
		else {
			ans = max(ans, (h[i] + h[i - 1] + d[i] - d[i - 1]) / 2);
		}
	}
	if (good) {
		ans = max(ans, h[m] + (n - d[m]));
		ans = max(ans, h[1] + d[1] - 1);
		cout << ans << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}

