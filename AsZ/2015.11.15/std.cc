#include <stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
char s1[120],s2[120];
int endd=6*6*6*6*6*6,to[10],ans,num[10][10],tot[10];
bool used[10],vis1[10],vis2[10],ishere[10];
int dfs(int u)
{
 vis1[u]=1;
 if(to[u]==u||vis2[u])
 {
     vis2[u]=1;
     return 0;
 }
 if(vis1[to[u]]&&!vis2[to[u]])
        {vis2[u]=1;
            return 1;}

    int res= dfs(to[u]);
    vis2[u]=1;
    return res;
}
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        ans=0;
    int length=strlen(s1);
    for(int i=0;i<6;i++)
        {tot[i]=0;
            for(int j=0;j<6;j++)
        num[i][j]=0;
        }
    for(int i=0;i<length;i++)
       {
           num[s1[i]-'1'][s2[i]-'1']++;
           ishere[s2[i]-'1']=1;
       }
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
            tot[j]+=num[i][j];
    for(int i=0;i<length;i++)
        if(s1[i]!=s2[i])
        ans++;
        for(int i=0;i<endd;i++)
        {
            int cur=0,res=0;
            for(int j=0;j<6;j++)
                {vis1[j]=vis2[j]=used[j]=ishere[j]=0;
               }
            for(int j=i,k=0;k<6;j/=6,k++)
            {
                if(!used[j%6])
                {
                    used[j%6]=1;
                    cur++;
                }
                to[k]=j%6;
                ishere[j%6]=1;
                if(k!=to[k])
                    res++;
            }
            if(i==1944)
                int u=0;
            if(cur<6)
            {for(int j=0;j<6;j++)
        if(ishere[j]==0)
            dfs(to[j]);
                for(int j=0;j<6;j++)
                {res+=dfs(j)+tot[j]-num[to[j]][j];}

            ans=min(ans,res);
            if(ans==7)
                int u=0;
                }
        }
    printf("%d\n",ans);
    }
}
