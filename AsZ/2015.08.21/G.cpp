#include <bits/stdc++.h>

using namespace std;

char str[200200];
int a[200200], f[2];

int main()
{
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        f[0] = 0;
        f[1] = -1;
        for (int i = 0; i < n; i++)
        {
            int t0 = 0, t1 = 0;
            switch (str[i])
            {
                case '0':
                    if (f[0] > -1)
                        t0 = max(t0, f[0]);
                    if (f[1] > -1)
                        t0 = max(t0, f[1] + a[i]);
                    t1 = -1;
                    break;
                case '1':
                    t0 = -1;
                    if (f[0] > -1)
                        t1 = max(t1, f[0] + a[i]);
                    if (f[1] > -1)
                        t1 = max(t1, f[1]);
                    break;
                case '?':
                    if (f[0] > -1)
                        t0 = max(t0, f[0]);
                    if (f[1] > -1)
                        t0 = max(t0, f[1] + a[i]);
                    if (f[0] > -1)
                        t1 = max(t1, f[0] + a[i]);
                    if (f[1] > -1)
                        t1 = max(t1, f[1]);
                    break;
            }
            f[0] = t0;
            f[1] = t1;
        }
        printf("Case #%d: %d\n", tt, max(f[0], f[1]));
    }
    return 0;
}
