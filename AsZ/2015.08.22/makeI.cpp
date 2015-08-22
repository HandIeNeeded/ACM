#include <bits/stdc++.h>

using namespace std;

int random(int x)
{
    return abs(rand() * rand() * rand()) % x + 1;
}
int main()
{
    freopen("i.in", "w", stdout);
    int ca = 1;
    srand(clock() % time(0));
    printf("%d\n", ca);
    for (; ca; --ca)
    {
        int n = 5;
        int m = 5;
        printf("%d %d\n", n, m);
        for (int i = 2; i <= n; ++i)
        {
            printf("%d %d %d\n", i, random(i - 1), random(100));
        }
        for (int i = 1; i <= m; ++i)
        {
            printf("%d %d\n", random(2), random(n));
        }
    }
    return 0;
}
