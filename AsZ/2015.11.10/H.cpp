#include <bits/stdc++.h>

#define N 100100
#define ll long long

using namespace std;

ll f[1010], a[N];

int main()
{
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%x", a + i);
    for (int i = 0; i <= 1000; i++)
        f[i] = -1;
    f[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = min(i, 1000); j >= 0; j--)
        {
            if (f[j] != -1)
                f[j] = f[j] + 1LL * (a[i] ^ (i - j));
            if (j > 0 && f[j - 1] != -1)
                f[j] = max(f[j - 1], f[j]);
        }
    ll ans = 0;
    for (int i = 0; i <= 1000; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
}
