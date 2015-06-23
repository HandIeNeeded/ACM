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

using namespace std;

const int MO = 100000007;
const int N = 1e6 + 5;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}
int fac[N], inv[N], pw[N];

void init() {
	fac[0] = inv[0] = inv[1] = pw[0] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO, pw[i] = 2 * pw[i - 1] % MO;
	REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
	REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int main() {
    ios :: sync_with_stdio(0);
	init();
	int n;
	cin >> n;
	int ans = 0;
	//step 1 fill until there is only 1 or 2 space
	//step 2 fill until there is only 1 space
	//step 3 fill until there is no space
	REP(left, 2) {
		REP(right, 2) {
			REPP(two, 0, n / 2) {
				int tot = left + 3 * two;
				int one = 0;
				if (right) {
					if ((n - tot) & 1) continue;
					else {
						one = ((n - tot) >> 1) - 1;
					}
				}
				else {
					if ((n - tot) & 1) {
						one = (n - tot) >> 1;
					}
					else continue;
				}
				if (one < 0) break;
				int tmp = 1;
				tmp = 1LL * C(one + two, one) * fac[one + two + 1] % MO;
				tmp = 1LL * tmp * pw[two] % MO * fac[left + right + two] % MO;
				tmp = 1LL * tmp * fac[one + two] % MO;
				add(ans, tmp);
			}
		}
	}
	cout << ans << endl;
    return 0;
}

