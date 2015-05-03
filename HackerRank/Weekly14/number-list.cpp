#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
int l[N], r[N], a[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		REPP(i, 1, n) scanf("%d", a + i);
		REPP(i, 1, n) l[i] = i - 1, r[i] = i + 1;
		REPP(i, 1, n) {
			int j = l[i];
			while (j && a[j] <= a[i]) j = l[j];
			l[i] = j;
		}
		for (int i = n; i >= 1; i--) {
			int j = r[i];
			while (j < n + 1 && a[j] < a[i]) j = r[j];
			r[i] = j;
		}
		long long ans = 0;
		REPP(i, 1, n) {
			if (a[i] > m) {
				ans += 1LL * (i - l[i]) * (r[i] - i);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}

