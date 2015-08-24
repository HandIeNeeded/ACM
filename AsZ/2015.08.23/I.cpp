#include <bits/stdc++.h>
#define MAXN 112345

using namespace std;

char s[MAXN], t[MAXN];
int main()
{
  // freopen("I.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        scanf("%s", s);
        scanf("%s", t);
        int ls = strlen(s);
        int lt = strlen(t);
        int ok = 1;
        int ps = -1, pt = -1;
        for (; s[ps + 1] == s[0]; ps++);
        for (; t[pt + 1] == s[0]; pt++);
        if (s[0] != t[0]) ok = 0;
        if (ps < pt) ok = 0;
        if (ps > pt)
        {
            ps = pt;
        }
        for (++ps; ps < ls && ok; ++ps)
        {
            for (; pt < lt - 1 && t[pt + 1] != s[ps]; ++pt);
            if (pt + 1 < lt && t[pt + 1] == s[ps])
            {
                pt++;
            } else ok = 0;
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
