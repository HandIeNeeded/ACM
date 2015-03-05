#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5e5 + 5;
int pos[N], dp[N], a[2][N], b[N], mi[N], n;
vector<int> tmp[N];

int go() {
	int cnt = 1;
	REPP(i, 1, n) {
		int now = b[i];
		REP(j, cnt) {
			int pos = upper_bound(tmp[j].begin(), tmp[j].end(), now) - tmp[j].begin();
			if (pos < (int) tmp[j].size()) {
				int tt = now;
				now = tmp[j][pos];
				tmp[j][pos] = tt;
			}
			else {
				tmp[j].push_back(now);
				now = -1;
				break;
			}
		}
		if (now != -1) {
			tmp[cnt++].push_back(now);
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	REP(i, 2) {
		REPP(j, 1, n) {
			scanf("%d", &a[i][j]);
		}
	}
	REPP(i, 1, n) {
		pos[a[0][i]] = i;
	}
	REPP(i, 1, n) {
		b[i] = pos[a[1][i]];
	}
	int ans = go();
	printf("%d\n", ans);

	return 0;
}

