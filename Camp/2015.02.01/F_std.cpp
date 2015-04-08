#include <cstdio>
#include <cstring>

const int N = 5000000 + 1;
const int M = 10 + 1;
const int L = 30;
const int D = 4;
const int MOD = (int)1e9 + 7;

int n, m;
char str[N + 1];

void add(int &x, int a)
{
	x += a;
	if (x >= MOD) {
		x -= MOD;
	}
}

void combine(bool avail, int* lwys, int* rwys, int* wys)
{
	for (int i = 0; i <= m; ++ i) {
		wys[i << 1] = wys[i << 1 | 1] = 0;
		for (int j = 0; j <= i; ++ j) {
			add(wys[i << 1], (long long)lwys[j << 1 | 1] * rwys[i - j << 1 | 1] % MOD);
		}
		if (avail) {
			for (int j = 0; j < i; ++ j) {
				add(wys[i << 1 | 1], (long long)lwys[j << 1] * rwys[i - 1 - j << 1] % MOD);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= m; ++ i) {
		add(wys[i << 1 | 1], sum);
		sum = wys[i << 1 | 1];
		add(wys[i << 1 | 1], wys[i << 1]);
	}
}

int pre[2][1 << (1 << D) - 1][M << 1], wys[L][2][M << 1];

void gen(int u, int d, int &mask)
{
	if (d) {
		mask = mask << 1 | (u <= n && str[u] == '0');
		gen(u << 1,     d - 1, mask);
		gen(u << 1 | 1, d - 1, mask);
	}
}

int* solve(int u, int d, int* loc)
{
	if ((u << D) <= n) {
		int* lwys = solve(u << 1,     d + 1, wys[d + 1][0]);
		int* rwys = solve(u << 1 | 1, d + 1, wys[d + 1][1]);
		combine(str[u] == '0', lwys, rwys, loc);
		return loc;
	} else {
		int mask = 0;
		gen(u, D, mask);
		return pre[D + 1 & 1][mask];
	}
}

int main()
{
	scanf("%d%d%s", &n, &m, str + 1);
	memset(pre, 0, sizeof(pre));
	pre[0][0][0] = pre[0][0][1] = pre[0][1][0] = 1;
	for (int i = 0; i <= m; ++ i) {
		pre[0][1][i << 1 | 1] = 1;
	}
	for (int i = 1; i < D; ++ i) {
		int i2 = i + 1 & 1;
		int s = (1 << i) - 1;
		for (int mask = 0; mask < 1 << s + s + 1; ++ mask) {
			combine(mask >> s + s, pre[i2][mask >> s & (1 << s) - 1], pre[i2][mask & (1 << s) - 1], pre[i & 1][mask]);
		}
	}
	int* w = solve(1, 0, wys[0][0]);
	printf("%d\n", w[m << 1 | 1]);
	return 0;
}
