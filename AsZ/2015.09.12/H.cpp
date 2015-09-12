#include <bits/stdc++.h>

#define MOD 998244353
#define g 3

using namespace std;

int x[1010];

int main()
{
	int len = 32, n = 10;
	x[0] = 1;
	ntt(x, len, 1);
	for (int i = 0; i < len; i++)
		x[i] = mul(x[i], x[i]);
	ntt(x, len, -1);
	return 0;
}

int main()
{

    return 0;
}
