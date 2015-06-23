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

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 20;
int a[N], b[N];
LL dp[N][2][2], pw[N];
bool vis[N][2][2];

LL dfs(int dep, int fa, int fb) {
	if (dep < 0) return 0;
	else if (vis[dep][fa][fb]) {
		return dp[dep][fa][fb];
	}
	else {
		vis[dep][fa][fb] = 1;
		if (fa && fb) {
			return dp[dep][fa][fb] = pw[dep + 1] - 1;
		}
		else {
			LL &ans = dp[dep][fa][fb];
			if (fa) {
				REP(i, 10) {
					REP(j, b[dep] + 1) {
						int tmp = (i + j) % 10;
						LL res = tmp * pw[dep] + dfs(dep - 1, fa, j != b[dep]);
						ans = max(res, ans);
					}
				}
			}
			else if (fb) {
				REP(i, a[dep] + 1) {
					REP(j, 10) {
						int tmp = (i + j) % 10;
						LL res = tmp * pw[dep] + dfs(dep - 1, i != a[dep], fb);
						ans = max(res, ans);
					}
				}
			}
			else {
				REP(i, a[dep] + 1) {
					REP(j, b[dep] + 1) {
						int tmp = (i + j) % 10;
						LL res = tmp * pw[dep] + dfs(dep - 1, i != a[dep], j != b[dep]);
						ans = max(ans, res);
					}
				}
			}
			return ans;
		}
	}
}

LL solve(LL A, LL B) {
	MST(a, 0), MST(b, 0);
	int lena = 0, lenb = 0;
	while (A) {
		a[lena++] = A % 10;
		A /= 10;
	}
	while (B) {
		b[lenb++] = B % 10;
		B /= 10;
	}
	int len = max(lena, lenb);
	return dfs(len - 1, 0, 0);
}

int main() {
    ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	pw[0] = 1;
	REPP(i, 1, 18) pw[i] = pw[i - 1] * 10;
	while (t--) {
		LL A, B;
		cin >> A >> B;
		MST(vis, 0), MST(dp, 0);
		cout << solve(A, B) << endl;
	}

    return 0;
}


