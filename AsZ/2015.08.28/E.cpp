#include <bits/stdc++.h>

using namespace std;

double a[100] = {0, 1312, 2372.3, 520.2, 932, 800.6, 1086.5, 1402.3, 1313.9, 1681, 2080.7, 495.8, 737.7, 577.5, 786.5, 1011.8, 999.6, 1251.2, 1520.6};

int main()
{
    //freopen("in.txt", "r", stdin);
    a[35] = 1139.9;
    a[36] = 1350.8;
    a[53] = 1008.4;
    a[54] = 1170.4;
    a[85] = 890 + 40; //890 - 40
    a[86] = 1037;
    int u, v;
    for (; scanf("%d%d", &u, &v) != EOF; )
    {
        if (a[u] > a[v]) printf("FIRST BIGGER\n");
        else printf("SECOND BIGGER\n");
    }
    return 0;
}
