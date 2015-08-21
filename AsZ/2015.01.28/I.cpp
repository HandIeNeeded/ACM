#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L 2000000010
//#define L 0

using namespace std;

vector<long long> x, y;

long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}

long long calc(int i, int j, long long ty)
{
	long long dx = abs(x[i] - x[j]);
	long long dy = abs(y[i] - y[j]);
//	printf("%d %d\n", i, j);
//	printf("%lld %lld\n", x[i], y[i]);
//	printf("%lld %lld\n", x[i], y[i]);
//	printf("%lld %lld\n", dx, dy);
	long long g = gcd(dx, dy);
	long long l = 0;
	if ((dx / g) % 2 && (dy / g) % 2)
		l = g / 2;
	long long a = dx;
	long long b = y[i] + y[j];
	long long res = (a / 2) * (b / 2);
	if ((res + ty * l) % 2)
		while (1);
	return (res + ty * l) / 2;
}

long long det(int g, int h)
{
	return x[g] * y[h] - x[h] * y[g];
}

int main() {
	ios :: sync_with_stdio(0);


	freopen("semi-cool.in", "r", stdin);
	freopen("semi-cool.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long long g, h;
		scanf("%lld %lld", &g, &h);
		x.push_back(g * 2 + L);
		y.push_back(h * 2 + L);
	}
	x.push_back(x[0]);
	y.push_back(y[0]);

	long long s = 0;
	for (int i = 0; i < n; i++)
		s += det(i, i + 1);
	if (s > 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			swap(x[i], x[n - i - 1]);
			swap(y[i], y[n - i - 1]);
		}
		x.pop_back();
		y.pop_back();
		x.push_back(x[0]);
		y.push_back(y[0]);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		if (x[i] < x[i + 1])
			ans += calc(i, i + 1, 1);
		else
			ans -= calc(i, i + 1, -1);
	printf("%lld\n", ans);

	return 0;
}

