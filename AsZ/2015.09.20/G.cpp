#include <bits/stdc++.h>
#define MAXN 8
#define MAXSTA 851234
#define MAXM 4601234

using namespace std;

typedef int arrayN[MAXSTA];
int a[MAXN];
int wq[MAXN][MAXN];
vector <int> ans[MAXN];

int num;
arrayN fir, tAns;
//arrayM e, nxt;

int mi[MAXN];

/*void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}*/

void work(int n)
{
    for (int i = 0; i < wq[n][n]; ++i)
    {
        fir[i] = 0;
        tAns[i] = -1;
    }
    num = 0;
   /* for (int i = 0; i < wq[n][n]; ++i)
    {
        int tmp = i;
        for (int j = 0; j < n; ++j)
            mi[j] = n + 1;

        for (int j = 0; j < n; ++j)
        {
            int x = tmp % n;
            tmp /= n;
            mi[x] = min(mi[x], j);
        }

        for (int j = 0; j < n; ++j)
            if (mi[j] < n)
            {
                if (j && mi[j] < mi[j - 1])
                {
                    int tmp = i - wq[n][mi[j]] * j + wq[n][mi[j]] * (j - 1);
                    link(tmp, i);
                }
                if (j < n - 1 && mi[j] < mi[j + 1])
                {
                    int tmp = i - wq[n][mi[j]] * j + wq[n][mi[j]] * (j + 1);
                    link(tmp, i);
                }
            }
    } */

    int s = 0;
    for (int i = 0; i < n; ++i)
        s += i * wq[n][i];


    tAns[s] = 0;
    deque <int> deq;
    deq.push_back(s);

    for (;!deq.empty();)
    {
        int u = deq.front();
        int tmp = u;

        deq.pop_front();

        for (int j = 0; j < n; ++j)
            mi[j] = n + 1;

        for (int j = 0; j < n; ++j)
        {
            int x = tmp % n;
            tmp /= n;
            mi[x] = min(mi[x], j);
        }

        for (int j = 0; j < n; ++j)
            if (mi[j] < n)
            {
                if (j && mi[j] < mi[j - 1])
                {
                    int tmp = u - wq[n][mi[j]] * j + wq[n][mi[j]] * (j - 1);
                    //(tmp, i);

                    if (tAns[tmp] == -1)
                    {
                        tAns[tmp] = tAns[u] + 1;
                        deq.push_back(tmp);
                    }
                }
                if (j < n - 1 && mi[j] < mi[j + 1])
                {
                    int tmp = u - wq[n][mi[j]] * j + wq[n][mi[j]] * (j + 1);
                    //link(tmp, i);

                    if (tAns[tmp] == -1)
                    {
                        tAns[tmp] = tAns[u] + 1;
                        deq.push_back(tmp);
                    }
                }
            }


       // for (int p = fir[u]; p; p = nxt[p])
    }

    for (int i = 0; i < wq[n][n]; ++i)
        ans[n].push_back(tAns[i]);
}

int main()
{
   // freopen("g.in", "r", stdin);
    int T;
    for (int i = 1; i < MAXN; ++i)
    {
        wq[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            wq[i][j] = wq[i][j - 1] * i;
    }

    ans[0].push_back(0);
    ans[1].push_back(0);
    for (int i = 2; i < MAXN; ++i)
        work(i);
//    cout << (sizeof(e) * 2) / 1024/ 1024;
    for (scanf("%d", &T); T; --T)
    {
        int n;
        scanf("%d", &n);
        vector <int> vec;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            vec.push_back(a[i]);
        }
        sort(vec.begin(), vec.end());
        int sta = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
            sta += wq[n][x] * i;
        }
        cout << ans[n][sta] << endl;
    }
    return 0;
}
