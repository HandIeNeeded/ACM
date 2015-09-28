#include <bits/stdc++.h>

using namespace std;

int c;

int pow_mod(int x, long long y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = 1LL * res * x % c;
        x = 1LL * x * x % c;
        y >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    int ti = 1;
    int k1, b1, k2;
    while (scanf("%d %d %d %d", &c, &k1, &b1, &k2) != EOF)
    {
        bool flag = true;
        cout << "Case #" << ti << ":" << endl;
        for (int a = 1; a < c; a++)
        {
            int b = (c - pow_mod(a, 1LL * k1 * b1)) % c;
            if (pow_mod(a, k1) != pow_mod(b, k2))
                continue;
            if (pow_mod(a, b1) != (c - pow_mod(pow_mod(b, k2 - 1), c - 2)) % c)
                continue;
            flag = false;
            cout << a << " " << b << endl;
        }
        if (flag)
            cout << "-1" << endl;
        ti++;
    }
    return 0;
}
