#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

#define X first
#define Y second

typedef pair<int, int> pii;
const int MX = 1005;
int p[MX], pn;
pii a[MX];
int val[MX][MX];

inline void chkmax(int& x, int y) {
	if (x < y) x = y;
}

void add(int x, int y, int v) {
	for (; y <= pn; y += y & -y) chkmax(val[x][y], v);
}

int get(int x, int y) {
	int rlt = 0;
	for (; y; y -= y & -y) chkmax(rlt, val[x][y]);
	return rlt;
}

bool cmp(const pii &a, const pii &b) {
	if (a.X != b.X) return a.X > b.X;
	return a.Y < b.Y;
}

int b[MX];

int main() {
	int T, n;
	int i, j, k;
	
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		pn = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].X, &a[i].Y);
			p[pn++] = a[i].Y;
		}
		sort(p, p + pn);
		pn = unique(p, p + pn) - p;
		
		for (i = 1; i <= n; i++)
			a[i].Y = lower_bound(p, p + pn, a[i].Y) - p + 1;
		sort(a + 1, a + n + 1, cmp);
		
		for (i = 1; i <= pn; i++)
			for (k = 1; k <= pn; k++) val[i][k] = 0;
		
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= pn; j++) {
				b[j] = get(j, a[i].Y) + 1;
			}
			for (j = 1; j <= pn; j++) {
				add(a[i].Y, j, b[j]);
				add(j, a[i].Y, b[j]);
			}
		}
		
		int mx = 0;
		for (i = 1; i <= pn; i++) chkmax(mx, get(i, pn));
		printf("%d\n", mx);
	}
	return 0;
}
