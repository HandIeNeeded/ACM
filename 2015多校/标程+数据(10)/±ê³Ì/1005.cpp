#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;
const int MX = 2005;
int M, N;
LL val[MX][MX];

inline void chkmax(LL &x, LL y) {
	if (x < y) x = y;
}

struct Data {
	int w, a, b;
	
	bool operator <(const Data &c) const {
		if (w != c.w) return w < c.w;
		return a + b > c.a + c.b;
	}
	
	void input() {
		scanf("%d%d%d", &w, &a, &b);
	}
} D[MX];

int main() {
	int tc, i, n, j, k, t;
	int l, r;
	int w, ma;
	LL s, mx;
	
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &M, &N);
		for (i = 0; i < N; i++) D[i].input();
		
		sort(D, D + N);
		n = 0;
		for (l = 0; l < N; l = r) {
			w = D[l].w;
			for (r = l; r < N && D[r].w == w; r++);
			n++;
			for (i = 0; i <= M; i++) val[n][i] = val[n - 1][i];
			s = 0;
			ma = 0;
			for (i = l; i < r; i++) ma = max(ma, D[i].a);
			for (i = l, k = 1; k <= M / w; k++) {
				if (i < r && ma < D[i].a + D[i].b) {
					s += D[i].a + D[i].b;
					i++;
				}
				else s += ma;
				for (j = 0; j + k * w <= M; j++) chkmax(val[n][j + k * w], val[n - 1][j] + s);
			}
		}
		LL ans = 0;
		for (i = 0; i <= M; i++) chkmax(ans, val[n][i]);
		printf("%lld\n", ans);
	}
	return 0;
}
