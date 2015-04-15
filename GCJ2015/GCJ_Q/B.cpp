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
int a[N], n;

int go(int x) {
	int cnt = 0;
	REPP(i, 1, n) {
		if (a[i] % x == 0) {
			cnt += a[i] / x - 1;
		}
		else cnt += a[i] / x;
	}
	return x + cnt;
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REPP(i, 1, n) scanf("%d", a + i);
		int ans = int(1e9);
		REPP(i, 1, 1000) {
			ans = min(ans, go(i));
		}
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

