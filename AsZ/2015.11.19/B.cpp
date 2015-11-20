#include <bits/stdc++.h>

using namespace std;

char s[200200], str[200200];

int main()
{
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        scanf("%s", str);
        int n = strlen(str);
        bool flag;
        if (n % 2 == 0)
        {
            flag = true;
            for (int i = 0; flag && i < n; i++)
                if (str[i] == '1')
                    flag = false;
            printf("%s\n", flag ? "DIES" : "LIVES");
        } else
        if (n % 4 == 1)
        {
            flag = str[0] == '1';
            for (int i = 1; flag && i < n; i += 2)
                flag = (str[i] == '0') && (str[i + 1] == '1');
            printf("%s\n", flag ? "DIES" : "LIVES");
        } else
        {
            for (int i = 0; i < n; i++)
                str[i] -= '0';
            bool f = false;
            for (int k = 0; k < 100; k++)
            {
                for (int i = 0; i < n; i++)
                    if (i == 0)
                        s[i] = str[1];
                    else
                    if (i == n - 1)
                        s[i] = str[n - 2];
                    else
                        s[i] = str[i - 1] ^ str[i + 1];
                bool flag = true;
                for (int i = 0; flag && i < n; i++)
                    if (s[i])
                        flag = false;
                if (flag)
                {
                    f = true;
                    break;
                }
//                for (int i = 0; i < n; i++)
//                    printf("%d", s[i]);
//                printf("\n");
                for (int i = 0; i < n; i++)
                    str[i] = s[i];
            }
            printf("%s\n", f ? "DIES" : "LIVES");
        }
    }
    return 0;
}
