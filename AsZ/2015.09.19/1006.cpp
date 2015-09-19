#include <bits/stdc++.h>
#define MAXN 1123456

using namespace std;

char st[MAXN];

int main()
{
   //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        scanf("%s", st);
        int len = strlen(st);
        int ans = 0;
        for (int i = 0; i < len; ++i)
            if (st[i] == 'c')
                ans++;
        if (ans != 0)
        {
            int bcnt = 0;
            int flag = 1;
            int lastCnt = 0;
            for (int i = 0; i < len; ++i)
            {
                if (st[i] == 'c')
                {
                    if (flag)
                    {
                        lastCnt = 0;
                        flag = 0;
                    } else
                    {
                        if (lastCnt <= 1)
                        {
                            ans = -1;
                            break;
                        } else lastCnt = 0;
                    }
                } else if (st[i] == 'f') 
                {
                    if (flag) bcnt++;
                    else lastCnt++;
                }
                else {
                    ans = -1;
                }
            }
            if (lastCnt + bcnt <= 1) ans = -1;
        } else ans = len / 2 + len % 2;
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
