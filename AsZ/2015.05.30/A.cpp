#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

#define EPS 1e-8

using namespace std;

int cmp(double x, double y)
{
	if (x < y - EPS)
		return -1;
	if (x > y + EPS)
		return 1;
	return 0;
}

double a[60][60], b[60][60];
int P[30], W[30];
int n;

double solve()
{
	int aw = W[0];
	double p = 1.0 * P[0] / s;
	double q = 1.0 - p;
	for (int i = 1; i <= n; i++)
		a[i][i - 1] = q;
	for (int i = 1; i <= n; i++)
		a[i][min(i + aw, n + 1)] = p;
	for (int i = 1; i <= n; i++)
		a[i][i] -= 1.0;
	a[0][0] = a[n + 1][n + 1] = a[n + 1][n + 2] = 1.0;

	int m = n + 2;
	for (int i = 0; i < m; i++)
		for (int j = 0; j <= m; j++)
			b[i][j] = a[i][j];
	for (int i = 0; i < m; i++)
	{
		int k = i;
		while (k < m && cmp(b[k][i], 0.0) == 0)
			k++;
		if (k == m)
			while (1);
		for (int j = i; j <= m; j++)
			swap(b[i][j], b[k][j]);
		for (int g = 0; g < m; g++)
			if (g != i && cmp(b[g][i], 0.0))
			{
				double k = b[g][i] / b[i][i];
				for (int h = i; h <= m; h++)
					b[g][h] -= b[i][h] * k;
			}
	}
	return b[n][n + 2] / b[n][n];
}

int main() {
    ios :: sync_with_stdio(0);

    freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);

	int M, s;
	scanf("%d %d %d", &n, &M, &s);
	vector< pair <int , int> > sta;
	for (int i = 0; i < M; i++)
		scanf("%d %d", &P[i], &W[i]);

	for (int i = 1; i <= n; i++)
		ty[i] = 0;

	bool flag = true;
	while (flag)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < M; j++)
				ty[i] = j;

	}
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j <= m; j++)
//				printf("%f%c", a[i][j], " \n"[j == m]);
//		cout << endl;
	printf("%.10f", solve());

    return 0;
}
