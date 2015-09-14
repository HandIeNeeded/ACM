#include <bits/stdc++.h>
#define MAXN 112345678

using namespace std;
const int lim = 50;

long long a[MAXN];
int main()
{
   // freopen("3.in", "r", std);
    long long lim = (int) 1e9;//271303737385189LL;
    a[1] = 1;
    a[2] = a[3] = 2;
    long long sum = 3;
    long long n = 3;
    long long s1 = a[1] + a[2] + a[3];
    for (int i = 3; ; i++)
    {
        for (int j = 1; j <= a[i]; ++j)
        {
            a[++n] = i;
            s1 += a[n];
            sum += 1LL * n * a[n];
         }
        if (s1 >= lim) break;
    }
    cout << n << endl << sum << endl;
    return 0;
}
