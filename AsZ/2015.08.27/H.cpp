#include <bits/stdc++.h>

#define N 100100

using namespace std;

int l[N], r[N], vis[N];
vector<int> a, q;
priority_queue< pair<int , int>, vector< pair<int , int> >, greater< pair<int , int> > > b;

bool cmp(int g, int h)
{
    return l[g] < l[h];
}

int main()
{
    freopen("H.in", "r", stdin);
    int ca, ti = 1;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &l[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &r[i]);

        a.clear();
        for (int i = 0; i < n; i++)
            a.push_back(i);
        sort(a.begin(), a.end(), cmp);

        q.clear();
        while (b.size())
            b.pop();
        int p = 0, cnt = 0;
        for (; cnt < n; cnt++)
        {
            while (p < n && l[a[p]] <= cnt)
            {
                b.push(make_pair(r[a[p]], a[p]));
                p++;
            }
            while (b.size() && b.top().first < cnt)
                b.pop();
            if (b.size())
            {
                q.push_back(b.top().second);
                b.pop();
                vis[q.back()] = ti;
            } else
                break;
        }
        for (int i = 0; i < n; i++)
            if (vis[i] < ti)
                q.push_back(i);
        printf("%d\n", cnt);
        for (int i = 0; i < n; i++)
            printf("%d%c", q[i] + 1, " \n"[i == n - 1]);
        ti++;
    }
    return 0;
}
