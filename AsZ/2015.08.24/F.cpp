#include <bits/stdc++.h>

using namespace std;

int a[10][10], b[10][10], c[10][10];

int main()
{
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        a[n / 2 - 1][i] = a[n / 2][i] = 1;
        a[i][n / 2 - 1] = a[i][n / 2] = 1;
    }
    for (int i = 0; i < n; i++)
        b[i][i] = 1;
    int m = 6;
    for (int t = 0; t < m; t++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                b[i][j] = c[i][j];
                printf("%d%c", b[i][j], " \n"[j == n - 1]);
            }
        printf("\n");
    }
    return 0;
}
