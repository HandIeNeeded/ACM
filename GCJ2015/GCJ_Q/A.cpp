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

char s[N];
int a[N];

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d%s", &n, s);
		REP(i, n + 1) a[i] = s[i] - '0';
		REPP(i, 1, n) a[i] += a[i - 1];
		int ans = 0;
		REPP(i, 1, n) ans = max(ans, i - a[i - 1]);
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

