#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("standard.in", "r", stdin);
//    freopen("standard.out", "w", stdout);
    int p, v, la = 99;
    scanf("%d %d", &p, &v);
    int lp = 0, rp = p;
    int lv = 0, rv = v;
    for (int ti = 0; l < r && ti < la; ti++)
    {
        int m = (lp + rp) / 2;
        printf("check %d %d\n", lp, m);
        fflush(stdio);
        char str[5];
        scanf("%s", &str);
        if (str[0] == 'Y')
            rp = m;
        else
            lp = m + 1;

    }
    printf("answer %d\n", l);
}
