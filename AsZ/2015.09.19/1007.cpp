#include <bits/stdc++.h>
#define MAXN 555

using namespace std;
typedef long long ll;

int n, mo;
const int tc[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll dpA[MAXN][2][2][2]; // n, have to not end?, havt to not end?, , jinwei?
ll dpS[MAXN][2][2];// trickcnt, have to not end, if jinwei

void add(ll &u, ll v)
{
    u += v;
    u %= mo;
}

ll dpAll() //
{
    memset(dpA, 0, sizeof(dpA));
    dpA[0][0][0][0] = 1;
    dpA[0][1][1][0] = 1;
   // dpA[3 * tc[0]][0][0][0] = 1;
   // dpA[tc[0]][1][0][0] = 1;
   // dpA[tc[0]][0][1][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        //dpA[i][0][0][0]
        //dpA[i][0][0][1]
        add(dpA[i + tc[1]][0][0][0], dpA[i][0][0][1]);
        //dpA[i][0][1][0]
        //dpA[i][0][1][1]


        for (int k = 0; k <= 1; ++k)
        {
            for (int x = 1; x <= 9; ++x)
            {
                int p = x + k;
                int jw = p / 10;
                p %= 10;
                int ni = i + tc[x] + tc[p];
                add(dpA[ni][0][0][jw], dpA[i][0][1][k]);
                add(dpA[ni][0][1][jw], dpA[i][0][1][k]);
            }
            int ni = i + tc[0] + tc[k];
            add(dpA[ni][0][1][0], dpA[i][0][1][k]);
        }

        //dpA[i][1][0][0]
        //dpA[i][1][0][1]



        for (int k = 0; k <= 1; ++k)
        {
            for (int x = 1; x <= 9; ++x)
            {
                int p = x + k;
                int jw = p / 10;
                p %= 10;
                int ni = i + tc[x] + tc[p];
                add(dpA[ni][0][0][jw], dpA[i][1][0][k]);
                add(dpA[ni][1][0][jw], dpA[i][1][0][k]);
            }
            int ni = i + tc[0] + tc[k];
            add(dpA[ni][1][0][0], dpA[i][1][0][k]);
        }

        //dpA[i][1][1][0]
        //dpA[i][1][1][1]

        for (int k = 0; k <= 1; ++k)
        {
            // x != 0, y != 0
            for (int x = 0; x <= 9; ++x)
                for (int y = 0; y <= 9; ++y)
                {
                    int p = x + y + k;
                    int jw = p / 10;
                    p %= 10;
                    int ni = i + tc[x] + tc[y] + tc[p];
                    if (x != 0 && y != 0)
                    {
                        for (int t1 = 0; t1 <= 1; ++t1)
                            for (int t2 = 0; t2 <= 1; ++t2)
                                add(dpA[ni][t1][t2][jw], dpA[i][1][1][k]);
                    } else if (x == 0 && y == 0)
                    {
                        add(dpA[ni][1][1][jw], dpA[i][1][1][k]);
                    } else if (x == 0)
                    {
                        for (int t2 = 0; t2 <= 1; ++t2)
                            add(dpA[ni][1][t2][jw], dpA[i][1][1][k]);
                    } else
                    {
                        for (int t1 = 0; t1 <= 1; ++t1)
                            add(dpA[ni][t1][1][jw], dpA[i][1][1][k]);
                    }
                }
        }

    }
    return dpA[n][0][0][0] % mo;
}

ll dpSame()
{
    memset(dpS, 0, sizeof(dpS));
    dpS[0][0][0] = 1;
    dpS[0][1][0] = 1;
   // dpS[3 * tc[0]][0][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        //dpS[i][0][0]
        //dpS[i][0][1]
        add(dpS[i + tc[1]][0][0], dpS[i][0][1]);

        //dpS[i][1][0/1]
        for (int k = 0; k <= 1; ++k)
        {
            for (int x = 1; x <= 9; ++x)
            {
                int p = 2 * x + k;
                int jw = p / 10;
                p %= 10;
                int ni = i + 2 * tc[x] + tc[p];
                add(dpS[ni][0][jw], dpS[i][1][k]);
                add(dpS[ni][1][jw], dpS[i][1][k]);
            }
            int ni = i + 2 * tc[0] + tc[k];
            add(dpS[ni][1][0], dpS[i][1][k]);
        }
    }
    return dpS[n][0][0] % mo;
}

int calc(int x)
{
    if (x == 0) return tc[0];
    int tmp = 0;
    for (;x;)
    {
        tmp += tc[x % 10];
        x /= 10;
    }
    return tmp;
}

int main()
{
   // freopen("7.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        scanf("%d%d", &n, &mo);
        n -= 3;
        ll ans = (dpAll()) % mo; //- dpSame() + mo) % mo;

       /* int tmp = 0;
        for (int i1 = 1; i1 <= 200; ++i1)
            for (int i2 = 1; i2 <= 200; ++i2)
            {
                int j = i1 + i2;
                if (calc(i1) + calc(i2) + calc(j) == n)
                {
                    printf("%d + %d = %d\n", i1, i2, j);
                    if (i1 == i2) tmp ++;
                }
            }

        cout << tmp << endl; */

        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
