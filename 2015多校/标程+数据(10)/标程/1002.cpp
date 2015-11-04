#include <algorithm>
#include <cstdio>
using namespace std;

#define MX 1000005
#define MOD 1000000007
typedef long long LL;
int me[MX], f[MX], g[MX];
LL rev[MX];

int main() {
	int i, j, k, p, e, T;
	for (i = 0; i < MX; i++) f[i] = i;
	for (i = 2; i < 1005; i++) if (f[i] == i) {
		for (j = i * i; j < MX; j += i) f[j] = i;
	}
	rev[1] = 1;
	for (i = 2; i < MX; i++) rev[i] = (MOD-rev[MOD % i]) * (MOD / i) % MOD;
	LL x = 1, y;
	for (i = 2; i < MX; i++) {
		y = x;
		for (k = i; k > 1; ) {
			p = f[k];
			e = 0;
			while (k % p == 0) k /= p, e++;
			for (int t = 0; t < min(me[p], e); t++) y = y * rev[p] % MOD;
			
			if (me[p] < e) {
				x = x * p % MOD;
				me[p] = e;
			}
		}
		g[i - 1] = y;
	}
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &i);
		printf("%d\n", g[i]);
	}
	return 0;
}
