#include <iostream>
#include <cstdio>
#include <cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define i64 long long
#define u32 unsigned int
using namespace std;
 
int C,Num=0;
 
const i64 MAX=500005;
bool tag[MAX];
int prime[MAX/10],cnt;
int p[MAX];
 
 
void init()
{
    int i,j;
    for(i=2;i<710;i++) if(!tag[i])
    {
        prime[cnt++]=i;
        for(j=i+i;j<710;j+=i) tag[j]=1;
    }
    for(i=2;i<MAX;i++)
    {
        for(j=0;j<cnt&&prime[j]<i;j++) if(i%prime[j]==0)
        {
            p[i]=p[i/prime[j]]+1;
            break;
        }
        if(!p[i]) p[i]++;
    }
}
 
struct node
{
    int v,next;
};
 
const int M=40005;
int a[M],b[MAX],n;
node edges[MAX];
int head[M],e;
 
 
void Add(int u,int v)
{
    edges[e].v=v;
    edges[e].next=head[u];
    head[u]=e++;
}
 
int match[M],opt[M],dx[M],dy[M],Q[M];
 
int BFS()
{
    int front=0,tail=0,flag=0,i,u,v;
    for(i=1;i<=n;i++) dx[i]=dy[i]=0;
    for(i=1;i<=n;i++) if(!opt[i]) Q[tail++]=i,dx[i]=1;
    while(front<tail)
    {
        u=Q[front++];
        for(i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].v;
            if(dy[v]) continue;
            dy[v]=dx[u]+1;
            if(!match[v]) flag=1;
            else
            {
                Q[tail++]=match[v];
                dx[match[v]]=dy[v]+1;
            }
        }
    }
    return flag;
}
 
int DFS(int u)
{
    int i,v,t;
    for(i=head[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].v;
        if(dy[v]!=dx[u]+1) continue;
        dy[v]=0;
        t=match[v];
        match[v]=u;opt[u]=v;opt[t]=0;
        if(!t||DFS(t))return 1;
        opt[u]=0;match[v]=t;opt[t]=v;
    }
    return 0;
}
 
int MaxMatch()
{
    int i,ans=0;
    for(i=1;i<=n;i++) opt[i]=match[i]=0;
    while(BFS())
    {
        for(i=1;i<=n;i++) if(!opt[i]&&DFS(i)) ans++;
    }
    return ans;
}
 
 
inline void read(int &x)
{
    char c;
    for(c=getchar();!(c>='0'&&c<='9');c=getchar());
    x=c-'0';
    while(c=getchar(),c>='0'&&c<='9') x=x*10+c-'0';
}
 
int main()
{
    init();
    for(scanf("%d",&C);C--;)
    {
        read(n);
        int i,j,k,t;
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
        {
            read(a[i]);
            b[a[i]]=i;
        }
        for(i=1;i<=n;i++) head[i]=-1;
        e=0;
        int pr[25],prNum;
        for(i=1;i<=n;i++)
        {
            t=a[i];
            prNum=0;
            for(j=0;j<cnt&&prime[j]*prime[j]<=t;j++) if(t%prime[j]==0)
            {
                pr[++prNum]=prime[j];
                while(t%prime[j]==0) t/=prime[j];
            }
            if(t>1) pr[++prNum]=t;
            for(j=1;j<=prNum;j++)
            {
                k=a[i]/pr[j];
                if(!b[k]) continue;
                if(p[a[i]]&1) Add(b[a[i]],b[k]);
                else Add(b[k],b[a[i]]);
 
            }
        }
        printf("Case #%d: %d\n",++Num,n-MaxMatch());
    }
    return 0;
}
