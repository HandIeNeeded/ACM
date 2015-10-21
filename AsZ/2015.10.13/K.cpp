#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("kabaleo.in", "r", stdin);
    int n, m, c, h, res = 0;
    scanf("%d %d %d %d", &n, &m, &c, &h);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        s[i] = x;
        a[x] += 1;
        if (x != h)
            res++;
    }
    int cnt = a[h];
    for (int i = 0; i < m; i++)
        scanf("%d", &p[i]);
    if (p[0] == h)
    {
        int ins = 1;
        if (cnt == n)
            ins = 0;
        cnt = min(n, cnt + 1);
        if (cnt > res)
        {
            for (int i = 0; i < m; i++)
                if (p[i] != h)
                    a[p[i]]++, cnt--;
            int num = 0;
            for (int i = 1; i <= c; i++)
                if (i != h)
                {
                    if  (a[i] - full >= cnt)
                    {
                        printf("0\n");
                        return 0;
                    } else
                    if ()
                }
            printf()
        }
    }
    return 0;
}
