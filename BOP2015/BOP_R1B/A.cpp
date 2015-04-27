#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

#define LL unsigned long long

LL dp[50][520];   //表示前i个系中，有j个空位使得该空位旁边为同一个系的位置数 
LL C[520][520];      //先求出组合数，然后再求出排列数
LL A[520];       //A[i]表示i个元素的全排列
int a[50];
map<char, int> mp;

void Init(){
    C[0][0]=1;
    for(int i=1;i<480;i++){     //求出组合数 
        C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j]);
        C[i][i]=1;
    }
    A[0]=A[1]=1;
    for(int i=2;i<480;i++)
        A[i]=(A[i-1]*i);
	REPP(i, 2, 9) {
		mp['0' + i] = i;
	}
	mp['T'] = 10, mp['J'] = 11, mp['Q'] = 12, mp['K'] = 13, mp['A'] = 1;
}

string s[60];

int main(){
    //freopen("input.txt","r",stdin);
    Init();
    int t,n,cases=0;
	cin >> t;
    while(t--){
		cin >> n;
        for(int i=1;i<=n;i++)
			cin >> s[i], a[mp[s[i][0]]]++;
		n = 13;
        memset(dp,0,sizeof(dp));
        dp[1][a[1]-1]=1;    //这样的组合数有一个 
        LL sum=a[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<sum;j++)  //对每一种空位  
                for(int k=1;k<=a[i];k++)    //将a[i]个元素分成k组 
                    for(int u=0;u<=j && u<=k;u++)   //将u组放到前j个空位中
                        dp[i][j-u+a[i]-1-(k-1)]=(dp[i][j-u+a[i]-k]+(((dp[i-1][j]*C[j][u])*C[sum+1-j][k-u])*C[a[i]-1][k-1]));
            sum+=a[i];
        }
        printf("Case #%d: ",++cases);
        LL ans=dp[n][0];
        for(int i=1;i<=n;i++)   //对每一组，进行全排列 
            ans=(ans*A[a[i]]);
        cout<<ans<<endl;
    }
    return 0;
}
