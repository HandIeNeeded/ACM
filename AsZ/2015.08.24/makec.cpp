#include <bits/stdc++.h>

using namespace std;

int random(int x)
{
    return abs(rand() * rand() * rand()) % x + 1;
}
int main()
{
    freopen("c.in", "w", stdout);
    srand(clock() % time(0));
    int ca = 10;
    for (int i = 1; i <= ca; ++i)
    {
        int n = 10;//100000;
        printf("%d\n", n);
        printf("%d", random(n - 2) + 1);
        for (int i = 2; i <= n; ++i)
            printf(" %d", random(i - 1));
        printf("\n");
    }
    return 0;
}
