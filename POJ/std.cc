#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;
const int V=440, E=V*2, maxint=0x3F3F3F3F;
struct etype
{
    int t, c, u;
    etype *next, *pair;
    etype() {}
    etype(int T, int C, int U, etype* N): t(T), c(C), u(U), next(N) {}
    void* operator new(size_t, void* p){return p;}
} *e[V], Te[E+E], *Pe;
int S, T, n, piS, cost;
bool v[V];
void addedge(int s, int t, int c, int u)
{
    e[s] = new(Pe++) etype(t, +c, u, e[s]);
    e[t] = new(Pe++) etype(s, -c, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}
int aug(int no, int m)
{
    if (no == T) return cost += piS * m, m;
    v[no] = true;
    int l = m;
    for (etype *i = e[no]; i; i = i->next)
        if (i->u && !i->c && !v[i->t])
        {
            int d = aug(i->t, l < i->u ? l : i->u);
            i->u -= d, i->pair->u += d, l -= d;
            if (!l) return m;
        }
    return m - l;
}
bool modlabel()
{
    static int d[V]; memset(d, 0x3F, sizeof(d)); d[T] = 0;
    static deque<int> Q; Q.push_back(T);
    while(Q.size())
    {
        int dt, no = Q.front(); Q.pop_front();
        for(etype *i = e[no]; i; i = i->next)
            if(i->pair->u && (dt = d[no] - i->c) < d[i->t])
                (d[i->t] = dt) <= d[Q.size() ? Q.front() : 0]
                    ? Q.push_front(i->t) : Q.push_back(i->t);
    }
    for(int i = 0; i < n; ++i)
        for(etype *j = e[i]; j; j = j->next)
            j->c += d[j->t] - d[i];
    piS += d[S];
    return d[S] < maxint;
}
int ab[V], *pab[V], w[V];
struct lt
{
    bool operator()(int* p1,int* p2) {return *p1 < *p2;}
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(e,0,sizeof(e));
        Pe = Te;
        static int m, k;
        scanf("%d %d", &m, &k);
        int abz = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", pab[abz] = &ab[abz]), abz++;
            scanf("%d", pab[abz] = &ab[abz]), abz++;
            scanf("%d", &w[i]);
        }
        sort(&pab[0], &pab[abz], lt());
        int c=0xDEADBEEF; n=0;
        for(int i = 0; i < abz; ++i)
        {
            if(c != *pab[i]) c = *pab[i], ++n;
            *pab[i] = n;
        }
        ++n, S = 0, T = n++;
        for(int i = 0; i < T; ++i) addedge(i, i+1, 0, k);
        for(int i = 0; i < m; ++i) addedge(ab[i+i], ab[i+i+1], -w[i], 1);
        piS = cost = 0;
        while(modlabel())
            do memset(v, 0, sizeof(v));
            while(aug(S, maxint));
        printf("%d\n", -cost);
    }
    return 0;
}
