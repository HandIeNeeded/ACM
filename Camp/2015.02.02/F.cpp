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

const int N = 50;
const int MO = 1e9 + 7;
int cnt[1 << 18], pw[N], n, k, lim;
int dp[2][27][1 << 18];
long long a[N];

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

void init() {
	REP(i, 1 << 18) {
		cnt[i] = __builtin_popcount(i);
	}
	REP(i, 45) pw[i] = pow_mod(i, k);
	lim = (1 << 18) - 1;
}

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int Guass() {
	long long bit = 1LL << 44;
	int now = 1;
	REP(turn, 44) {
		bit >>= 1;
		bool find = 0;
		REPP(i, now, n) {
			if (a[i] & bit) {
				find = 1;
				swap(a[i], a[now]);
				break;
			}
		}
		if (find) {
			REPP(i, 1, n) if (i != now && (a[i] & bit)) {
				a[i] ^= a[now];
			}
			now++;
		}
	}
	return now - 1;
}

void dfs(int dep, int limit, long long now, int &ans) {
	if (dep > limit) {
		add(ans, pw[__builtin_popcountll(now)]);
	}
	else {
		dfs(dep + 1, limit, now, ans);
		dfs(dep + 1, limit, now ^ a[dep], ans);
	}
}

int main() {
	//freopen("F.in", "r", stdin);
	scanf("%d%d", &n, &k);
	init();
	REPP(i, 1, n) scanf("%lld", a + i);
	int rank = Guass();
	//cout << rank << endl;
	//REPP(i, 1, n) {
	//	cout << a[i] << ' ';
	//}
	//cout << endl;
	if (rank <= 26) {
		int ans = 0;
		dfs(1, rank, 0, ans);
		REP(i, n - rank) {
			ans <<= 1;
			ans %= MO;
		}
		cout << ans << endl;
	}
	else {
		dp[0][0][0] = 1;
		int pre = 0, now = 1;
		REPP(i, 1, n) {
			int k = min(i - 1, 26);
			REP(cnt, k + 1) {
				REP(j, 1 << 18) {
					dp[now][cnt][j] = dp[pre][cnt][j];
				}
			}
			REP(cnt, k + 1) {
				int ni = cnt;
				if (i <= 26) {
					ni++;
				}
				REP(j, 1 << 18) {
					int nj = (a[i] & lim);
					nj ^= j;
					add(dp[now][ni][nj], dp[pre][cnt][j]);
				}
			}
			swap(pre, now);
		}
		int ans = 0;
		REP(cnt, 27) {
			REP(j, 1 << 18) {
				add(ans, 1LL * dp[pre][cnt][j] * pw[cnt + ::cnt[j]] % MO);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

