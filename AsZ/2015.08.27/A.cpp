#include <bits/stdc++.h>
#define MAXN 312345

using namespace std;

struct node
{
    int x, y;
    node (int tx = 0, int ty = 0, int n = 0)
    {
        if (tx > n) x = tx - n;
        else x = tx;
        if (ty > n) y = ty - n;
        else y = ty;
    }
} ans[MAXN];

int ansCnt, a[MAXN], ok;

int abs(int x)
{
    return x < 0 ? -x : x;
}

void getAns(int sta, int len, int n)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        int p = sta + i;
        if (sum == 1)
            ans[++ansCnt] = node(p - 1, p, n);
        else if (sum == -1)
            ans[++ansCnt] = node(p, p - 1, n);
        sum += a[p];
        if (abs(sum) >= 2)
        {
            ok = 0;
            return ;
        }
    }
    if (sum) ok = 0;
}

void workOne(int ave, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= ave;
        a[i + n] = a[i];
    }
    int twoOne = 0;
    int last = -2;
    for (int i = 1; i <= n * 2; ++i)
        if (a[i] != 0)
        {
            if (last == a[i])
            {
                getAns(i, n, n);
                return ;
            }
            last = a[i];
        }

    for (int i = 1; i <= n; ++i)
        if (a[i] != 0)
        {
            getAns(i, n, n);
            return ;
        }
}

void getAnsBefore(int l, int r, int n)
{
    if (l + 1 == r)
    {
        if (a[l] == a[r]) ok = 0;
        else
        {
            if (a[l] < 0)
            {
                ans[++ansCnt] = node(l + 1, l, n);
            } else  ans[++ansCnt] = node(l, l + 1, n);
        }
        return ;
   }
    if (a[l] == 2)
    {
        ans[++ansCnt] = node(l, l + 1, n);
        a[l + 1] += 1;
    } else
    {
        ans[++ansCnt] = node(l + 1, l, n);
        a[l + 1] -= 1;
    }

    if (a[r] == 2)
    {
        ans[++ansCnt] = node(r, r - 1, n);
        a[r - 1] += 1;
    } else
    {
        ans[++ansCnt] = node(r - 1, r, n);
        a[r - 1] -= 1;
    }

    for (int i = l + 1; i <= r - 1; ++i)
        if (abs(a[i]) > 1)
        {
            ok = 0;
            return ;
        }

    getAns(l + 1, (r - 1) - (l + 1) + 1, n);


}

void workTwo(int ave, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= ave;
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        if (abs(a[i]) == 2)
        {
            int last = i;
            for (int j = i + 1; j <= i + n && ok; ++j)
                if (abs(a[j]) == 2)
                {
                    getAnsBefore(last, j, n);
                    last = j;
                }
            return ;
        }
}

int main()
{
   // freopen("a.in", "r", stdin);
    int ca;
    for (scanf("%d", &ca); ca; --ca)
    {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            sum += a[i];
        }
        ok = 1;
        if (sum % n) ok = 0;
        int ave = sum / n;
        for (int i = 1; i <= n && ok; ++i)
            if (abs(a[i] - ave) >= 3)
                ok = 0;
        if (!ok)
        {
            printf("NO\n");
            continue;
        }
        ansCnt = 0;
        int flag = 1;
       for (int i = 1; i <= n; ++i)
            if (abs(a[i] - ave) == 2)
            {
                flag = 0;
                workTwo(ave, n);
                break;
            }
        if (flag)
        {
            for (int i = 1; i <= n; ++i)
                if (abs(a[i] - ave) == 1)
                {
                    workOne(ave, n);
                    flag = 0;
                    break;
                }
        }
        if (ok)
        {
            printf("YES\n");
            printf("%d\n", ansCnt);
            for (int i = 1; i <= ansCnt; ++i)
                printf("%d %d\n", ans[i].x, ans[i].y);
        } else printf("NO\n");
    }
    return 0;
}
