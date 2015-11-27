#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define inf 0x7fffffff
#define maxn 4050
ll a[maxn],b[maxn];
ll sum[maxn][2];//sum[i][u]表示前i层楼，性别为u的总人数
ll dsum[maxn][2];//dsum[i][u]表示前i层楼，性别为u者距离0层的距离之和
ll dp[maxn][2];//dp[i][u]表示第i层为u属性，第i+1层为另一属性，前i层不同性别到达自己的最近属性的寝室的最近距离和

ll goup(int l,int r,int sex){   //表示[l+1,r]区间sex性别要去r+1的总距离
    return (sum[r][sex]-sum[l][sex])*(r+1)-(dsum[r][sex]-dsum[l][sex]);
}

ll godown(int l,int r,int sex){  //表示[l+1,r]区间sex性别要去l的总距离
    return dsum[r][sex]-dsum[l][sex]-(sum[r][sex]-sum[l][sex])*l;
}

ll cnt(int l,int r,int sex){   //在[l,r]都是sex属性，且l-1与r+1都为非sex属性的条件下。 [l,r]这些楼层非sex属性的人，去自己属性寝室的最小距离。
    int mid=(l+r)>>1;
    return godown(l-1,mid,sex)+goup(mid,r,sex);
}
int main()
{
    int n,m,i,j,T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum[0][0]=sum[0][1]=0;
        dsum[0][0]=dsum[0][1]=0;
        for(i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
            sum[i][0]=sum[i-1][0]+a[i];
            sum[i][1]=sum[i-1][1]+b[i];
            dsum[i][0]=dsum[i-1][0]+a[i]*i;
            dsum[i][1]=dsum[i-1][1]+b[i]*i;
        }
        memset(dp,0,sizeof(dp));
        ll ans=1e18;
        for(i=1;i<n;i++){
            dp[i][0]=goup(0,i,1);  //这里先假设前i层都是性别0，i+1层是性别1所要的总距离
            dp[i][1]=goup(0,i,0);
            for(j=1;j<i;j++){
                dp[i][0]=min(dp[i][0],dp[j][1]+cnt(j+1,i,1)   ); //依次使得前j层是1，使得第j,i+1都是1，这样就好状态转移了
                dp[i][1]=min(dp[i][1],dp[j][0]+cnt(j+1,i,0)   );
            }
            ans=min(ans,dp[i][0]+godown(i,n,0)  ); //这里每一层都要更新一下ans，而不能最后才更新，因为最后才更新的话就不能使得后面几层都相同了
            ans=min(ans,dp[i][1]+godown(i,n,1)  );
        }
        cas++;
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
