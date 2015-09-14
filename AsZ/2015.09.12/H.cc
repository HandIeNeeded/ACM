#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

#define N 100100
#define SI 400400
#define MOD 880803841
#define g 26

using namespace std;

int cnt[N << 2], flag[N << 2];
int ql, qr;
int a[SI], b[SI], s[N], S[N];
int jc[SI], invj[SI], qm[SI];

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

void prepare(int n, int m)
{
    int len = 1;
    while (m * 2 >= len)
        len <<= 1;
    jc[0] = 1, invj[0] = 1;
    for (int i = 1; i < len; i++)
    {
        jc[i] = mul(jc[i - 1], i);
        invj[i] = pow_mod(jc[i], MOD - 2);
    }
    for (int i = 0; i < len; i++)
        qm[i] = pow_mod(i, n);

    a[0] = 0;
    for (int i = m + 1; i < len; i++)
        a[i] = 0;
    for (int i = 0; i <= m; i++)
        if (i % 2)
        {
            if (invj[i] == 0)
                a[i] = 0;
            else
                a[i] = MOD - invj[i];
        } else
            a[i] = invj[i];
    b[0] = 0;
    for (int i = m + 1; i < len; i++)
        b[i] = 0;
    for (int i = 1; i <= m; i++)
        b[i] = mul(qm[i], invj[i]);
    ntt(a, len, 1);
    ntt(b, len, 1);
    for (int i = 0; i < len; i++)
        a[i] = mul(a[i], b[i]);
    ntt(a, len, -1);
    for (int i = 0; i <= m; i++)
        s[i] = a[i];
}

void push(int x, int l, int r) {
    cnt[L] = MID - l + 1 - cnt[L];
    cnt[R] = r - MID - cnt[R];
    flag[L] ^= 1, flag[R] ^= 1;
    flag[x] = 0;
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        cnt[x] = r - l + 1 - cnt[x];
        flag[x] ^= 1;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        cnt[x] = cnt[L] + cnt[R];
    }
}

void build(int x, int l, int r) {
    if (l == r) {
        cnt[x] = 1;
        flag[x] = 0;
    }
    else {
        build(LC), build(RC);
        cnt[x] = cnt[L] + cnt[R];
        flag[x] = 0;
    }
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, d;
        scanf("%d%d%d", &n, &m, &d);
        build(1, 1, m);
        prepare(n, m);
        while (d--) {
            scanf("%d%d", &ql, &qr);
            update(1, 1, m);
            printf("%d\n", s[cnt[1]]);
        }
    }

    return 0;
}

