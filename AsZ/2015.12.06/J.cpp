#include <bits/stdc++.h>

#define N 1010

using namespace std;

int a[N];
char s[N], ans[N];
int n, lim;

void gen()
{
    for (int i = 0; i < n; i++)
        s[i] = '0' + (rand() & 1);
}

void solve()
{
    int res, mark;
    for (int i = 0; i < n - 1; i++)
    {
        s[i] = (s[i] == '0') ? '1' : '0';
        s[i + 1] = (s[i + 1] == '0') ? '1' : '0';
        printf("%s\n", s);
        fflush(stdout);
        scanf("%d", &res);
        if (res == n)
            exit(0);
        if (res)
            a[i + 1] = 1;
        else
            a[i + 1] = 0;
        s[i] = (s[i] == '0') ? '1' : '0';
        s[i + 1] = (s[i + 1] == '0') ? '1' : '0';
    }

    for (int i = 0; i < n; i++)
        s[i] -= '0';

    ans[0] = 0;
    mark = ans[0] ^ s[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = s[i] ^ (mark ^ a[i]);
        mark = ans[i] ^ s[i];
    }
    for (int i = 0; i < n; i++)
        ans[i] += '0';
    printf("%s\n", ans);
    fflush(stdout);
    scanf("%d", &res);
    if (res == n)
        exit(0);

    ans[0] = 1;
    mark = ans[0] ^ s[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = s[i] ^ (mark ^ a[i]);
        mark = ans[i] ^ s[i];
    }
    for (int i = 0; i < n; i++)
        ans[i] += '0';
    printf("%s\n", ans);
    fflush(stdout);
}

int main() {

    scanf("%d", &n);
    lim = n + 501;

    bool flag = false;
    while (lim-- > n)
    {
        gen();
        printf("%s\n", s);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if (res == n)
            return 0;
        if (res)
        {
            flag = true;
            break;
        }
    }

    if (!flag)
        while (1);

    solve();

    return 0;
}
