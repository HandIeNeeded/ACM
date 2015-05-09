#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

const int N = 505;
int a[N], cnt[N], n, s;
vector<int> edge[N];

void dfs(int x, int p) {
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			dfs(y, x);
		}
	}
	if (x != s && cnt[x]) {
		cnt[x]--;
		cnt[p]++;
	}
}

int main() {
	//freopen("A.in", "r", stdin);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int sum = 0;
		cin >> n >> s;
		REPP(i, 1, n) edge[i].clear();
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		REPP(i, 1, n) scanf("%d", a + i), sum += a[i], cnt[i] = a[i];
		int ans = 0;
		if (cnt[s] == sum) {
			ans = 0;
		}
		else {
			REPP(i, 1, sum) {
				dfs(s, 0);
				if (cnt[s] == sum) {
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

