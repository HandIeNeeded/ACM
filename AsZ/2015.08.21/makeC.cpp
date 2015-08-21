#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("C.in", "w", stdout);
    int ca = 2;
    srand(clock() % time(0));
    printf("%d\n", ca);
    int n = 100;
    for (; ca; --ca)
    {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", rand() % 2 + 1);
        printf("\n");
    }
    return 0;
}
