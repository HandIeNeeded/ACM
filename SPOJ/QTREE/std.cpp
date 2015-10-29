#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 10010;
struct Tedge
{ int b, next; } e[maxn * 2];
int tree[maxn << 2];
int zzz, n, z, edge, root, a, b, c;
int d[maxn][3];
int first[maxn], dep[maxn], w[maxn], fa[maxn], top[maxn], son[maxn], siz[maxn];
char ch[10];

void insert(int a, int b, int c)
{
     e[++edge].b = b;
     e[edge].next = first[a];
     first[a] = edge;
}

void dfs(int v)
{
     siz[v] = 1; son[v] = 0;
     for (int i = first[v]; i > 0; i = e[i].next)
         if (e[i].b != fa[v])
         {
             fa[e[i].b] = v;
             dep[e[i].b] = dep[v]+1;
             dfs(e[i].b);
             if (siz[e[i].b] > siz[son[v]]) son[v] = e[i].b;
             siz[v] += siz[e[i].b];
         }
}

void build_tree(int v, int tp)
{
     w[v] = ++ z; top[v] = tp;
     if (son[v] != 0) build_tree(son[v], top[v]);
     for (int i = first[v]; i > 0; i = e[i].next)
         if (e[i].b != son[v] && e[i].b != fa[v])
             build_tree(e[i].b, e[i].b);
}

void update(int root, int lo, int hi, int loc, int x)
{
     if (loc > hi || lo > loc) return;
     if (lo == hi)
     { tree[root] = x; return; }
     int mid = (lo + hi) / 2, ls = root * 2, rs = ls + 1;
     update(ls, lo, mid, loc, x);
     update(rs, mid+1, hi, loc, x);
     tree[root] = max(tree[ls], tree[rs]);
}

int maxi(int root, int lo, int hi, int l, int r)
{
     if (l > hi || r < lo) return 0;
     if (l <= lo && hi <= r) return tree[root];
     int mid = (lo + hi) / 2, ls = root * 2, rs = ls + 1;
     return max(maxi(ls, lo, mid, l, r), maxi(rs, mid+1, hi, l, r));
}

inline int find(int va, int vb)
{
     int f1 = top[va], f2 = top[vb], tmp = 0;
     while (f1 != f2)
     {
           if (dep[f1] < dep[f2])
           { swap(f1, f2); swap(va, vb); }
           tmp = max(tmp, maxi(1, 1, z, w[f1], w[va]));
           va = fa[f1]; f1 = top[va];
     }
     if (va == vb) return tmp;
     if (dep[va] > dep[vb]) swap(va, vb);
     return max(tmp, maxi(1, 1, z, w[son[va]], w[vb]));  //
}

void init()
{
     scanf("%d", &n);
     root = (n + 1) / 2;
     fa[root] = z = dep[root] = edge = 0;
     memset(siz, 0, sizeof(siz));
     memset(first, 0, sizeof(first));
     memset(tree, 0, sizeof(tree));
     for (int i = 1; i < n; i++)
     {
         scanf("%d%d%d", &a, &b, &c);
         d[i][0] = a; d[i][1] = b; d[i][2] = c;
         insert(a, b, c);
         insert(b, a, c);
     }
     dfs(root);
     build_tree(root, root);    //
     for (int i = 1; i < n; i++)
     {
         if (dep[d[i][0]] > dep[d[i][1]]) swap(d[i][0], d[i][1]);
         update(1, 1, z, w[d[i][1]], d[i][2]);
     }
}

inline void read()
{
     ch[0] = ' ';
     while (ch[0] < 'C' || ch[0] > 'Q') scanf("%s", ch);
}

void work()
{
     for (read(); ch[0] != 'D'; read())
     {
         scanf("%d%d", &a, &b);
         if (ch[0] == 'Q') printf("%d\n", find(a, b));
                      else update(1, 1, z, w[d[a][1]], b);
     }
}

int main()
{
    for (scanf("%d", &zzz); zzz > 0; zzz--)
    {
        init();
        work();
    }
    return 0;
}
