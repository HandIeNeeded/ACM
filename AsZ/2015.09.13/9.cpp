#include <bits/stdc++.h>

#define N 50500
#define INF 0x3f3f3f3f

using namespace std;

int dp[N], p;

void calc(int v, int c, int s)
{
    int upper = min(p + 100 - v, s);
    for (int i = upper; i >= 0; i--)
        dp[i + v] = min(dp[i + v], dp[i] + c);
}

void calc1(int v, int c, int s)
{
    int upper = min(p - v, s);
//    cout << v << " " << c << " " << s << endl;
//    cout << upper << endl;
    for (int i = upper; i >= 0; i--)
    {
        if (dp[i] == -1)
            continue;
        dp[i + v] = max(dp[i + v], dp[i] + c);
    }
}

int main()
{
    freopen("9.in", "r", stdin);
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        int n, m;
        scanf("%d %d %d", &n, &m, &p);

        for (int i = 0; i <= p + 200; i++)
            dp[i] = INF;
        dp[0] = 0;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            for (int k = 1; k <= z; k <<= 1)
            {
                calc(x * k, y * k, sum);
                z -= k, sum += k * x;
            }
            if (z)
            {
                calc(x * z, y * z, sum);
                sum += z * x;
            }
        }

//        cout << endl;

        int minspace = INF;
        for (int i = p; i <= p + 100; i++)
            minspace = min(minspace, dp[i]);

        p = 50000, sum = 0;
        for (int i = 0; i <= p; i++)
            dp[i] = -1;
        dp[0] = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            for (int k = 1; k <= z; k <<= 1)
            {
                calc1(y * k, x * k, sum);
                z -= k, sum += k * y;
            }
            if (z)
            {
                calc1(y * z, x * z, sum);
                sum += z * y;
            }
        }

//        for (int i = 0; i <= 20; i++)
//            printf("%d%c", dp[i], " \n"[i == 20]);
        bool flag = false;
        for (int i = 0; i <= p; i++)
            if (dp[i] >= minspace)
            {
                printf("%d\n", i);
                flag = true;
                break;
            }
        if (!flag)
            printf("TAT\n");
    }
    return 0;
}
