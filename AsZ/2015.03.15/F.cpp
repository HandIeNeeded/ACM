#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define MAXN 1123456
#define MST(a, b) memset(a, (b), sizeof(a))
#define MO 1000000009

using namespace std;

int f[MAXN][4];
char s1[MAXN], s2[MAXN], s3[MAXN];

int mul(int u, int v)
{
	return 1LL * u * v % MO;
}

void add(int &u, int v)
{
    u += v;
    if (u >= MO) u -= MO;
}

int calcxxx(char c1, char c2, char c3)
{
	int tmp = 1;
	if (c1 == '?') tmp *= 26;
	if (c2 == '?') tmp *= 26;
    if (c3 == '?') tmp *= 26;
    return tmp;
}

int calc123(char c1, char c2, char c3)
{
    if (c1 == '?' && c2 == '?' && c3 == '?') return 26 * 25 * 4;
	else if (c1 == '?' && c2 == '?')
    {
        int x = c3 - 'a' + 1;
        if (x <= 2) return 0;
        return (x - 1) * (x - 2) / 2;

    } else if (c1 == '?' && c3 == '?')
    {
		int x = c2 - 'a' + 1;
		if (x <= 1) return 0;
		return (x - 1) * (26 - x);

    } else if (c2 == '?' && c3 == '?')
    {
        int x = c1 - 'a' + 1;
        return (26 - x) * (25 - x) / 2;
    }
    else if (c1 == '?')
    {
        if (c2 >= c3) return 0;
        int x = c2 - 'a' + 1;
        if (x == 0) return 0;
        return x - 1;

    } else if (c2 == '?')
	{
        if (c1 >= c3) return 0;
        return c3 - c1 - 1;

	} else if (c3 == '?')
	{
		if (c1 == 'a' - 1 && c2 == 'a' - 1) return 26;
        if (c1 >= c2) return 0;
        int x = c2 - 'a' + 1;
        return 26 - x;
	} else if (c1 < c2 && c2 < c3) return 1;
	else return 0;
}

int calc12(char c2, char c3)
{
    if (c2 == '?' && c3 == '?') return 26 * 25 / 2;
    else if (c2 == '?') return c3 - 'a';
    else if (c3 == '?') return 'z' - c2;
	else if (c2 < c3) return 1;
	else return 0;
}

int calcx12(char c1, char c2, char c3)
{
	int tmp = 1;
	if (c1 == '?') tmp = 26;
	return tmp * calc12(c2, c3);
}

int calc12x(char c1, char c2, char c3)
{
	int tmp = 1;
	if (c3 == '?') tmp = 26;
	return tmp * calc12(c1, c2);
}

int calc11(char c1, char c2)
{
    if (c1 == '?' && c2 == '?') return 26;
    if (c1 == '?' || c2 == '?') return 1;
    if (c1 == c2) return 1;
    return 0;
}

int calc111(char c1, char c2, char c3)
{
    if (c1 == '?' && c2 == '?' && c3 == '?') return 26;
    else return min(calc11(c1, c2), min(calc11(c1, c3), calc11(c2, c3)));
}

int calcx11(char c1, char c2, char c3)
{
	int tmp = 1;
	if (c1 == '?') tmp = 26;
	return tmp * calc11(c2, c3);
}

int calc122(char c1, char c2, char c3)
{
	if (c1 == '?' && c2 == '?' && c3 == '?') return 26 * 25 / 2;
	else if (c1 == '?' && c2 == '?')
    {
        int x = c3 - 'a' + 1;
        return (x - 1);

    } else if (c1 == '?' && c3 == '?')
    {
		int x = c2 - 'a' + 1;
		return (x - 1);

    } else if (c2 == '?' && c3 == '?')
    {
        int x = c1 - 'a' + 1;
        return (26 - x);
    }
    else if (c1 == '?')
    {
        if (c2 != c3) return 0;
        int x = c2 - 'a' + 1;
        return x - 1;

    } else if (c2 == '?')
	{
        if (c1 >= c3) return 0;
        return 1;

	} else if (c3 == '?')
	{
        if (c1 >= c2) return 0;
        return 1;
	} else if (c1 < c2 && c2 == c3) return 1;
	else return 0;
}

int calc11x(char c1, char c2, char c3)
{
	int tmp = 1;
	if (c3 == '?') tmp = 26;
	return tmp * calc11(c1, c2);
}

int calc112(char c1, char c2, char c3)
{
	if (c1 == '?' && c2 == '?' && c3 == '?') return 26 * 25 / 2;
	else if (c1 == '?' && c2 == '?')
	{
        int x = c3 - 'a' + 1;
        return (x - 1);

    } else if (c1 == '?' && c3 == '?')
    {
		int x = c2 - 'a' + 1;
		return 26 - x;

    } else if (c2 == '?' && c3 == '?')
    {
        int x = c1 - 'a' + 1;
        return (26 - x);
    }
    else if (c1 == '?')
    {
        if (c2 >= c3) return 0;
        return 1;

    } else if (c2 == '?')
	{
        if (c1 >= c3) return 0;
        return 1;

	} else if (c3 == '?')
	{
        if (c1 != c2) return 0;
        return 'z' - c1;
	} else if (c1 == c2 && c2 < c3) return 1;
	else return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (;T; --T)
	{
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%s", s3);
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int l3 = strlen(s3);
        int n = max(l1, max(l2, l3));
        //MST(f, 0);
        f[0][1] = 1;
		REPP(i, 1, n)
		{
			int o1 = 1, o2 = 1, o3 = 1;
			char c1 = s1[i - 1];
            if (i - 1 > l1 - 1) c1 = 'a' - 1, o1 = 0;
			char c2 = s2[i - 1];
            if (i - 1 > l2 - 1) c2 = 'a' - 1, o2 = 0;
			char c3 = s3[i - 1];
			if (i - 1 > l3 - 1) c3 = 'a' - 1, o3 = 0;
			f[i][0] = 0;
			if (f[i - 1][0]) add(f[i][0], mul(f[i - 1][0], calcxxx(c1, c2, c3)));

			if (f[i - 1][1]) add(f[i][0], mul(f[i - 1][1], calc123(c1, c2, c3)));
            if (f[i - 1][2]) add(f[i][0], mul(f[i - 1][2], calcx12(c1, c2, c3)));
            if (f[i - 1][3]) add(f[i][0], mul(f[i - 1][3], calc12x(c1, c2, c3)));


            f[i][1] = 0;
            if (f[i - 1][1] && o1 && o2 && o3)
				add(f[i][1], mul(f[i - 1][1], calc111(c1, c2, c3)));

			f[i][2] = 0;
			if (o2 && o3)
			{
				if (f[i - 1][2]) add(f[i][2], mul(f[i - 1][2], calcx11(c1, c2, c3)));
				if (f[i - 1][1]) add(f[i][2], mul(f[i - 1][1], calc122(c1, c2, c3)));
			}

			f[i][3] = 0;
			if (o1 && o2)
			{
				if (f[i - 1][3]) add(f[i][3], mul(f[i - 1][3], calc11x(c1, c2, c3)));
				if (f[i - 1][1]) add(f[i][3], mul(f[i - 1][1], calc112(c1, c2, c3)));
			}
		}
		printf("%d\n", f[n][0]);
	}
	return 0;
}
