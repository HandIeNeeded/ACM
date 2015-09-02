#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 200005;
const int MS = 1 << 17;
int n, m;
int a[MX], b[MX], c[MX];
int fst[MX], nxt[MX];
int d[MX];
int q[MX], hd, tl;
int cnt[MS];

int main() {
	int tc, k, u, v, qc, s;
	long long ans;
	
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		m = n - 1;
		for (k = 1; k <= m; k++) {
			scanf("%d%d%d", &a[k], &b[k], &c[k]);
			a[k + m] = b[k], b[k + m] = a[k], c[k + m] = c[k];
		}
		fill_n(fst, n + 1, 0);
		for (k = m * 2; k > 0; k--) {
			nxt[k] = fst[a[k]];
			fst[a[k]] = k;
		}
		fill_n(d, n + 1, -1);
		hd = tl = 0;
		d[1] = 0;
		q[tl++] = 1;
		while (hd < tl) {
			u = q[hd++];
			for (k = fst[u]; k; k = nxt[k]) {
				v = b[k];
				if (d[v] != -1) continue;
				d[v] = d[u] ^ c[k];
				q[tl++] = v;
			}
		}
		memset(cnt, 0, sizeof cnt);
		for (u = 1; u <= n; u++) cnt[d[u]]++;
		
		for (scanf("%d", &qc); qc--; ) {
			scanf("%d", &s);
			ans = 0;
			for (u = 1; u <= n; u++) ans += cnt[d[u] ^ s];
			if (!s) ans += n;
			ans /= 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
