#include <bits/stdc++.h>

#define MOD 1004535809
#define g 3
#define N 150000

using namespace std;

inline int add(int x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y)
{
	return (1LL * x * y) % MOD;
}

inline int pow_mod(int x, int y)
{
	int res = 1, t = x;
	while (y)
	{
		if (y & 1)
			res = mul(res, t);
		t = mul(t, t);
		y >>= 1;
	}
	return res;
}

void change(int *x, int len)
{
	for (int i = 1, j = len >> 1; i < len - 1; i++)
	{
		if (i < j)
			swap(x[i], x[j]);
		int k = len >> 1;
		while (j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if (k > j)
			j += k;
	}
}

void ntt(int *x, int len, int ty)
{
	change(x, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		int l = h >> 1;
		int G = pow_mod(g, (MOD - 1) / h);
		for (int i = 0; i < len; i += h)
		{
			int C = 1, T = i + h, u, v;
			for (int s = i, t = i + l; t < T; s++, t++)
			{
				u = x[s], v = mul(C, x[t]);
				x[s] = add(u, v);
				x[t] = add(u, MOD - v);
				C = mul(C, G);
			}
		}
	}
	if (ty == -1)
	{
		for (int i = 1; i < len / 2; i++)
			swap(x[i], x[len - i]);
		int inv = pow_mod(len, MOD - 2);
		for (int i = 0; i < len; i++)
			x[i] = mul(x[i], inv);
	}
}

int jc[N], invj[N];
int a[N * 4], b[N * 4], f[N * 4];

void prepare()
{
	jc[0] = 1;
	invj[0] = 1;
    for (int i = 1; i < N; i++)
    {
		jc[i] = mul(jc[i - 1], i);
		invj[i] = pow_mod(jc[i], MOD - 2);
	}
}

int sum(int x)
{
	return 1LL * x * (x - 1) / 2 % (MOD - 1);
}

void calc(int l, int r)
{
	if (l == r)
	{
		int tmp = mul(pow_mod(2, sum(l)), invj[l - 1]);
		f[l] = add(tmp, MOD - f[l]);
		return;
	}
	int mid = (l + r) / 2;
	calc(l, mid);
	int len = r - l + 1;
	int ll = 1;
	while (ll <= len * 2 + 4)
		ll <<= 1;
	for (int i = 0; i < ll; i++)
		a[i] = b[i] = 0;
	for (int i = 1; i <= len; i++)
		a[i] = mul(invj[i], pow_mod(2, sum(i)));

	for (int i = l; i <= mid; i++)
		b[i - l] = f[i];

	ntt(a, ll, 1);
	ntt(b, ll, 1);
	for (int i = 0; i < ll; i++)
		a[i] = mul(a[i], b[i]);
	ntt(a, ll, -1);

	for (int i = mid + 1; i <= r; i++)
		f[i] = add(f[i], a[i - l]);
	calc(mid + 1, r);
}

int main()
{
    prepare();
    int n;
    scanf("%d", &n);
    calc(1, n);
    cout << mul(f[n], jc[n - 1]) << endl;
    return 0;
}
