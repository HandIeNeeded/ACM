#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MAXN 212345

using namespace std;


const double esp = 1e-10;

int a[MAXN], b[MAXN], g[MAXN], num[MAXN];
double ans[MAXN];
int n, A, B;

int com(int u, int v)
{
	return (a[u] * b[v] > a[v] * b[u]) || (a[u] * b[v] + a[v] * b[u] == 0 && (a[u] > a[v]));
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("burrito.in", "r", stdin);
	freopen("burrito.out", "w", stdout);
    scanf("%d%d%d", &n, &A, &B);
    REP(i, n)
    {
		scanf("%d%d%d", g + i, a + i, b + i);
		num[i] = i;
    }
	sort(num, num + n, com);
    double aSum = 0, bSum = 0;
    REP(j, n)
    {
		int i = num[j];
		if (a[i] == 0) break;
        if (bSum + b[i] * g[i] <= 1.0 * B + esp)
            {
                ans[i] = g[i];
                aSum += a[i] * g[i];
                bSum += b[i] * g[i];
            } else
            {
                double x = (B - bSum) * 1.0 / b[i];
                ans[i] = x;
                aSum += a[i] * x;
                bSum += b[i] * x;
            }
    }
    if (aSum <= A - esp)
    {
		printf("-1 -1\n");
		return 0;
    }

    printf("%.10lf %.10lf\n", aSum, bSum);
    REP(i, n)
    {
        printf("%.10lf%c", ans[i], " \n"[i == n - 1]);
    }
	return 0;
}
