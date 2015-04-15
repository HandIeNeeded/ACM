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

char s[N];
int n, a[N], b[N];
long long times;
int mp[5][5] = {
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2, -1, 4, -3,
	0, 3, -4, -1, 2,
	0, 4, 3, -2, -1
};

int index(char c) {
	if (c == 'i') return 2;
	else if (c == 'j') return 3;
	else return 4;
}

int mul(int x, int y) {
	int signal = x * y > 0 ? 1 : -1;
	x = abs(x), y = abs(y);
	return signal * mp[x][y];
}

int pow_mod(int x, long long y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &times);
		scanf("%s", s);
		a[0] = b[0] = 1;
		REPP(i, 1, n) a[i] = index(s[i - 1]);
		REP(i, 8) {
			REPP(j, 1, n) {
				b[i * n + j] = mul(b[i * n + j - 1], a[j]);
			}
		}
		//REPP(i, 0, 8 * n) {
		//	cout << i << ' ' << b[i] << endl;
		//}
		int ans = 1;
		ans = pow_mod(b[n], times);
		bool bad = 0;
		if (ans != -1) bad = 1;
		else {
			bool findi = 0, findj = 0;
			REPP(i, 1, n * min(8LL, times)) {
				if (b[i] == 2) {
					findi = 1;
				}
				if (findi && b[i] == 4) {
					findj = 1;
					break;
				}
			}
			if (!findi || !findj) bad = 1;
		}
		printf("Case #%d: %s\n", ca++, bad ? "NO" : "YES");
	}

	return 0;
}

