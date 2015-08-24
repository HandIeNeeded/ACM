#include <bits/stdc++.h>

#define N 60
#define MOD 2015

using namespace std;

struct Mat
{
    int n;
    int a[N][N];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    int* operator [] (int i)
    {
        return a[i];
    }
    Mat operator * (Mat b)
    {
        Mat res;
        res.n = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < n; k++)
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        return res;
    }
};

int main()
{
    freopen("F.in", "r", stdin);
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        Mat t;
        t.n = n + 1;
        for (int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                int x;
                scanf("%d", &x);
                t[i][x - 1] = 1;
            }
        }
        for (int i = 0; i <= n; i++)
            t[i][n] = 1;
        Mat ans;
        ans.n = n + 1;
        for (int i = 0; i <= n; i++)
            ans[i][i] = 1;
        m--;
        while (m)
        {
            if (m & 1)
                ans = ans * t;
            t = t * t;
//        for (int i = 0; i <= n; i++)
//            for (int j = 0; j <= n; j++)
//                printf("%d%c", ans[i][j], " \n"[j == n]);
//            printf("\n");
//        for (int i = 0; i <= n; i++)
//            for (int j = 0; j <= n; j++)
//                printf("%d%c", t[i][j], " \n"[j == n]);
            m >>= 1;
        }
        int res = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < n; j++)
                res = (res + ans[j][i]) % MOD;
        printf("%d\n", (res + 1) % MOD);
    }
    return 0;
}
