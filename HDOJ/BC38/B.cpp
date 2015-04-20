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
int a[N], cnt[N];

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int mx = 0;
		REPP(i, 1, n) scanf("%d", a + i), mx = max(mx, a[i]);
		REPP(i, 1, mx) cnt[i] = 0;
		REPP(i, 1, n) cnt[a[i]]++;
		REPP(i, 1, mx) {
			for (int j = i + i; j <= mx; j += i) {
				cnt[i] += cnt[j];
			}
		}
		int ans = 1;
		for (int i = mx; i >= 1; i--) {
			if (cnt[i] >= 2) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

