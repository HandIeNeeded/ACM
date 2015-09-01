#include <bits/stdc++.h>

using namespace std;

vector<int> a[11];
int k, n, m, mm;

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
        long long sum = 1LL * n * (n + 1LL) / 2LL;
        long long por = sum / m;
        if (por * (long long)m < sum)
        {
            ERR();
            continue;
        }
        for (int i = 0; i < m; i++)
            a[i].clear();
        mm = 2 * m;
        k = n / mm;
        for (int g = 0; g < k - 1; g++)
            for (int i = 0; i < m; i++)
            {
                a[i].push_back(n - (g + 1) * mm + i + 1);
                a[i].push_back(n - g * mm - i);
            }
        if (k * mm == n)
        {
            LAS();
            OUT();
            continue;
        } else
        {
            bool flag = false;
            int mo = n % mm;
            switch (m)
            {
                case 2:
                    a[0].push_back(1);
                    a[0].push_back(2);
                    a[1].push_back(3);
                    flag = true;
                    break;
                case 3:
                    if (mo == 2)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 2; i++)
                        {
                            a[i].push_back(8 - i);
                            a[i].push_back(4 + i);
                        }
                        for (int i = 1; i < 4; i++)
                            a[2].push_back(i);
                        a[2].push_back(6);
                    } else
                    if (mo == 3)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 2; i++)
                        {
                            a[i].push_back(9 - i);
                            a[i].push_back(6 + i);
                        }
                        for (int i = 1; i < 6; i++)
                            a[2].push_back(i);
                    } else
                    if (mo == 5)
                    {
                        LAS();
                        for (int i = 0; i < 2; i++)
                        {
                            a[i].push_back(4 - i);
                            a[i].push_back(1 + i);
                        }
                        a[2].push_back(5);
                    }
                    flag = true;
                    break;
                case 4:
                    for (int i = 0; i < 3; i++)
                    {
                        a[i].push_back(6 - i);
                        a[i].push_back(1 + i);
                    }
                    a[3].push_back(7);
                    flag = true;
                    break;
                case 5:
                    if (mo == 4)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 4; i++)
                        {
                            a[i].push_back(14 - i);
                            a[i].push_back(7 + i);
                        }
                        for (int i = 1; i < 7; i++)
                            a[4].push_back(i);
                        flag = true;
                        break;
                    } else
                    if (mo == 5)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            a[i].push_back(15 - i);
                            a[i].push_back(9 + i);
                        }
                        for (int i = 4; i < 13; i += 4)
                            a[3].push_back(i);
                        for (int i = 1; i < 8; i++)
                            if (i != 4)
                                a[4].push_back(i);
                    } else
                    if (mo == 9)
                    {
                        LAS();
                        for (int i = 0; i < 4; i++)
                        {
                            a[i].push_back(8 - i);
                            a[i].push_back(1 + i);
                        }
                        a[4].push_back(9);
                    }
                    flag = true;
                    break;
                case 6:
                    if (mo == 3)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 5; i++)
                        {
                            a[i].push_back(15 - i);
                            a[i].push_back(5 + i);
                        }
                        for (int i = 1; i < 5; i++)
                            a[5].push_back(i);
                        a[5].push_back(10);
                    } else
                    if (mo == 8)
                    {
                        if (!k)
                        {
                            flag = false;
                            break;
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            a[i].push_back(20 - i);
                            a[i].push_back(15 + i);
                        }
                        a[3].push_back(14);
                        a[3].push_back(13);
                        a[3].push_back(8);
                        for (int i = 3; i < 13; i++)
                            if (i != 6)
                                a[4].push_back(i);
                        a[4].push_back(11);
                        for (int i = 1; i < 8; i++)
                            if (i != 3)
                                a[5].push_back(i);
                        a[5].push_back(10);
                    } else
                    if (mo == 11)
                    {
                        LAS();
                        for (int i = 0; i < 5; i++)
                        {
                            a[i].push_back(10 - i);
                            a[i].push_back(1 + i);
                        }
                        a[5].push_back(11);
                    }
                    flag = true;
                    break;
                case 7:
                    if (mo == 6)
                    {

                    }
                case 8:
                case 9:
                case 10:
            }
        }
    }
    return 0;
}
