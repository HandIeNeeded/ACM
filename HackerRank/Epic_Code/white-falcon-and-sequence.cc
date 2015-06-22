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
#define LL long long

using namespace std;

const int N = 3005;
int c[N], a[N], b[N];

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> c[i];
	}
	LL ans = -(1LL << 60);
	REPP(i, 1, n) {
		int cnta = 0, cntb = 0;
		for (int j = i - 1; j > 0; j--) a[++cnta] = c[j];
		for (int j = i + 1; j <= n; j++) b[++cntb] = c[j];
		int t = min(cnta, cntb);
		LL now = 0;
		REPP(j, 1, t) {
			now += 1LL * a[j] * b[j];
			ans = max(ans, now);
			if (now <= 0) now = 0;
		}
		cnta = cntb = 0;
		for (int j = i; j > 0; j--) a[++cnta] = c[j];
		for (int j = i + 1; j <= n; j++) b[++cntb] = c[j];
		t = min(cnta, cntb);
		now = 0;
		REPP(j, 1, t) {
			now += 1LL * a[j] * b[j];
			ans = max(ans, now);
			if (now <= 0) now = 0;
		}
	}
	cout << ans << endl;

    return 0;
}

