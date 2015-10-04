/* ***********************************************
Author        :CKboss
Created Time  :2015年08月03日 星期一 15时51分35秒
File Name     :HDOJ5338.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int maxn=100100;

int n;
int nb[maxn],wz[maxn];
int sed[maxn<<2];
int mx[maxn<<2];

#define lrt rt<<1
#define rrt rt<<1|1
#define lson l,m,lrt
#define rson m+1,r,rrt

void push_up(int rt)
{
	mx[rt]=max(mx[lrt],mx[rrt]);
}

void push_down(int rt)
{
	if(sed[rt])
	{
		mx[rrt]=mx[lrt]=0;
		sed[rrt]=sed[lrt]=0;
		sed[rt]=0;
	}
}

void build(int l,int r,int rt)
{
	sed[rt]=mx[rt]=0;
	if(l==r)
	{
		mx[rt]=nb[l];
		return ;
	}
	int m=(l+r)/2;
	build(lson); build(rson);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R) return mx[rt];

	push_down(rt);
	int m=(l+r)/2;
	int ret=0;
	if(L<=m) ret=max(ret,query(L,R,lson));
	if(R>m) ret=max(ret,query(L,R,rson));
	return ret;
}

void update(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		sed[rt]=1;
		mx[rt]=0;
		return ;
	}

	push_down(rt);
	int m=(l+r)/2;
	if(L<=m) update(L,R,lson);
	if(R>m) update(L,R,rson);
	push_up(rt);
}

void show(int l,int r,int rt)
{
	printf("%d: %d <----> %d mx: %d\n",rt,l,r,mx[rt]);
	if(l==r) return;
	int m=(l+r)/2;
	show(lson); show(rson);
}

int ans[maxn];
bool used[maxn];

int tree[maxn];

inline int lowbit(int x) { return x&(-x); }

void add(int p,int v=1)
{
	for(int i=p;i<maxn;i+=lowbit(i))
		tree[i]+=v;
}

int sum(int p)
{
	int ret=0;
	for(int i=p;i;i-=lowbit(i))
		ret+=tree[i];
	return ret;
}

int get_left(int x)
{
	int low=0,high=x-1;
	int ans=1,mid;

	int bz=sum(x);
	if(bz==0) return 0;

	while(low<=high)
	{
		mid=(low+high)/2;

		if(sum(mid)<bz)
		{
			low=mid+1;
		}
		else
		{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T_T;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(tree,0,sizeof(tree));

		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",nb+i);
			wz[nb[i]]=i;
			ans[i]=0; used[i]=0;
		}

		if(n==1)
		{
			printf("%d\n",nb[1]); continue;
		}

		build(1,n,1);

		for(int i=1;i<=n;i++)
		{

			if(ans[i]) continue;

			int left=0,right=0,self=0;

			/// link to self
			if(used[wz[i]]==false) self=i;

			/// link to right 
			if(wz[i]!=n)
			{
				int pright=wz[i]+1;
				if(used[pright]==false)
				{
					right=nb[pright];
				}
			}

			/// link to left
			if(wz[i]!=1)
			{
				int pleft=get_left(wz[i])+1;
				left=query(pleft,wz[i],1,n,1);
			}


			if(left>self||right>self)
			{
				if(right>left)
				{
					ans[i]=right;
					used[wz[right]]=true;
					update(wz[right],wz[right],1,n,1);
				}
				else
				{
					ans[i]=left;

					/// link circle
					for(int j=wz[left];j<wz[i];j++)
					{
						ans[nb[j]]=nb[j+1];
						used[j]=true;
					}
					used[wz[i]]=true;

					/// set mark
					add(wz[i]);
				}
			}
			else
			{
				ans[i]=self;
				used[wz[i]]=true;
				add(wz[i]);
			}
		}

		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],(i==n)?10:32);
	}
    
    return 0;
}
