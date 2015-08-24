#include <bits/stdc++.h>
#define MAXN 1123456

using namespace std;

int a[MAXN];

int findcha(int n)
{
    int tmp = 2;
    for (int i = 1; i < n; )
    {
        int j = i + 1;
        for (; j + 1 <= n && (a[j + 1] - a[j] == a[j] - a[j - 1]); ++j);
        tmp = max(tmp, j - i + 1);
        i = j;
    }
    return tmp;
}

int findbi(int n)
{

    int tmp = 2;
    for (int i = 1; i < n; )
    {
        int j = i + 1;
        for (; j + 1 <= n && (1LL * a[j + 1] * a[j - 1] == 1LL * a[j] * a[j]); ++j);
        tmp = max(tmp, j - i + 1);
        i = j;
    }
    return tmp;
}

int main()
{
  //  freopen("b.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        int ans = max(findcha(n), findbi(n));
        if (n == 1) ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}
