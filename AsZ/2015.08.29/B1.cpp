#include <bits/stdc++.h>

using namespace std;

int main()
{
   //freopen("b.in", "r", stdin);
    int n, m, x, y;
    for (; scanf("%d%d%d%d", &n, &m, &x, &y) != EOF;)
    {
        if (n < m) swap(n, m), swap(x, y);
        if (m == 1)
        {
            printf("1\n");
            continue;
        }
        int ans0 = (m + 1) / 2, ans1, ans2;
        y = max(y, m - y + 1);
        x = max(x, n - x + 1);
        int h1 = x - 1;
        int h2 = n - x;

        int t1 = min(ans0, h1);
        int t2 = min(ans0, h2);
        int t0 = y - 1;
        if (x == n) t0 = 1;
        ans1 = max(t0, max(t1, t2));

        h1++, h2++;
        int ht = min(h1, h2);
        if (ht >= ans0) ans2 = ht;
        else ans2 = ans0;


        int ans = min(ans1, ans2);
        printf("%d\n", ans);
    }
    return 0;
}
