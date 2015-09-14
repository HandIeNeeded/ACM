#include <bits/stdc++.h>

using namespace std;
const int lim = 50;

int main()
{
    srand(clock() % time(0));
    freopen("10.in", "w", stdout);
    int T = 5;
    printf("%d\n", T);
    int lim = 40;
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (int i = 1; i <= T; ++i)
    {
        int n = rand() % lim + 2;
        int m = rand() % n + 1;
        int k = rand() % 5 + 1;
        printf("%d %d %d\n", n, m, k + 1);
        for (int j = 0; j <= k; ++j)
            printf("%d ", p[j]);
        printf("\n");
    }
    return 0;
}
