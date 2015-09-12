#include <bits/stdc++.h>
#define MAXN 211

using namespace std;

int n;
char st[MAXN];

int main()
{
   // freopen("in.txt", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n;
        scanf("%d\n", &n);
        scanf("%s", st);
        int ans = 0;
        for (;;)
        {
            int flag = 1;
            for (int i = 1; i <= n - 2; ++i)
            {
                if (st[i - 1] == st[i + 1])
                {
                    flag = 0;
                    ans += 2;

                    st[i - 1] = st[i];
                    n -= 2;
                    for (int j = i; j < n; ++j)
                        st[j] = st[j + 2];
                    break;
                }
            }
            if (flag) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
