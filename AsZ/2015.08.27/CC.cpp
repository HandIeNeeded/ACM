#include <bits/stdc++.h>

using namespace std;

vector<int> a[11];
int k, n, m, mm;
int v[11];

void ERR()
{
    printf("NO\n");
}

void OUT()
{
    printf("YES\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i].size());
        for (int j = 0; j < a[i].size(); j++)
            printf("%d%c", a[i][j], " \n"[j == a[i].size() - 1]);
    }
}

void LAS()
{
    for (int i = 0; i < m; i++)
    {
        a[i].push_back(n - k * mm + i + 1);
        a[i].push_back(n - (k - 1) * mm - i);
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d %d", &n, &m);
        long long sum = 1LL * n * n(n + 1LL) / 2LL;
        long long por = sum / m;
        if (por * (long long)m  + int * int < sum)
        {
            ERR();
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            a[i].clear();
            v[i] = por;
        }
        mm = 2 * m;
        k = n / mm;
        int mo = n % mm;
        for (int g = 0; g < k - 1; g++)
            for (int i = 0; i < m; i++)
            {
                a[i].push_back(n - (g + 1) * mm + i + 1);
                v[i] -= a[i].back();
                a[i].push_back(n - g * mm - i);
                v[i] -= a[i].back();
            }
        if (k * mm == n)
        {
            LAS();
            OUT();
            continue;
        } else
        {
            if (mo == mm - 1)
            {
                LAS();
                for (int i = 0; i < m - 1; i++)
                {
                    a[i].push_back(mm - i - 2);
                    a[i].push_back(1 + i);
                }
                a[m - 1].push_back(mm - 1);
                OUT();
                continue;
            }
            bool flag = false;
            int maxi = min(n, n - (k - 1) * mm);
            for (int i = maxi; i > 0; i--)
            {
                for (int j = 0; j < m; j++)
                    if (v[j] >= i)
                    {
                        a[j].push_back(i);
                        v[j] -= i;
                        flag = true;
                        break;
                    }
                if (!flag)
                {
                    ERR();
                    break;
                }
            }
            if (flag)
                OUT();
        }
    }
    return 0;
}
