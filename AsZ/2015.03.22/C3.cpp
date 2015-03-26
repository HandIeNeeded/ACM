#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
int n,m;

int fa[300010];
int son[300010];
int dep[300010];
int num[300010];
int top[300010];
map <string,string> con[300010];
map <string,vector<int> > a[300010];
vector <int> so[300010];

void dfs1(int now,int d)
{
	int nu=so[now].size(),tt;
	dep[now]=d;
	for (int i=0; i<nu; i++)
	{
		tt=so[now][i];
		dfs1(tt,d+1);
		num[now]+=num[tt];
		if (son[now]==0 || num[tt]>num[son[now]]) son[now]=tt;
	}
}

void add_inf(int now,int topnode)
{
	for (auto i:con[now])
	{
		a[topnode][i.first].push_back(now);
	}
}

void dfs2(int now,int topnode)
{
	int nu=so[now].size(),tt;
	top[now]=topnode;
	add_inf(now,topnode);

	if (so[now].size()==0) return ;
	dfs2(son[now],topnode);
	for (int i=0; i<nu; i++)
	{
		tt=so[now][i];
		if (tt==son[now]) continue;
		dfs2(tt,tt);
	}
}

int find_node(int now,int en,string s)
{
	if (a[now].find(s)==a[now].end()) return 0;

	int len=a[now][s].size();

	if (en<dep[a[now][s][0]]) return 0;
	if (dep[a[now][s][len-1]]<=en) return a[now][s][len-1];

	int l=0,r=len-1,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (dep[a[now][s][mid]]<=en) l=mid+1;
		else r=mid-1;
	}

	for (int i=min(l+2,len-1); i>=max(0,l-2); i--)
	{
		if (dep[a[now][s][i]]<=en)
		{
			return a[now][s][i];
		}
	}

	return 0;
}

void find(int x,string s)
{
	if (x==0)
	{
		printf("N/A\n");
		return ;
	}
	int topnode=top[x];

	int tt=find_node(topnode,dep[x],s);
	if (tt!=0)
	{
		printf("%s\n",con[tt][s].c_str());
		return ;
	}
	else find(fa[topnode],s);
}

int main()
{
	int x,len,pos;
	int root;
	char s[10000];
	string s1,s2;

	cin>>n;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&fa[i],&x);
		if (fa[i]==0) root=i;
		so[fa[i]].push_back(i);

		gets(s);
		for (int j=1; j<=x; j++)
		{
			gets(s);
			len=strlen(s);
			for (int k=0; k<len; k++)
				if (s[k]=='=')
				{
					pos=k;
					break;
				}
			s1=s;
			s2=s1.substr(pos+1);
			s1=s1.substr(0,pos);
			con[i][s1]=s2;
		}
	}
	dfs1(root,1);
	dfs2(root,1);

	cin>>m;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%s",&x,&s);
		s1=s;
		find(x,s1);
		fflush(stdout);
	}
}
