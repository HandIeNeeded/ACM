#include <bits/stdc++.h>
#define MAXN 612345

using namespace std;

int a[MAXN];

int main()
{
    freopen("in.txt", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n, m, z, l;
        scanf("%d%d%d%d", &n, &m, &z, &l);
        a[1] = 0;
        for (int i = 2; i <= n; ++i)
            a[i] = (1LL * a[i - 1] * m + z) % l;
        int ans1 = 0;
        for (int i = 1; i <= n; ++i)
            ans1 ^= 2 * a[i];
        cout << ans1 << endl;
        int ans2 = 0;
       /* for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                ans2 ^= a[i] + a[j];
        cout << ans2 << endl;*/
    }
    return 0;
}
