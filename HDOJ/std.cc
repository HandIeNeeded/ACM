#include <bits/stdc++.h>
#define MAXN 212345

using namespace std;

typedef int arrayN[MAXN];

arrayN a, b, g, ml, gol;
const int lim = (-5) * MAXN;
int high, base, now;

struct segment
{
    int lazy;
    int mx;
} seg[MAXN * 4];

void palindrome(int n, int p[])
{
    memset(p, 0, sizeof(p));
    int mx = 0, id = 0;
    for (int i = 1; i < n; ++i)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (b[i + p[i]] == b[i - p[i]]) p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }
}

struct node
{
    int a;
    int pos;
    node (int a = 0, int pos = 0) : a(a), pos(pos) {}
};

void add(int &u, int v)
{
    u += v;
    if (u < lim) u = lim;
}

void dropLazy(int x, int v)
{
    add(seg[x].lazy, v);
    add(seg[x].mx, v);
}

void pushdown(int x)
{
    for (int i = high - 1; i >= 1; --i)
    {
        int p = (x >> i);
        if (seg[p].lazy)
        {
            dropLazy(p << 1, seg[p].lazy);
            dropLazy(p << 1 ^ 1, seg[p].lazy);
            seg[p].lazy = 0;
        }
    }
}

void update(int x)
{
    for (x >>= 1; x; x >>= 1)
    {
        seg[x].mx = max(seg[x << 1].mx, seg[x << 1 ^ 1].mx);
    }
}

void dye(int l, int r, int v)
{
    if (l < 0) l = 0;
    if (l > r) return;
    l++, r++;
    l += base - 1;
    r += base + 1;
    pushdown(l);
    pushdown(r);
    int ll = l, rr = r;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
        if (!(l & 1)) dropLazy(l + 1, v);
        if (r & 1) dropLazy(r - 1, v);
    }
    update(ll);
    update(rr);
}

int ask(int l, int r)
{
    if (l < 0) l = 0;
    if (l > r) return -1;
    l++, r++;
    l += base - 1;
    r += base + 1;
    pushdown(l);
    pushdown(r);
    int tmp = -1;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
        if (!(l & 1)) tmp = max(tmp, seg[l + 1].mx);
        if (r & 1) tmp = max(tmp, seg[r - 1].mx);
    }
    return tmp;
}

void change(int x, int v)
{
    x++;
    x += base;
    pushdown(x);
    seg[x].mx = v;
    seg[x].lazy = 0;
    for (x >>= 1; x; x >>= 1)
    {
        seg[x].mx = max(seg[x << 1].mx, seg[x << 1 ^ 1].mx);
    }
}
int check(int x, int n)
{
    int last = -1;
    int ok = 0;
    ++now;
   // memset(seg, 0, sizeof(seg));
    dye(0, n + 1, lim);
    for (int i = 0; i < n && !ok; ++i)
        if (a[i] >= x)
        {
            if (last == -1)
            {
                change(i, a[i]);
                last = i;
                continue;
            }
            dye(0, i - 1, last - i);
            int tmp = ask(i - a[i], i - x);
            if (tmp >= 0) ok = 1;
            change(i, a[i]);
            last = i;
        }
    return ok;
}

int solve(int n)
{
    int l = 0, r = n / 3;
    for (; l < r; )
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid, n)) l = mid;
        else r = mid - 1;
    }
    return l;
}


int main()
{
  //  freopen("C.in", "r", stdin);
  //  freopen("cmy.out", "w", stdout);
    int ca;
    scanf("%d", &ca);
    for (int t = 1; t <= ca; ++t)
    {
        int n;
        scanf("%d", &n);
        int tot = 0;
        b[tot++] = -2;
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf("%d", &x);
            b[tot++] = -1;
            b[tot++] = x;
        }
        b[tot++] = -1;
        b[tot++] = -3;
        palindrome(tot, ml);
        for (base = 1, high = 1; base <= n + 5; base <<= 1, high++);
        for (int i = 3, j = 0; i <= tot - 2; i += 2, j++)
        {
            a[j] = ml[i];
            if (b[i - ml[i] + 1] == -1)
                --a[j];
            a[j] /= 2;
        }

        int ans = solve(n);
     //   for (int i = 0; i < n; ++i)
     //       printf("%d ", a[i]);
      //  printf("\n");
        printf("Case #%d: %d\n", t, ans * 3);
    }
    return 0;
}
