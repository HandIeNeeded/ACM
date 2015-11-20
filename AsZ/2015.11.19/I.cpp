#include <bits/stdc++.h>

#define N 110
#define ll long long
#define MOD1 1000000007
#define MOD2 1000000009

using namespace std;

struct Hash
{
    ll x, y;
    Hash(ll x = 0, ll y = 0) : x(x), y(y) {}
    Hash operator + (Hash h)
    {
        return Hash((x + h.x) % MOD1, (y + h.y) % MOD2);
    }
    Hash operator * (Hash h)
    {
        return Hash((x * h.x) % MOD1, (y * h.y) % MOD2);
    }
    bool operator < (const Hash &h) const
    {
        return x < h.x || (x == h.x && y < h.y);
    }
};

Hash BIT = Hash(23, 37);
Hash E = Hash(1, 1);

ll a[N], b[N], c[N], num[N];

bool cmp(int i, int j)
{
    return a[i] * b[j] - a[j] * b[i] > 0;
}

int main()
{
ios:: sync_with_stdio(0);
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (a[i] < 0)
                a[i] = -a[i], b[i] = -b[i], c[i] = -c[i];
            num[i] = i;
        }

        sort(num, num + n, cmp);

        ll tot = 1;
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && a[num[i]] * b[num[j]] == a[num[j]] * b[num[i]])
                j++;
            tot += 1LL * (j - i) * (i + 1);
        }
//        cout << tot << endl;
        map<Hash , int> mp;
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;

            Hash hs;
            for (int j = 0; j < n; j++)
            {
                hs = hs * BIT;
                if (a[j] * x + b[j] * y  + c[j] > 0)
                {
                    hs = hs + E;
//                    printf("1");
                }
//                else printf("0");
            }
//            printf("\n");
            mp[hs]++;
        }
        if (int(mp.size()) < tot)
            printf("VULNERABLE\n");
        else
            printf("PROTECTED\n");
    }
    return 0;
}
