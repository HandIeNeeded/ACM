#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define inf (1<<30)
#define eps 1e-8
#define pb push_back
using namespace std;
const int maxn=100005;
int n;
int d[maxn][15];
int main()
{
    int a;
   // memset(d,0,sizeof(d));
    while(~scanf("%d",&n)) {
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            int cnt=0;
            while(a) {
                d[i][cnt++]=a%10;
                a/=10;
            }
        }
        int tot=0;
        ll res=0;
        vector<int>vec;
        for(int i=0;i<10;i++) {
            vec.clear();
            for(int j=0;j<n;j++) {
                int u=0;
                for(int k=i;k>=0;k--)
                    u=u*10+d[j][k];
                vec.push_back(u);
            }
            ll v=1;
            for(int j=0;j<=i;j++)
                v*=10;
            sort(vec.begin(),vec.end());
            //cout<<vec[0]<<" "<<vec[1]<<endl;
            for(int j=0;j<vec.size();j++) {
                res+=vec.size()-(lower_bound(vec.begin()+j+1,vec.end(),v-vec[j])-vec.begin());
                //cout<<res<<endl;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
