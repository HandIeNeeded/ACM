#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("B.in", "r", stdin);
    int n, m, x, y;
    while (scanf("%d %d %d %d", &n, &m, &x, &y) != EOF)
    {
        int L = y - 1, U = x - 1, R = m - y, D = n - x;
        int mini = min(min(L, R), min(U, D));
        bool same = L == U;
        same == same && L == R;
        same == same && L == D;
        if (same)
        {
            cout << L << endl;
            continue;
        }
        int ans = 0;
        if (L)
        {
            int tmp = L;
            tmp = min(tmp, U + 1);
            tmp = min(tmp, D + 1);
            ans = max(ans, tmp);
        }
        if (U)
        {
            int tmp = U;
            tmp = min(tmp, L + 1);
            tmp = min(tmp, R + 1);
            ans = max(ans, tmp);
        }
        if (R)
        {
            int tmp = R;
            tmp = min(tmp, U + 1);
            tmp = min(tmp, D + 1);
            ans = max(ans, tmp);
        }
        if (D)
        {
            int tmp = D;
            tmp = min(tmp, L + 1);
            tmp = min(tmp, R + 1);
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
