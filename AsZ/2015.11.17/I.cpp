#include <bits/stdc++.h>

#define N 200
#define BIAS 20000

using namespace std;

int f[N][BIAS * 2 + 10];
bool vis[N][BIAS * 2 + 10];
int r[N], s[N], sum[N];
int n, A, B;

int dp(int i, int x)
{
    if (i == n || vis[i][x + BIAS])
        return f[i][x + BIAS];
    int t1 = sum[i + 1] - dp(i + 1, -min(x + r[i], 200)) + s[i];
    int t2 = dp(i + 1, max(x - 1 - r[i], -200));
    if (x > 0)
    {
        f[i][x + BIAS] = max(t1, t2);
    } else
    {
        f[i][x + BIAS] = t1;
    }
//    cout << i << " " << x << " " << f[i][x + BIAS] << endl;
    vis[i][x + BIAS] = true;
    return f[i][x + BIAS];
}

int main()
{
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &r[i], &s[i]);
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + s[i];
    int sub = A - B;
    if (sub > BIAS)
        sub = BIAS;
    if (sub < -BIAS)
        sub = -BIAS;
    int res = dp(0, sub);
    printf("%d %d\n", res, sum[0] - res);
    return 0;
}
