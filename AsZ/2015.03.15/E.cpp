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
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1005;
const int M = (1 << 13) + 5;

bool dp[N][M], op[N][M];
int pre[N][M], n, s[N], a[N];
char str[3] = "lr", ans[N];

int HB(int x) {
	if (x == 0) return 0;
	for (int i = 13; i >= 0; i--) {
		if (x & (1 << i)) {
			return (1 << i);
		}
	}
	return 0;
}

void go(int x, int y) {
	int now = 0;
	while (x) {
		ans[now++] = str[op[x][y]];
		y = pre[x][y];
		x--;
	}
	ans[now] = 0;
	reverse(ans, ans + now);
}

int main() {
	int t;
	//freopen("E.in", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		REPP(i, 1, n) {
			scanf("%d", a + i);
			s[i] = s[i - 1] + a[i];
		}
		if (HB(s[n]) != s[n]) {
			puts("no");
			continue;
		}
		REPP(i, 1, s[1]) {
			dp[1][i] = 0;
			pre[1][i] = 0;
		}
		dp[1][a[1]] = 1, op[1][a[1]] = 1, pre[1][a[1]] = 0;
		REPP(i, 2, n) {
			REPP(j, 1, s[i]) {
				dp[i][j] = 0;
				pre[i][j] = 0;
			}
			REPP(j, 1, s[i] - 1) {
				if (dp[i - 1][j]) {
					int low = LB(j);
					int high = HB(j);
					//left
					if (a[i] <= low) {
						int st = j + a[i];
						dp[i][st] = 1;
						op[i][st] = 0;
						pre[i][st] = j;
					}
					else if (low == high && a[i] > low) {
						int st = a[i];
						dp[i][st] = 1;
						op[i][st] = 0;
						pre[i][st] = j;
					}
					//right
					int right = s[i - 1] - j + high;
					low = LB(right);
					high = HB(right);
					if (a[i] <= low) {
						right = right + a[i];
						int st;
						if (high != HB(right)) {
							st = j - high + HB(right);
						}
						else {
							st = j;
						}
						dp[i][st] = 1;
						op[i][st] = 1;
						pre[i][st] = j;
					}
					else if (low == high && a[i] > low) {
						int st = j + a[i];
						dp[i][st] = 1;
						op[i][st] = 1;
						pre[i][st] = j;
					}
				}
			}
		}
		if (!dp[n][s[n]]) {
			puts("no");
		}
		else {
			go(n, s[n]);
			puts(ans);
		}
	}

	return 0;
}
