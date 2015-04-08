#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5005;
long long a[N];

bool good(int a, int b) {
	long long upper = (1LL << 50) - 1;
	long long x = ::a[a], y = ::a[b];
	long long hole = ~y & upper;
	long long ball = x & hole;
	hole += ball;
	hole &= upper;
	hole |= (x & y);
	hole &= y;
	return __builtin_parityll(hole);
}

int main() {
	int n;
	scanf("%d", &n);
	REPP(i, 1, n) {
		int tmp;
		scanf("%d", &tmp);
		REP(j, tmp) {
			int x;
			scanf("%d", &x);
			x--;
			a[i] |= 1LL << x;
		}
	}
	int ans = 0;
	REPP(i, 1, n) {
		REPP(j, i + 1, n) {
			if (good(i, j)) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
