#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
typedef long long ll;
char txt[maxn];
int sa[maxn],T1[maxn],T2[maxn],ct[maxn],he[maxn],rk[maxn],n,m,cut;
int mk[maxn];
ll f[maxn],ans;
void getsa(char *st)
{
    int i,k,p,*x=T1,*y=T2;
    for(i=0; i<m; i++) ct[i]=0;
    for(i=0; i<n; i++) ct[x[i]=st[i]]++;
    for(i=1; i<m; i++) ct[i]+=ct[i-1];
    for(i=n-1; i>=0; i--)
        sa[--ct[x[i]]]=i;
    for(k=1,p=1; p<n; k<<=1,m=p)
    {
        for(p=0,i=n-k; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0; i<m; i++) ct[i]=0;
        for(i=0; i<n; i++) ct[x[y[i]]]++;
        for(i=1; i<m; i++) ct[i]+=ct[i-1];
        for(i=n-1; i>=0; i--) sa[--ct[x[y[i]]]]=y[i];
        for(swap(x,y),p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
    }
}
void gethe(char *st)
{
    int i,j,k=0;
    for(i=0;i<n;i++) rk[sa[i]]=i;
    for(i=0;i<n-1;i++)
    {
        if(k) k--;
        j=sa[rk[i]-1];
        while(st[i+k]==st[j+k]) k++;
        he[rk[i]]=k;
    }
}
bool isok(ll p)
{
    int pos,len,i,pp,cnt;
    pos=lower_bound(f+1,f+1+n,p)-f;//定位sa
    len=he[pos]+p-f[pos-1];//确定串长
    for(i=0;i<n;i++)
        mk[i]=-1;
    if(n-sa[pos]>len)//看自己所属后缀是否要切
        mk[sa[pos]]=sa[pos]+len-1;
    for(i=pos+1;i<=n;i++)
    {
        if(he[i]==0)
            return false;
        len=min(len,he[i]);//lcp
        mk[sa[i]]=sa[i]+len-1;//排序比pos大一定要分割。
    }
    pp=n,cnt=0;
    for(i=0;i<n;i++)
    {
        if(mk[i]!=-1)//能不切先不切和后面的一起切。贪心的思想。
            pp=min(pp,mk[i]);
        if(pp==i)
        {
            cnt++;
            if(cnt>cut)
                return false;
            pp=n;
        }
    }
    return cnt<cut;//切cnt次就是cnt+1块。
}
int main()
{
    int i,pos,len;
    ll low,hi,mid;

    while(scanf("%d",&cut),cut)
    {
        scanf("%s",txt);
        n=strlen(txt)+1;
        m=128;
        getsa(txt);
        gethe(txt);
        n--;
        f[1]=n-sa[1];
        for(i=2;i<=n;i++)
            f[i]=f[i-1]+n-sa[i]-he[i];
        low=1,hi=f[n],ans=1;
        while(low<=hi)
        {
            mid=(low+hi)>>1;
            if(isok(mid))
                ans=mid,hi=mid-1;
            else
                low=mid+1;
        }
        pos=lower_bound(f+1,f+1+n,ans)-f;
        len=he[pos]+ans-f[pos-1];
        txt[sa[pos]+len]=0;
        printf("%s\n",txt+sa[pos]);
    }
    return 0;
}
