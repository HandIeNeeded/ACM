#include <bits/stdc++.h>

#define g 5
#define N 131072
#define MAXN 262144
#define MOD 258280327

using namespace std;

int f[N * 15], f2[N * 15], ans[N * 15];

int add(int x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

int mul(int x, int y)
{
	x = (1LL * x * y) % MOD;
	return x;
}

int pow_mod(int x, int y)
{
	int ans = 1, t = x;
	while (y)
	{
		if (y & 1)
			ans = (1LL * ans * t) % MOD;
		t = (1LL * t * t) % MOD;
		y >>= 1;
	}
	return ans;
}

void change(int *x, int len)
{
	int u, j;
	u = j = len / 3;
	for (int i = 1; i < len - 1; i++)
	{
		if (i < j)
			swap(x[i], x[j]);
		int k = u;
		while (j >= k * 2)
		{
			j -= k * 2;
			k /= 3;
		}
		j += k;
	}
}

void nft(int *x, int len, int ty)
{
	change(x, len);
	for (int h = 3; h <= len; h *= 3)
	{
		int l = h / 3;
		int G = pow_mod(g, (MOD - 1) / h);
		for (int i = 0; i < len; i += h)
		{
			int n1, n2, n3;
			n3 = (n2 = (n1 = i) + l) + l;
			int g1, g2;
			g1 = g2 = 1;
			int G1 = pow_mod(G, l);
			int G2 = pow_mod(G, 2 * l);
			for (int j = 0; j < l; j++)
			{
				int u1 = x[n1 + j];
				int u2 = x[n2 + j];
				int u3 = x[n3 + j];
				x[n1 + j] = add(u1, add(mul(g1, u2), mul(g2, u3)));
				x[n2 + j] = add(u1, add(mul(G1, mul(g1, u2)), mul(G2, mul(g2, u3))));
				x[n3 + j] = add(u1, add(mul(G2, mul(g1, u2)), mul(G1, mul(g2, u3))));
				g1 = mul(g1, G);
				g2 = mul(g2, mul(G, G));
			}
		}
	}
	if (ty == -1)
	{
		for (int i = 1; i <= len / 2; i++)
			swap(x[i], x[len - i]);
		int inv = pow_mod(len, MOD - 2);
		for (int i = 0; i < len; i++)
			x[i] = mul(x[i], inv);
	}
}

int main()
{
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("dichromatic.in", "r", stdin);
	// freopen("dichromatic.out", "w", stdout);

	int q, h;
	scanf("%d%d", &q, &h);

	f[0] = f[1] = 1;
	ans[0] = ans[1] = 1;
	int inv = pow_mod(2, MOD - 2);
	for (int k = 0; k < h; k++)
	{
		int lim = min(N, pow_mod(2, 2 * k + 1));
		int n = 1;
		while (n <= lim * 4)
			n *= 3;
		for (int i = 0; i <= lim; i++)
			f2[i] = f[i];
		for (int i = lim + 1; i < n; i++)
			f2[i] = 0;
		nft(f2, n, 1);
		for (int i = 0; i < n; i++)
			f2[i] = mul(f2[i], f2[i]);
		nft(f2, n, -1);

		// for (int i = 0; i < n; i++)
		// 	printf("%d%c", f2[i], " \n"[i == n - 1]);

		for (int i = 0; i < n; i++)
			f[i] = f2[i];
		nft(f, n, 1);
		for (int i = 0; i < n; i++)
			f[i] = mul(f[i], f[i]);
		nft(f, n, -1);

		for (int i = n - 1; i > 0; i--)
		{
			f[i] = f2[i - 1];
			if (i >= 3)
				f[i] = add(f[i], f[i - 3]);
		}
		f[0] = 0;

		for (int i = 0; i < n; i++)
			ans[i] = add(ans[i], f[i]);
		
		// for (int i = 0; i < n; i++)
		// 	printf("%d%c", f[i], " \n"[i == n - 1]);
	}
	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d%c", ans[x], " \n"[i == q - 1]);
	}

	return 0;
}