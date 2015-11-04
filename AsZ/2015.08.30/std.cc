#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define clr(a, x) memset(a, x, sizeof a)
using namespace std;

const int maxn=620;
const int oo=0x3f3f3f3f;
struct Edge
{
    int u, v, cap, flow, cost, nxt;
    Edge(int u, int v, int c, int f, int co, int nxt):u(u), v(v), cap(c), flow(f), cost(co), nxt(nxt) {}
    Edge() {}
};
struct MCMF
{
    int n, m, s, t;
    Edge edge[maxn*maxn+maxn];
    int head[maxn], tot;
    int inq[maxn], d[maxn], p[maxn], a[maxn];
    void init(int _n)
    {
        n=_n;
        tot=0;
        clr(head, -1);
    }
    void add(int u, int v, int cap, int cost)
    {
        edge[tot]=Edge(u, v, cap, 0, cost, head[u]);
        head[u]=tot++;
        edge[tot]=Edge(v, u, 0, 0, -cost, head[v]);
        head[v]=tot++;
    }
    bool spfa(int s, int t, int& flow, int& cost)
    {
        clr(d, 0x3f);
        clr(inq, 0);
        d[s]=0, inq[s]=1, p[s]=0, a[s]=oo;

        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            inq[u]=0;
            for(int i=head[u]; ~i; i=edge[i].nxt)
            {
                Edge& e=edge[i];
                if(e.cap>e.flow && d[e.v]>d[u]+e.cost)
                {
                    d[e.v]=d[u]+e.cost;
                    p[e.v]=i;
                    a[e.v]=min(a[u], e.cap-e.flow);
                    if(!inq[e.v])
                    {
                        q.push(e.v);
                        inq[e.v]=1;
                    }
                }
            }
        }
        if(d[t]==oo)return false;
        flow+=a[t];
        cost+=a[t]*d[t];
        int u=t;
        while(u!=s)
        {
            edge[p[u]].flow+=a[t];
            edge[p[u]^1].flow-=a[t];
            u=edge[p[u]].u;
        }
        return true;
    }
    int MinCost(int s, int t)
    {
        int flow=0, cost=0;
        int ans=0;
        while(spfa(s, t, flow, cost) && cost<ans)
            ans=cost;
        return ans;
    }
} net;

int tuner[maxn], lev[maxn], atk[maxn];
int val[maxn][maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m, s, t, ans=0;
        scanf("%d%d", &n, &m);
        net.init(n+m+10);
        s=0, t=n+1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d", tuner+i, lev+i, atk+i);
            if(tuner[i])net.add(s, i, 1, 0);
            else net.add(i, t, 1, 0);
            ans+=atk[i];
        }
        clr(val, 0);
        for(int k=1; k<=m; k++)
        {
            int l, a, r;
            scanf("%d%d%d", &l, &a, &r);
            if(r==0)
            {
                for(int i=1; i<=n; i++)if(tuner[i])
                        for(int j=1; j<=n; j++)if(!tuner[j])
                                if(lev[i]+lev[j]==l && atk[j]+atk[i]<a)
                                    val[i][j]=min(val[i][j], atk[i]+atk[j]-a);
            }
            else if(r==1)
            {
                int x;
                scanf("%d", &x);
                for(int i=1; i<=n; i++)
                    if(tuner[x]!=tuner[i] && lev[i]+lev[x]==l && atk[x]+atk[i]<a)
                    {
                        if(tuner[x])
                            val[x][i]=min(val[x][i], atk[x]+atk[i]-a);
                        else val[i][x]=min(val[i][x], atk[i]+atk[x]-a);
                    }
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                if(atk[x]+atk[y]>=a)continue ;
                if(tuner[x])
                    val[x][y]=min(val[x][y], atk[x]+atk[y]-a);
                else val[y][x]=min(val[y][x], atk[y]+atk[x]-a);
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(val[i][j]<0)
                    net.add(i, j, 1, val[i][j]);
        printf("%d\n", ans-net.MinCost(s, t));
    }
    return 0;
}
