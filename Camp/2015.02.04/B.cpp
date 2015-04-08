#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 200005;
char rr[N], cc[N];
int r[N], c[N];
int row[4][N], col[4][N];

int go(int x, int y) {
	return !(x && y);
}

int cal(int x, int y) {
	return (!x) || y;
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s%s", rr, cc);
	REP(i, n) r[i + 1] = 1 - (rr[i] - '0');
	REP(j, m) c[j + 1] = 1 - (cc[j] - '0');
	row[1][1] = col[1][1] = r[1] || c[1];
	REPP(i, 2, n) row[1][i] = cal(row[1][i - 1], r[i]);
	REPP(i, 2, m) col[1][i] = cal(col[1][i - 1], c[i]);
	REPP(i, 2, 3) {
		row[i][1] = cal(row[i - 1][1], c[i]);
		REPP(j, 2, n) {
			row[i][j] = go(row[i][j - 1], row[i - 1][j]);
		}
		col[i][1] = cal(col[i - 1][1], r[i]);
		REPP(j, 2, m) {
			col[i][j] = go(col[i][j - 1], col[i - 1][j]);
		}
	}
	while (q--) {
		int x, y;
		int ans = 0;
		scanf("%d%d", &x, &y);
		if (x >= y) {
			if (y > 3) {
				x -= (y - 3);
				ans = row[3][x];
			}
			else ans = row[y][x];
		}
		else {
			if (x > 3) {
				y -= (x - 3);
				ans = col[3][y];
			}
			else ans = col[x][y];
		}
		ans ? puts("Yes") : puts("No");
	}

	return 0;
}

